package model.impl;

import model.IPoint;
import model.ISnake;
import model.IState;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class State implements IState, Serializable {

    private HashMap<Integer, ISnake> snakes = new HashMap<Integer, ISnake>();
    private List<IPoint> toRemove = new ArrayList<IPoint>();

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

}
