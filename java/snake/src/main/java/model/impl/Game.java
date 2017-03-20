package model.impl;

import model.*;

import java.util.ArrayList;
import java.util.List;

public class Game implements IGame {

    private IState state;

    public Game(IState state) {
        this.state = state;
    }

    @Override
    public void addSnake(int id) {
        //TODO find a free spot for the new snake
        ISnake snake = new Snake(id);
        List<IPoint> points = new ArrayList<IPoint>();
        points.add(new Point(0,5));
        points.add(new Point(1,5));
        points.add(new Point(2,5));
        points.add(new Point(3,5));
        snake.setPoints(points);
        state.getSnakes().put(id, snake);

        // nothing to remove
        state.setToRemove(new ArrayList<IPoint>());
    }

    @Override
    public void removeSnake(int id) {
        ISnake snake = state.getSnakes().remove(id);
        state.setToRemove(snake.getPoints());
    }

    @Override
    public IState updateState(int id, Direction direction) {
        ISnake snake = state.getSnakes().get(id);

        List<IPoint> points = snake.getPoints();
        List<IPoint> newPoints = new ArrayList<IPoint>();

        ArrayList<IPoint> toRemove = new ArrayList<IPoint>();
        toRemove.add(points.get(0));
        state.setToRemove(toRemove);

        for(int i = 0; i< points.size()-1; i++) {
            newPoints.add(points.get(i+1));
        }
        IPoint p = points.get(points.size()-1);

        if(direction == Direction.RIGHT) {
            newPoints.add(new Point(p.getX()+1, p.getY()));
        }
        if(direction == Direction.LEFT) {
            newPoints.add(new Point(p.getX()-1, p.getY()));
        }
        if(direction == Direction.UP) {
            newPoints.add(new Point(p.getX(), p.getY()-1));
        }
        if(direction == Direction.DOWN) {
            newPoints.add(new Point(p.getX(), p.getY()+1));
        }

        snake.setPoints(newPoints);
        return state;
    }

    @Override
    public IState getState() {
        return state;
    }

}
