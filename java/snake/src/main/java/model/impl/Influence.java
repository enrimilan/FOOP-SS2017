package model.impl;

import model.IInfluence;

import java.io.Serializable;

public class Influence implements IInfluence, Serializable {

    private int duration;
    private int speed;
    private int health;
    private long startTime;

    public Influence(int duration, int speed, int health, long startTime) {
        this.duration = duration;
        this.speed = speed;
        this.health = health;
        this.startTime = startTime;
    }

    @Override
    public void setDuration(int duration) {
        this.duration = duration;
    }

    @Override
    public int getDuration() {
        return duration;
    }

    @Override
    public long getStartTime() {
        return startTime;
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

    @Override
    public int getHealth() {
        return health;
    }

}
