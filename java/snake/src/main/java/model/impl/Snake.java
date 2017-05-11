package model.impl;

import model.IPoint;
import model.ISnake;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Snake implements ISnake, Serializable {

    private int id;
    private int speed = 100;

    public int getHealth() {
        return health;
    }

    public void setHealth(int health) {
        System.out.println("health = [" + health + "]");
        this.health = health;
    }

    private int health = 100;
    private String color;
    private List<IPoint> points = new ArrayList<IPoint>();

    public Snake(int id) {
        this.id = id;
    }

    @Override
    public void setSpeed(int speed) {
        this.speed = speed;
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

    @Override
    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String getColor() {
        return color;
    }

}
