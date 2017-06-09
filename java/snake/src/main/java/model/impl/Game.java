package model.impl;

import model.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.*;
import java.util.stream.Collectors;

import static java.util.Arrays.asList;
import static util.Constants.*;

public class Game implements IGame {

    private static final Logger logger = LogManager.getLogger(Game.class);
    private IState state;
    private List<String> colors = new ArrayList<>();
    private Random rand = new Random();
    private boolean hasFinished;
    private Long startingTime;

    public Game(IState state) {
        this.state = state;
        colors.addAll(asList(BLUE, DARKRED, DARKGREEN, DARKORANGE));
    }

    @Override
    public void addSnake(int id) {
        if(startingTime == null) startingTime = System.currentTimeMillis();
        ISnake snake = Factory.createSnake(id, colors.remove((int)(Math.random() * (colors.size()-1))), occupyRandomPoint());
        state.getSnakes().put(id, snake);
        logger.debug("Add snake for client {} at position ({},{})", id, snake.getHead().getX(), snake.getHead().getY());
        if(state.getFood() == null) placeFood();
    }

    @Override
    public void removeSnake(int id) {
        ISnake snake = state.getSnakes().get(id);
        if(snake.isPlaying()) {
            removeSnakeTail(snake, snake.getLength() - 1);
            snake.setIsPlaying(false);
            logger.debug("Remove snake for client {}", id);
        }
    }

    @Override
    public IState updateState(int id, Direction direction) {
        ISnake snake = state.getSnakes().get(id);
        if(snake == null || !snake.isPlaying() || hasFinished) {
            logger.debug("Snake with id {} not found or not playing anymore", id);
            return null;
        }
        snake.setDirection(calculateDirection(snake, direction));

        // new snake head
        IPoint head = snake.getHead();
        if(snake.getDirection() == Direction.RIGHT) snake.addHead(Factory.createPoint(head.getX() + 1, head.getY()));
        if(snake.getDirection() == Direction.LEFT) snake.addHead(Factory.createPoint(head.getX() - 1, head.getY()));
        if(snake.getDirection() == Direction.UP) snake.addHead(Factory.createPoint(head.getX(), head.getY() - 1));
        if(snake.getDirection() == Direction.DOWN) snake.addHead(Factory.createPoint(head.getX(), head.getY() + 1));
        head = snake.getHead();
        occupyPoint(head);

        if(!eatsFood(snake, head)) {
            // the snake didn't eat anything, normal movement
            removeSnakeTail(snake, 0);
        }
        eatsPoison(snake, head);
        eatsPowerUp(snake, head);
        bitesItselfOrOtherSnake(snake);
        collidesWithBorder(snake, head);
        checkTimeouts(snake);

        // place poison and power-up randomly
        if(rand.nextInt(100)<POISON_CHANCE && state.getPoisons().size()<POISON_MAX){
            placePoison();
        }
        if(rand.nextInt(100)<POWER_UP_CHANCE && state.getPowerUps().size()<POWER_UP_MAX){
            placePowerUp();
        }
        state.setTimeElapsed(System.currentTimeMillis() - startingTime);
        updateGameResult();
        logger.debug("Calculated next state");
        return state;
    }

    @Override
    public IState getState() {
        return state;
    }

    @Override
    public boolean hasFinished() {
        return hasFinished;
    }

