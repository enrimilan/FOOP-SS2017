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

    private HashMap<Integer, ISnake> snakes = new HashMap<Integer, ISnake>();
    private List<IPoint> toRemove = new ArrayList<IPoint>();
    private List<IPoint> availablePoints = new ArrayList<IPoint>();
    private Food food;
    private List<Poison> poison;
    private List<PowerUp> powerups;

    public State() {
        for(int x = 0; x < Constants.BOARD_WIDTH; x++) {
            for(int y = 0; y < Constants.BOARD_HEIGHT; y++) {
                availablePoints.add(new Point(x, y));
            }
        }
        poison = new ArrayList<>();
        powerups = new ArrayList<>();
    }

    @Override
    public HashMap<Integer, ISnake> getSnakes() {
        return snakes;
    }

    @Override
    public List<IPoint> getToRemove() {
        return toRemove;
    }

    @Override
    public void setToRemove(List<IPoint> toRemove) {
        this.toRemove = toRemove;
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
        return availablePoints.remove((int)(Math.random() * availablePoints.size()));
    }

    @Override
    public void setPoison(Poison poison) {
        this.poison.add(poison);
    }

    @Override
    public List<Poison> getPoisons() {
        return poison;
    }

    @Override
    public void setPowerUp(PowerUp powerUp) {
        this.powerups.add(powerUp);
    }

    @Override
    public List<PowerUp> getPowerups() {
        return powerups;
    }

}
