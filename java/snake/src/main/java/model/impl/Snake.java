package model.impl;

import model.IPoint;
import model.ISnake;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Snake implements ISnake, Serializable {

    private int id;
    private int speed = 1;
    private int health; //TODO
    private List<IPoint> points = new ArrayList<IPoint>();

    public Snake(int id) {
        this.id = id;
    }

    @Override
    public int getSpeed() {
        return speed;
    }

    @Override
    public int getId() {
        return id;
    }

    @Override
    public List<IPoint> getPoints() {
        return points;
    }

    @Override
    public void setPoints(List<IPoint> points) {
        this.points = points;
    }

}
