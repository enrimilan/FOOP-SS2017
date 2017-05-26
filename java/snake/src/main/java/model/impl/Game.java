package model.impl;

import model.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import util.*;

import java.util.*;

import static java.util.Arrays.asList;
import static java.util.Arrays.binarySearch;

public class Game implements IGame {

    private static final Logger logger = LogManager.getLogger(Game.class);
    private IState state;
    private List<String> colors = new ArrayList<String>();
    private Random rand = new Random();
    private ArrayList<IPoint> toRemove = new ArrayList<IPoint>();


    public Game(IState state) {
        this.state = state;
        colors.addAll(asList("blue", "darkred", "darkgreen", "darkorange"));
    }

    @Override
    public void addSnake(int id) {
        ISnake snake = new Snake(id);

        String color =  colors.remove((int)(Math.random() * (colors.size()-1)));
        snake.setColor(color);

        IPoint point = state.occupyRandomPoint();

        List<IPoint> points = new ArrayList<IPoint>();
        points.add(point);
        snake.setPoints(points);
        state.getSnakes().put(id, snake);

        logger.debug("Add snake for client {} at position ({},{})", id, point.getX(), point.getY());

        // nothing to remove
        state.setToRemove(new ArrayList<IPoint>());

        if(state.getFood() == null) {
            placeFood();
        }
    }

    @Override
    public void removeSnake(int id) {
        ISnake snake = state.getSnakes().remove(id);
        colors.add(snake.getColor());
        state.setToRemove(snake.getPoints());
        state.getAvailablePoints().addAll(snake.getPoints());
    }

    /**
     * cuts away bitten snakes tail
     *
     * @param bittenSnake
     * @param x x coord of cut
     * @param y y coord of cut
     */
    void cutSnakesTail(ISnake bittenSnake, int x, int y){

        logger.info("biting snake "+bittenSnake.getColor()+" or border at "+x+"/"+y);

        ArrayList<IPoint> bittenPointsTemper = (ArrayList<IPoint>) bittenSnake.getPoints();
        List<IPoint> pointsToCut = new ArrayList<>();

        for(IPoint point : bittenPointsTemper){
            if(!(point.getY()==y&&point.getX()==x)){
                logger.info("removing point "+point.getX()+" "+point.getY()+" from snake "+bittenSnake.getColor());
                pointsToCut.add(point);
                toRemove.add(point);
                state.setToRemove(toRemove);
                state.getAvailablePoints().add(point);
            }else{
                logger.info("removing point "+point.getX()+" "+point.getY()+" from snake "+bittenSnake.getColor());
                pointsToCut.add(point);
                toRemove.add(point);
                state.setToRemove(toRemove);
                state.getAvailablePoints().add(point);
                break;
            }
        }

        bittenPointsTemper.removeAll(pointsToCut);
        if(bittenPointsTemper.size()<=0){
            //state.getSnakes().remove(bittenSnake.getId());
            removeSnake(bittenSnake.getId());
            logger.info("snake got bitten in head or crashed into border? remove.");
        }
        bittenSnake.setPoints(bittenPointsTemper);

        logger.info("size now: "+bittenPointsTemper.size());

    }


