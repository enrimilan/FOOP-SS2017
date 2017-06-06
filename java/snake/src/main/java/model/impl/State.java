package model.impl;

import model.IPoint;
import model.ISnake;
import model.IState;
import util.Constants;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class State implements IState, Serializable {

    private HashMap<Integer, ISnake> snakes = new HashMap<>();
    private List<IPoint> availablePoints = new ArrayList<>();
    private Food food;
    private List<Poison> poisons;
    private List<PowerUp> powerUps;

    public State() {
        for(int x = 0; x < Constants.BOARD_WIDTH; x++) {
            for(int y = 0; y < Constants.BOARD_HEIGHT; y++) {
                availablePoints.add(new Point(x, y));
            }
        }
        poisons = new ArrayList<>();
        powerUps = new ArrayList<>();
    }

    @Override
    public HashMap<Integer, ISnake> getSnakes() {
        return snakes;
    }

    @Override
    public void setFood(Food food) {
        this.food = food;
    }

    @Override
    public Food getFood() {
        return food;
    }

    @Override
    public List<IPoint> getAvailablePoints() {
        return availablePoints;
    }

    @Override
    public IPoint occupyRandomPoint() {
        return availablePoints.remove((int)(Math.random() * (availablePoints.size() - 1)));
    }

    @Override
    public void occupyPoint(IPoint point) {
        availablePoints.remove(point);
    }

    @Override
    public List<Poison> getPoisons() {
        return poisons;
    }

    @Override
    public List<PowerUp> getPowerUps() {
        return powerUps;
    }

}