    /**
     * Ensure the snake can't move in the opposite direction if it is longer than 1
     * @param snake the snake
     * @param direction the new direction
     * @return the old direction if the snake wants to move in the opposite direction, else the new direction
     */
    private Direction calculateDirection(ISnake snake, Direction direction) {
        if(snake.getLength()>1) {
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
            logger.debug("Snake ate food");
            // a snake has a maximum speed
            if(snake.getSpeed() + FOOD_SPEED > MAX_SPEED) {
                snake.setSpeed(MAX_SPEED);
            }
            else {
                snake.setSpeed(snake.getSpeed() + FOOD_SPEED);
            }
            snake.setHealth(snake.getHealth() + FOOD_HEALTH);
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
                logger.debug("Snake ate poison");
                // decrease health or speed randomly
                if(rand.nextInt(1) == 1 && snake.getSpeed() - POISON_SPEED >= MIN_SPEED) {
                    snake.setSpeed(snake.getSpeed() - POISON_SPEED);
                }
                else {
                    snake.setHealth(snake.getHealth() - POISON_HEALTH);
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
                logger.debug("Snake ate power-up");
                if(powerUp.getType()==PowerUpType.SPEED && snake.getSpeed() + POWER_UP_SPEED <= MAX_SPEED){
                    snake.getInfluences().add(Factory.createInfluence(POWER_UP_DURATION, POWER_UP_SPEED, 0, System.currentTimeMillis()));
                    snake.setSpeed(snake.getSpeed() + POWER_UP_SPEED);
                }
                else {
                    snake.getInfluences().add(Factory.createInfluence(POWER_UP_DURATION, 0, POWER_UP_HEALTH, System.currentTimeMillis()));
                    snake.setHealth(snake.getHealth() + POWER_UP_HEALTH);
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
        if(snake.getLength() > 3 && snake.getPoints().subList(0, snake.getLength() - 2).contains(snake.getHead())) {
            logger.debug("Snake bit itself");
            removeSnakeTail(snake, snake.getLength() - 1);
            snake.setHealth(0);
            return true;
        }

        // biting other snakes
        logger.debug("Checking if snake bites another one");
        for(ISnake bittenSnake : state.getSnakes().values()) {
            if(bittenSnake.getId() != snake.getId()) {
                int bitingIndex = bittenSnake.getPoints().indexOf(snake.getHead());
                if(bitingIndex != -1) {
                    logger.debug("Snake bit another one");
                    int speedGain = snake.getSpeed() + BITING_SPEED > MAX_SPEED? MAX_SPEED - snake.getSpeed() : BITING_SPEED;
                    snake.getInfluences().add(Factory.createInfluence(BITING_DURATION, speedGain, BITING_HEALTH, System.currentTimeMillis()));
                    snake.setSpeed(snake.getSpeed() + speedGain);
                    snake.setHealth(snake.getHealth() + BITING_HEALTH);
                    bittenSnake.setHealth(bittenSnake.getHealth() - Math.round((snake.getLength() / bittenSnake.getLength()) * BITING_HEALTH));
                    removeSnakeTail(bittenSnake, bitingIndex);
                    occupyPoint(snake.getHead());
                    return true;
                }
            }
        }
        return false;
    }

    private boolean collidesWithBorder(ISnake snake, IPoint head) {
        logger.debug("Checking if snake collides with the border");
        if(head.getX()<0 || head.getX()>=BOARD_WIDTH || head.getY()<0 || head.getY()>=BOARD_HEIGHT){
            logger.debug("Snake collided with the border");
            removeSnakeTail(snake, snake.getLength() - 1);
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
            if(System.currentTimeMillis() - poison.getSystemTime() >= MAX_ARTIFACT_TIME) {
                state.getPoisons().remove(poison);
                makePointAvailable(poison.decoratedPoint);
            }
        }
        // check for timeouts for power-ups
        logger.debug("Checking power-up timeouts");
        List<PowerUp> powerUps = new ArrayList<>(state.getPowerUps());
        for(PowerUp powerUp : powerUps) {
            if(System.currentTimeMillis() - powerUp.getSystemTime() >= MAX_ARTIFACT_TIME) {
                state.getPowerUps().remove(powerUp);
                makePointAvailable(powerUp.decoratedPoint);
            }
        }
        // check for timeouts for influences
        logger.debug("Checking influence timeouts");
        List<IInfluence> influences = new ArrayList<>(snake.getInfluences());
        for(IInfluence influence : influences) {
            if(System.currentTimeMillis() - influence.getStartTime() >= influence.getDuration()) {
                if(snake.getSpeed()- influence.getSpeed() < MIN_SPEED) {
                    snake.setSpeed(MIN_SPEED);
                }
                else {
                    snake.setSpeed(snake.getSpeed() - influence.getSpeed());
                }
                snake.setHealth(snake.getHealth() - influence.getHealth());
                snake.getInfluences().remove(influence);
            }
        }
    }

    private void placeFood() {
        Food food = Factory.createFood(occupyRandomPoint());
        logger.debug("Place food of type " + food.getType()+ " at position ({},{})", food.getX(), food.getY());
        state.setFood(food);
    }

    private void placePoison() {
        Poison poison = Factory.createPoison(occupyRandomPoint());
        logger.info("Place poison of type " + poison.getType()+ " at position ({},{})", poison.getX(), poison.getY());
        state.getPoisons().add(poison);
    }

    private void placePowerUp() {
        PowerUp powerUp = Factory.createPowerUp(occupyRandomPoint());
        logger.debug("Place power-up of type " + powerUp.getType() + " at position ({},{})", powerUp.getX(), powerUp.getY());
        state.getPowerUps().add(powerUp);
    }

    private void updateGameResult() {
        // snakes that lost while playing
        for(ISnake snake : state.getSnakes().values()) {
            if(snake.getHealth() <= 0 || snake.getLength() == 0) {
                snake.setIsPlaying(false);
                state.addResult(snake.getId(), LOST_MESSAGE);
            }
        }
        // if all players had already joined and only one remained playing
        List<ISnake> winners = state.getSnakes().values().stream().filter(ISnake::isPlaying).collect(Collectors.toList());
        if(state.getSnakes().size() == MAX_PLAYERS && winners.size() == 1) {
            winners.get(0).setIsPlaying(false);
            state.addResult(winners.get(0).getId(), WON_MESSAGE);
            hasFinished = true;
        }
        // time is up, so elect a winner!
        if(state.getTimeElapsed() >= GAME_DURATION) {
            state.setTimeElapsed(GAME_DURATION);
            hasFinished = true;
            int maxLength = state.getSnakes().values().stream().filter(ISnake::isPlaying).map(ISnake::getLength).max(Integer::compareTo).get();
            winners = state.getSnakes().values().stream().filter(s -> s.getLength() == maxLength).collect(Collectors.toList());
            if(winners.size() == 1) {
                ISnake winner = winners.get(0);
                for(ISnake snake : state.getSnakes().values()) {
                    snake.setIsPlaying(false);
                    if(winner == snake) {
                        state.addResult(winner.getId(), WON_MESSAGE);
                    }
                    else {
                        state.addResult(snake.getId(), winner.getColor() + " snake wins");
                    }
                }
            }
            else {
                // many winners
                for(ISnake snake : state.getSnakes().values()) {
                    if(snake.isPlaying() && snake.getLength() == maxLength) {
                        state.addResult(snake.getId(), DRAW_MESSAGE);
                    }
                    else if(snake.isPlaying()) {
                        state.addResult(snake.getId(), LOST_MESSAGE);
                    }
                    snake.setIsPlaying(false);
                }
            }
        }
    }

    private void removeSnakeTail(ISnake snake, int index) {
        for(int i = 0; i <= index; i++) {
            IPoint tail = snake.getTail();
            snake.getPoints().remove(tail);
            makePointAvailable(tail);
        }
    }

    private void occupyPoint(IPoint point) {
        state.getAvailablePoints().remove(point);
    }

    private IPoint occupyRandomPoint() {
        return state.getAvailablePoints().remove((int)(Math.random() * (state.getAvailablePoints().size() - 1)));
    }

    private void makePointAvailable(IPoint p) {
        List<IPoint> availablePoints = state.getAvailablePoints();
        // no duplicates and no invalid points
        if(!availablePoints.contains(p)&&!(p.getX()<0||p.getX()>=BOARD_WIDTH||p.getY()<0||p.getY()>=BOARD_HEIGHT)) {
            availablePoints.add(p);
        }
    }

}