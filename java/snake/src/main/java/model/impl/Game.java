package model.impl;

import model.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.ArrayList;
import java.util.List;

import static java.util.Arrays.asList;

public class Game implements IGame {

    private static final Logger logger = LogManager.getLogger(Game.class);
    private IState state;
    private List<String> colors = new ArrayList<String>();

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

    @Override
    public IState updateState(int id, Direction direction) {

        ISnake snake = state.getSnakes().get(id);
        List<IPoint> points = snake.getPoints();

        IPoint p = points.get(points.size()-1);
        if(direction == Direction.RIGHT) {
            points.add(new Point(p.getX()+1, p.getY()));
        }
        if(direction == Direction.LEFT) {
            points.add(new Point(p.getX()-1, p.getY()));
        }
        if(direction == Direction.UP) {
            points.add(new Point(p.getX(), p.getY()-1));
        }
        if(direction == Direction.DOWN) {
            points.add(new Point(p.getX(), p.getY()+1));
        }

        IPoint head = points.get(points.size()-1);
        ArrayList<IPoint> toRemove = new ArrayList<IPoint>();

        if(head.equals(state.getFood())) {
            //eat food
            if(snake.getSpeed() < 1000) {
                snake.setSpeed(snake.getSpeed() + 20);
                snake.setHealth(snake.getHealth() + 10);
            }
            placeFood();
            state.getAvailablePoints().remove(head);
        }
        else {
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
        IPoint food = state.occupyRandomPoint();
        logger.debug("Placing food at position ({},{})", food.getX(), food.getY());
        state.setFood(food);
    }

}