    /**
     * handles collision detection with itself or other snakes or borders.
     *
     *
     * Snakes touching each other increase their health level and speed for a while.
     * But, the health level of a snake bitten by another snake (or itself) dramatically decreases,
     * depending on the sizes of the biting and bitten snakes.
     *
     *
     * @param snake biting snake
     * @param x x coordinate of next cell of snake
     * @param y y coordinate of next cell of snake
     * @return
     */
    boolean checkForSnakeCollision(ISnake snake, int x, int y){


        /**
         * check if snake collided with border
         */

            if(x<0||x>=Constants.BOARD_WIDTH||y<0||y>=Constants.BOARD_HEIGHT){
                cutSnakesTail(snake,snake.getPoints().get(snake.getPoints().size()-1).getX(),snake.getPoints().get(snake.getPoints().size()-1).getY());
                return false;
            }

        /**
         * check for other snakes
         */

        for(Map.Entry<Integer, ISnake> entry : state.getSnakes().entrySet()){
            for(IPoint point : entry.getValue().getPoints()){
                if(point.getX()==x&&point.getY()==y){
                    //collision
                    /**
                     * SNAKE + speed and health, ISnake - speed and health
                     */
                    logger.info("snake "+snake.getColor()+" just bit "+entry.getValue().getColor());
                    //alter biting snake:
                    snake.setActiveGoodBiting(System.currentTimeMillis() + Constants.BITINGTIME);
                    snake.setHasBittenCount(snake.getHasBittenCount() + 1);
                    snake.setHealth(snake.getHealth()+Constants.BITINGHEALTH+(entry.getValue().getHealth()/Constants.BITINGFACTOR));
                    logger.info("biting snake health increased by: "+snake.getHealth()+Constants.BITINGHEALTH+(entry.getValue().getHealth()/Constants.BITINGFACTOR));
                    int speed = snake.getSpeed()+Constants.BITINGSPEED+(entry.getValue().getSpeed()/Constants.BITINGFACTOR);
                    if(speed<500) snake.setSpeed(speed);

                    //alter bitten snake:
                    entry.getValue().setActiveBadBiting(System.currentTimeMillis() + Constants.BITINGTIME);
                    entry.getValue().setSnakeWasBittenByOtherSnake(entry.getValue().getSnakeWasBittenByOtherSnake() + 1);
                    entry.getValue().setHealth(entry.getValue().getHealth() - (Constants.BITINGHEALTH+(snake.getHealth()/Constants.BITINGFACTOR)));
                    logger.info("bitten snake health decreased by: " + (entry.getValue().getHealth() - (Constants.BITINGHEALTH+(snake.getHealth()/Constants.BITINGFACTOR))));
                    entry.getValue().setSpeed(entry.getValue().getSpeed() - Constants.BITINGSPEED+(snake.getSpeed()/Constants.BITINGFACTOR));
                    cutSnakesTail(entry.getValue(), x, y);

                    return true;
                }
            }
        }

        return true;

    }


