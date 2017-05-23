package model.impl;

import model.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import util.*;

import java.util.*;

import static java.util.Arrays.asList;

public class Game implements IGame {

    private static final Logger logger = LogManager.getLogger(Game.class);
    private IState state;
    private List<String> colors = new ArrayList<String>();
    private Random rand = new Random();



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
     * handles collision detection with itself or other snakes.
     *
     *
     * Snakes touching each other increase their health level and speed for a while.
     * But, the health level of a snake bitten by another snake (or itself) dramatically decreases,
     * depending on the sizes of the biting and bitten snakes.
     *
     *
     */

    boolean checkForSnakeCollision(ISnake snake, int x, int y){

        for(Map.Entry<Integer, ISnake> entry : state.getSnakes().entrySet()){
            for(IPoint point : entry.getValue().getPoints()){
                if(point.getX()==x&&point.getY()==y){
                    //collision
                    /**
                     * SNAKE + speed and health, ISnake - speed and health
                     */
                    logger.info("snake "+snake.getColor()+" just bit "+entry.getValue().getColor());
                    //alter biting snake:
                    snake.setActiveGoodBiting(System.currentTimeMillis() + Constants.BITINGTIME);//TODO if already has biting
                    snake.setHasBittenCount(snake.getHasBittenCount() + 1);
                    snake.setHealth(snake.getHealth()+Constants.BITINGHEALTH);
                    snake.setSpeed(snake.getSpeed() +Constants.BITINGSPEED);

                    //alter bitten snake:
                    entry.getValue().setActiveBadBiting(System.currentTimeMillis() + Constants.BITINGTIME);
                    entry.getValue().setSnakeWasBittenByOtherSnake(snake.getSnakeWasBittenByOtherSnake() + 1);
                    entry.getValue().setHealth(snake.getHealth() - Constants.BITINGHEALTH);
                    entry.getValue().setSpeed(snake.getSpeed() - Constants.BITINGSPEED);

                    return true;

                }
            }

        }

        return false;

    }


    @Override
    public IState updateState(int id, Direction direction) {

        logger.info("direction: "+direction);
        ISnake snake = state.getSnakes().get(id);
        List<IPoint> points = snake.getPoints();


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
            if(!checkForSnakeCollision(snake, p.getX()+1, p.getY())){
                points.add(new Point(p.getX() + 1, p.getY()));
                snake.setDirection(Direction.RIGHT);
            }
        }
        if(direction == Direction.LEFT) {
            if(!checkForSnakeCollision(snake, p.getX()-1, p.getY())) {
                points.add(new Point(p.getX() - 1, p.getY()));
                snake.setDirection(Direction.LEFT);
            }
        }
        if(direction == Direction.UP) {
            if(!checkForSnakeCollision(snake, p.getX(), p.getY()-1)) {
                points.add(new Point(p.getX(), p.getY() - 1));
                snake.setDirection(Direction.UP);
            }else{
                points.add(new Point(p.getX() + 1, p.getY()));
                snake.setDirection(Direction.RIGHT);
            }
        }
        if(direction == Direction.DOWN) {
            if(!checkForSnakeCollision(snake, p.getX()+1, p.getY()+1)){
                points.add(new Point(p.getX(), p.getY()+1));
                snake.setDirection(Direction.DOWN);
            }
        }

        IPoint head = points.get(points.size()-1);
        ArrayList<IPoint> toRemove = new ArrayList<IPoint>();


        /**
         * check if snake collided with border
         */

        for(IPoint po : points){
            if(po.getX()<0||po.getX()>=Constants.BOARD_WIDTH||
               po.getY()<0||po.getY()>=Constants.BOARD_HEIGHT){
                removeSnake(id);
                return state;
            }
        }



        /**
         * check powerup timing
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
                      case LENGTH:
                            snake.removePowerUp(powerUpType);
                            break;
                      case INVINCIBILITY:
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
            toRemove.add(state.getPoisons().get(j));
            state.getPoisons().remove(j);

        }

        //place powerup arbitrarily
        if(rand.nextInt(100)<Constants.POWERUPCHANCE&&state.getPowerups().size()<=Constants.POWERUPMAX){
            placePowerUp();

        }

        //remove powerup arbitrarily
        if(state.getPowerups().size()>0&&rand.nextInt(100)<Constants.POWERUPCHANCE/2){
            int j = rand.nextInt(state.getPowerups().size());
            toRemove.add(state.getPowerups().get(j));
            state.getPowerups().remove(j);

        }


        //eat poison
        if(!state.getPoisons().isEmpty()){
            for(Poison po : state.getPoisons()) {
                if (head.equals(po.decoratedPoint)) {
                    snake.setHealth(snake.getHealth() - 50);
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
                        snake.setSpeed(snake.getSpeed()+100);
                        snake.setPowerUpInfluenceCount(snake.getPowerUpInfluenceCount() + 1);

                        if(snake.getActivePowerUps().containsKey(PowerUpType.SPEED)){
                            snake.setActivePowerUps(PowerUpType.SPEED, snake.getActivePowerUps().get(PowerUpType.SPEED)+Constants.POWERUPDURATION);
                        }else{
                            snake.setActivePowerUps(PowerUpType.SPEED, System.currentTimeMillis()+Constants.POWERUPDURATION);
                        }
                    }

                    if(po.getType()==PowerUpType.HEALTH){
                        snake.setHealth(snake.getHealth() + 200);
                        snake.setPowerUpInfluenceCount(snake.getPowerUpInfluenceCount() + 1);

                        if(snake.getActivePowerUps().containsKey(PowerUpType.HEALTH)){
                            snake.setActivePowerUps(PowerUpType.HEALTH, snake.getActivePowerUps().get(PowerUpType.HEALTH)+Constants.POWERUPDURATION);
                        }else{
                            snake.setActivePowerUps(PowerUpType.HEALTH, System.currentTimeMillis()+Constants.POWERUPDURATION);
                        }
                    }

                    if(po.getType()==PowerUpType.INVINCIBILITY){

                    }

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
        if(head.equals(state.getFood().decoratedPoint)) {//TODO ugh, decoratedpoint, this seems unneat
            if(snake.getSpeed() < 300) {
                snake.setSpeed(snake.getSpeed() + 40);
            }
            snake.setHealth(snake.getHealth() + 30);
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
