package model.impl;

import model.*;

import java.io.Serializable;
import java.util.*;

public class Snake implements ISnake, Serializable {

    private int id;
    private int speed = 100;
    private int health = 100;
    private String color;
    private Direction direction;
    private List<IPoint> points = new ArrayList<IPoint>();
    private List<IInfluence> influences = new ArrayList<>();
    private boolean playing = true;

    public Snake(int id, String color) {
        this.id = id;
        this.color = color;
    }

    @Override
    public int getId() {
        return id;
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
    public void setHealth(int health) {
        this.health = health;
    }

    public int getHealth() {
        return health;
    }

    @Override
    public int getLength() {
        return points.size();
    }

    @Override
    public void addHead(IPoint point) {
        points.add(point);
    }

    @Override
    public List<IPoint> getPoints() {
        return points;
    }

    @Override
    public IPoint getHead() {
        if(points.size() > 0) {
            return points.get(points.size() - 1);
        }
        return null;
    }

    @Override
    public IPoint getTail() {
        if(points.size() > 0) {
            return points.get(0);
        }
        return null;
    }

    @Override
    public String getColor() {
        return color;
    }

    @Override
    public Direction getDirection() {
        return direction;
    }

    @Override
    public void setDirection(Direction dir) {
        this.direction = dir;
    }

    @Override
    public List<IInfluence> getInfluences() {
        return influences;
    }

    @Override
    public void setIsPlaying(boolean playing) {
        this.playing = playing;
    }

    @Override
    public boolean isPlaying() {
        return playing;
    }

}