    @Override
    public IState updateState(int id, Direction direction) {

        logger.info("direction: "+direction);
        ISnake snake = state.getSnakes().get(id);
        List<IPoint> points = snake.getPoints();

        /**
         * check if snake dead
         */

        if(snake.getHealth()<=0){
            cutSnakesTail(snake,snake.getPoints().get(snake.getPoints().size()-1).getX(),snake.getPoints().get(snake.getPoints().size()-1).getY());
        }

        /**
         *ensure snake cant go through itself if its longer than 1
         */

        if(snake.getPoints().size()>1) {
            if (snake.getDirection() == Direction.RIGHT && direction == Direction.LEFT) direction = Direction.RIGHT;
            if (snake.getDirection() == Direction.LEFT && direction == Direction.RIGHT) direction = Direction.LEFT;
            if (snake.getDirection() == Direction.UP && direction == Direction.DOWN) direction = Direction.UP;
            if (snake.getDirection() == Direction.DOWN && direction == Direction.UP) direction = Direction.DOWN;
        }

        /**
         * directions
         */

        IPoint p = points.get(points.size()-1);
        if(direction == Direction.RIGHT) {
            if(checkForSnakeCollision(snake, p.getX()+1, p.getY())) {
                points.add(new Point(p.getX() + 1, p.getY()));
                snake.setDirection(Direction.RIGHT);
            }

        }
        if(direction == Direction.LEFT) {
            if(checkForSnakeCollision(snake, p.getX()-1, p.getY())) {
                points.add(new Point(p.getX() - 1, p.getY()));
                snake.setDirection(Direction.LEFT);
            }

        }
        if(direction == Direction.UP) {
           if(checkForSnakeCollision(snake, p.getX(), p.getY()-1)){
                points.add(new Point(p.getX(), p.getY() - 1));
                snake.setDirection(Direction.UP);
           }


        }
        if(direction == Direction.DOWN) {
            if(checkForSnakeCollision(snake, p.getX(), p.getY()+1)) {
                points.add(new Point(p.getX(), p.getY() + 1));
                snake.setDirection(Direction.DOWN);
            }
        }

        IPoint head = points.get(points.size()-1);



        /**
         * check biting timing (so effects of bitings can wear off)
         */

        if(snake.getHasBittenCount()>0){
            if(System.currentTimeMillis()>snake.getActiveGoodBiting()){
                snake.setHealth(snake.getHealth()-Constants.BITINGHEALTH);
                snake.setSpeed(snake.getSpeed()-Constants.BITINGSPEED);
                snake.setHasBittenCount(snake.getHasBittenCount()-1);
            }
        }

        if(snake.getSnakeWasBittenByOtherSnake()>0){
            if(System.currentTimeMillis()>snake.getActiveBadBiting()){
                snake.setHealth(snake.getHealth()+Constants.BITINGHEALTH);
                snake.setSpeed(snake.getSpeed()+Constants.BITINGSPEED);
                snake.setSnakeWasBittenByOtherSnake(snake.getSnakeWasBittenByOtherSnake()-1);
            }
        }



        /**
         * check powerup timing (so effects of powerups can wear off)
         */

        if(snake.getPowerUpInfluenceCount()>0){
          for(PowerUpType powerUpType : snake.getActivePowerUps().keySet()){
              if(System.currentTimeMillis()>snake.getActivePowerUps().get(powerUpType)){
                  switch (powerUpType){
                      case SPEED:
                            snake.setSpeed(snake.getSpeed()-100);
                            snake.setPowerUpInfluenceCount(snake.getPowerUpInfluenceCount()-1);
                            snake.removePowerUp(powerUpType);
                            break;
                      case HEALTH:
                            snake.setHealth(snake.getHealth()-200);
                            snake.setPowerUpInfluenceCount(snake.getPowerUpInfluenceCount()-1);
                            snake.removePowerUp(powerUpType);
                            break;
                        //dismissed
                      case LENGTH:
                            snake.removePowerUp(powerUpType);
                            break;
                      case INVINCIBILITY:
                        //dismissed
                  }
              }
          }
        }



        //place poison arbitrarily
        if(rand.nextInt(100)<Constants.POISONCHANCE&&state.getPoisons().size()<=Constants.POISONMAX){
            placePoison();

        }

        //remove poison arbitrarily
        if(state.getPoisons().size()>0&&rand.nextInt(100)<Constants.POISONCHANCE){
            int j = rand.nextInt(state.getPoisons().size());
            //ensure artefact stays at least 10 seconds
            if(state.getPoisons().get(j).getSystemTime()+Constants.MINARTEFACTTIME<=System.currentTimeMillis()) {
                toRemove.add(state.getPoisons().get(j));
                state.getPoisons().remove(j);
            }

        }

        //place powerup arbitrarily
        if(rand.nextInt(100)<Constants.POWERUPCHANCE&&state.getPowerups().size()<=Constants.POWERUPMAX){
            placePowerUp();

        }

        //remove powerup arbitrarily
        if(state.getPowerups().size()>0&&rand.nextInt(100)<Constants.POWERUPCHANCE){
            int j = rand.nextInt(state.getPowerups().size());
            //ensure artefact stays at least 10 seconds
            logger.info("Checking to remove powerup. Poweruptime: "+(state.getPowerups().get(j).getSystemTime()+Constants.MINARTEFACTTIME)+" curr time: "+System.currentTimeMillis());
            if(state.getPowerups().get(j).getSystemTime()+Constants.MINARTEFACTTIME<=System.currentTimeMillis()) {
                logger.info("CHECK "+(state.getPowerups().get(j).getSystemTime()+Constants.MINARTEFACTTIME)+" <= "+System.currentTimeMillis());
                toRemove.add(state.getPowerups().get(j));
                state.getPowerups().remove(j);
            }

        }


        //eat poison
        if(!state.getPoisons().isEmpty()){
            for(Poison po : state.getPoisons()) {
                if (head.equals(po.decoratedPoint)) {

                    if(rand.nextInt(2)>=1) {
                        snake.setHealth(snake.getHealth() - 50);
                    }else{
                        if(snake.getSpeed()>50)snake.setSpeed(snake.getSpeed() - 50);
                    }

                    state.getAvailablePoints().remove(head);
                    state.getPoisons().remove(po);
                    break;
                }
            }
        }



        

        /**
         * handles powerup consumption (eat powerup/toxin)
         */
        if(!state.getPowerups().isEmpty()){
            for(PowerUp po : state.getPowerups()) {
                if (head.equals(po.decoratedPoint)) {

                    if(po.getType()==PowerUpType.SPEED){
                        if(snake.getSpeed()<500){
                            snake.setSpeed(snake.getSpeed() + Constants.POWERUPSPEED);
                            snake.setPowerUpInfluenceCount(snake.getPowerUpInfluenceCount() + 1);
                        }
                        if(snake.getActivePowerUps().containsKey(PowerUpType.SPEED)){
                            snake.setActivePowerUps(PowerUpType.SPEED, snake.getActivePowerUps().get(PowerUpType.SPEED)+Constants.POWERUPDURATION);
                        }else{
                            snake.setActivePowerUps(PowerUpType.SPEED, System.currentTimeMillis() + Constants.POWERUPDURATION);
                        }
                    }

                    if(po.getType()==PowerUpType.HEALTH){
                        snake.setHealth(snake.getHealth() + Constants.POWERUPHEALTH);
                        snake.setPowerUpInfluenceCount(snake.getPowerUpInfluenceCount() + 1);

                        if(snake.getActivePowerUps().containsKey(PowerUpType.HEALTH)){
                            snake.setActivePowerUps(PowerUpType.HEALTH, snake.getActivePowerUps().get(PowerUpType.HEALTH)+Constants.POWERUPDURATION);
                        }else{
                            snake.setActivePowerUps(PowerUpType.HEALTH, System.currentTimeMillis()+Constants.POWERUPDURATION);
                        }
                    }

                    if(po.getType()==PowerUpType.INVINCIBILITY){
                        //dismissed
                    }

                    //dismissed
                    if(po.getType()==PowerUpType.LENGTH){
                        snake.setActivePowerUps(PowerUpType.LENGTH,System.currentTimeMillis()+Constants.POWERUPDURATION-8000);
                        snake.setPowerUpInfluenceCount(snake.getPowerUpInfluenceCount() + 1);
                    }
                    state.getAvailablePoints().remove(head);
                    state.getPowerups().remove(po);
                    break;
                }
            }
        }


        //eat food
        if(head.equals(state.getFood().decoratedPoint)) {
            if(snake.getSpeed() < 400) {
                snake.setSpeed(snake.getSpeed() + Constants.FOODHEALTH);
            }
            snake.setHealth(snake.getHealth() + Constants.FOODSPEED);
            placeFood();
            state.getAvailablePoints().remove(head);
        }
        else if(!snake.getActivePowerUps().keySet().contains(PowerUpType.LENGTH)) {
            IPoint tail = points.get(0);
            points.remove(tail);
            toRemove.add(tail);
            state.getAvailablePoints().add(tail);
        }
        state.setToRemove(toRemove);

        return state;
    }

    @Override
    public IState getState() {
        return state;
    }

    private void placeFood() {
        Food food = new Food(state.occupyRandomPoint());
        logger.info("Placing food of Art " + food.getArt()+ " at position ({},{})", food.getX(), food.getY());
        state.setFood(food);
    }

    private void placePoison() {
        Poison poison = new Poison(state.occupyRandomPoint());
        logger.info("Placing poison of Art " + poison.getArt()+ " at position ({},{})", poison.getX(), poison.getY());
        state.setPoison(poison);
    }

    private void placePowerUp() {
        PowerUp powerup = new PowerUp(state.occupyRandomPoint());
        logger.debug("Placing powerup of Art " + powerup.getArt() + " at position ({},{})", powerup.getX(), powerup.getY());
        state.setPowerUp(powerup);
    }

   

}
