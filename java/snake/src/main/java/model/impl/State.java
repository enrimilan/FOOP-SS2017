package model.impl;

import model.*;
import util.Constants;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class State implements IState, Serializable {

    private HashMap<Integer, ISnake> snakes = new HashMap<>();
    private HashMap<Integer, String> results = new HashMap<>();
    private List<IPoint> availablePoints = new ArrayList<>();
    private Food food;
    private List<Poison> poisons = new ArrayList<>();
    private List<PowerUp> powerUps = new ArrayList<>();
    private Long timeElapsed = 0L;

    public State() {
        for(int x = 0; x < Constants.BOARD_WIDTH; x++) {
            for(int y = 0; y < Constants.BOARD_HEIGHT; y++) {
                availablePoints.add(Factory.createPoint(x, y));
            }
        }
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
    public void addResult(int id, String result) {
        results.put(id, result);
    }

    @Override
    public String getResult(int id) {
        return results.get(id);
    }

    @Override
    public void setTimeElapsed(long staringTime) {
        this.timeElapsed = staringTime;
    }

    @Override
    public Long getTimeElapsed() {
        return timeElapsed;
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
