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
    private List<String> colors = new ArrayList<>();
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

        if(state.getFood() == null) {
            placeFood();
        }
    }

    @Override
    public void removeSnake(int id) {
        ISnake snake = state.getSnakes().remove(id);
        colors.add(snake.getColor());
        state.getAvailablePoints().addAll(snake.getPoints());
    }

    @Override
    public IState updateState(int id, Direction direction) {
        logger.debug("received direction {} from snake {}", direction, id);
        ISnake snake = state.getSnakes().get(id);
        List<IPoint> points = snake.getPoints();

        snake.setDirection(calculateDirection(snake, direction));

        // new snake head
        IPoint head = snake.getHead();
        if(snake.getDirection() == Direction.RIGHT) points.add(new Point(head.getX() + 1, head.getY()));
        if(snake.getDirection() == Direction.LEFT) points.add(new Point(head.getX() - 1, head.getY()));
        if(snake.getDirection() == Direction.UP) points.add(new Point(head.getX(), head.getY() - 1));
        if(snake.getDirection() == Direction.DOWN) points.add(new Point(head.getX(), head.getY() + 1));
        head = snake.getHead();
        state.occupyPoint(head);

        if(!eatsFood(snake, head)) {
            // the snake didn't eat anything, normal movement
            removeSnakeTail(snake, 0, 0);
        }
        eatsPoison(snake, head);
        eatsPowerUp(snake, head);
        bitesItselfOrOtherSnake(snake);
        collidesWithBorder(snake, head);
        checkTimeouts(snake);

        // place poison randomly
        if(rand.nextInt(100)<Constants.POISON_CHANCE && state.getPoisons().size()<Constants.POISON_MAX){
            placePoison();
        }
        // place power-up randomly
        if(rand.nextInt(100)<Constants.POWER_UP_CHANCE && state.getPowerUps().size()<Constants.POWER_UP_MAX){
            placePowerUp();
        }

        logger.debug("Calculated next state");
        return state;
    }

    @Override
    public IState getState() {
        return state;
    }

    /**
     * Ensure the snake can't move in the opposite direction if it is longer than 1
     * @param snake the snake
     * @param direction the new direction
     * @return the old direction if the snake wants to move in the opposite direction, else the new direction
     */
    private Direction calculateDirection(ISnake snake, Direction direction) {
        if(snake.getPoints().size()>1) {
            if (snake.getDirection() == Direction.RIGHT && direction == Direction.LEFT) return Direction.RIGHT;
            if (snake.getDirection() == Direction.LEFT && direction == Direction.RIGHT) return Direction.LEFT;
            if (snake.getDirection() == Direction.UP && direction == Direction.DOWN) return Direction.UP;
            if (snake.getDirection() == Direction.DOWN && direction == Direction.UP) return Direction.DOWN;
        }
        return direction;
    }

    private boolean eatsFood(ISnake snake, IPoint head) {
        logger.debug("Checking if snake eats food");
        if(head.equals(state.getFood().decoratedPoint)) {
            // a snake has a maximum speed
            if(snake.getSpeed() + Constants.FOOD_SPEED > Constants.MAX_SPEED) {
                snake.setSpeed(Constants.MAX_SPEED);
            }
            else {
                snake.setSpeed(snake.getSpeed() + Constants.FOOD_SPEED);
            }
            snake.setHealth(snake.getHealth() + Constants.FOOD_HEALTH);
            placeFood();
            return true;
        }
        return false;
    }

    private boolean eatsPoison(ISnake snake, IPoint head) {
        logger.debug("Checking if snake eats poison");
        List<Poison> poisons = new ArrayList<>(state.getPoisons());
        for(Poison poison : poisons) {
            if (head.equals(poison.decoratedPoint)) {
                // decrease health or speed randomly
                if(rand.nextInt(1) == 1 && snake.getSpeed() - Constants.POISON_SPEED >= Constants.MIN_SPEED) {
                    snake.setSpeed(snake.getSpeed() - Constants.POISON_SPEED);
                }
                else {
                    snake.setHealth(snake.getHealth() - Constants.POISON_HEALTH);
                }
                state.getPoisons().remove(poison);
                return true;
            }
        }
        return false;
    }

    private boolean eatsPowerUp(ISnake snake, IPoint head) {
        logger.debug("Checking if snake eats a power-up");
        List<PowerUp> powerUps = new ArrayList<>(state.getPowerUps());
        for(PowerUp powerUp : powerUps) {
            if (head.equals(powerUp.decoratedPoint)) {
                if(powerUp.getType()==PowerUpType.SPEED && snake.getSpeed() + Constants.POWER_UP_SPEED <= Constants.MAX_SPEED){
                    snake.getInfluences().add(new Influence(Constants.POWER_UP_DURATION, Constants.POWER_UP_SPEED, 0, System.currentTimeMillis()));
                    snake.setSpeed(snake.getSpeed() + Constants.POWER_UP_SPEED);
                }
                else {
                    snake.getInfluences().add(new Influence(Constants.POWER_UP_DURATION, 0, Constants.POWER_UP_HEALTH, System.currentTimeMillis()));
                    snake.setHealth(snake.getHealth() + Constants.POWER_UP_HEALTH);
                }
                state.getPowerUps().remove(powerUp);
                return true;
            }
        }
        return false;
    }

    private boolean bitesItselfOrOtherSnake(ISnake snake) {

        // biting itself
        logger.debug("Checking if snake bites itself");
        if(snake.getPoints().size() > 3 && snake.getPoints().subList(0, snake.getPoints().size() - 2).contains(snake.getHead())) {
            removeSnakeTail(snake, 0, snake.getPoints().size() - 1);
            snake.setHealth(0);
            logger.debug("Snake bit itself");
            return true;
        }


        // biting other snakes
        logger.debug("Checking if snake bites another one");
        for(ISnake s : state.getSnakes().values()) {
            if(s.getId() != snake.getId()) {
                int bitingIndex = s.getPoints().indexOf(snake.getHead());
                if(bitingIndex != -1) {
                    removeSnakeTail(s, 0, bitingIndex);
                    s.setHealth(s.getHealth() - 150);
                    return true;
                }
            }
        }
        return false;
    }

    private boolean collidesWithBorder(ISnake snake, IPoint head) {
        logger.debug("Checking if snake collides with the border");
        if(head.getX()<0 || head.getX()>=Constants.BOARD_WIDTH || head.getY()<0 || head.getY()>=Constants.BOARD_HEIGHT){
            removeSnakeTail(snake, 0, snake.getPoints().size() - 1);
            snake.setHealth(0);
            return true;
        }
        return false;
    }

    private void checkTimeouts(ISnake snake) {
        // check for timeouts for poisons
        logger.debug("Checking poison timeouts");
        List<Poison> poisons = new ArrayList<>(state.getPoisons());
        for(Poison poison : poisons) {
            if(System.currentTimeMillis() - poison.getSystemTime() >= Constants.MAX_ARTIFACT_TIME) {
                state.getPoisons().remove(poison);
                state.getAvailablePoints().add(poison.decoratedPoint);
            }
        }
        // check for timeouts for power-ups
        logger.debug("Checking power-up timeouts");
        List<PowerUp> powerUps = new ArrayList<>(state.getPowerUps());
        for(PowerUp powerUp : powerUps) {
            if(System.currentTimeMillis() - powerUp.getSystemTime() >= Constants.MAX_ARTIFACT_TIME) {
                state.getPowerUps().remove(powerUp);
                state.getAvailablePoints().add(powerUp.decoratedPoint);
            }
        }
        // check for timeouts for influences
        logger.debug("Checking influence timeouts");
        List<IInfluence> influences = new ArrayList<>(snake.getInfluences());
        for(IInfluence influence : influences) {
            if(System.currentTimeMillis() - influence.getStartTime() >= influence.getDuration()) {
                if(snake.getSpeed()- influence.getSpeed() < Constants.MIN_SPEED) {
                    snake.setSpeed(Constants.MIN_SPEED);
                }
                else {
                    snake.setSpeed(snake.getSpeed() - influence.getSpeed());
                }
                snake.setHealth(snake.getHealth() - influence.getHealth());
                snake.getInfluences().remove(influence);
            }
        }
    }

    private void removeSnakeTail(ISnake snake, int from, int to) {
        for(int i = from; i <= to; i++) {
            IPoint tail = snake.getTail();
            snake.getPoints().remove(tail);
            state.getAvailablePoints().add(tail);
        }
    }

    private void placeFood() {
        Food food = new Food(state.occupyRandomPoint());
        logger.debug("Placing food of Art " + food.getArt()+ " at position ({},{})", food.getX(), food.getY());
        state.setFood(food);
    }

    private void placePoison() {
        Poison poison = new Poison(state.occupyRandomPoint());
        logger.info("Placing poison of Art " + poison.getArt()+ " at position ({},{})", poison.getX(), poison.getY());
        state.getPoisons().add(poison);
    }

    private void placePowerUp() {
        PowerUp powerUp = new PowerUp(state.occupyRandomPoint());
        logger.debug("Placing powerup of Art " + powerUp.getArt() + " at position ({},{})", powerUp.getX(), powerUp.getY());
        state.getPowerUps().add(powerUp);
    }

}
