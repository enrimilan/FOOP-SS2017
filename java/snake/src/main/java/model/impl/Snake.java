package model.impl;

import model.*;

import java.io.Serializable;
import java.util.*;

public class Snake implements ISnake, Serializable {

    private int id;
    private int speed = 100;
    //which type was at which timestamp(long) activated:
    private HashMap<PowerUpType, Long> activePowerUps = new HashMap<>();
    private int snakeUnderInflucenceOfPowerups = 0;
    private Long activeGoodBiting;
    private Long activeBadBiting;
    private Direction heading;
    private int snakeHasBittenOtherSnake = 0;


    private int snakeWasBittenByOtherSnake = 0;
    private int health = 100;
    private String color;
    private List<IPoint> points = new ArrayList<IPoint>();

    public Snake(int id) {
        this.id = id;
    }


    public int getSnakeWasBittenByOtherSnake() {
        return snakeWasBittenByOtherSnake;
    }

    public void setSnakeWasBittenByOtherSnake(int snakeWasBittenByOtherSnake) {
        this.snakeWasBittenByOtherSnake = snakeWasBittenByOtherSnake;
    }

    public Long getActiveBadBiting() {
        return activeBadBiting;
    }

    public void setActiveBadBiting(Long activeBadBiting) {
        this.activeBadBiting = activeBadBiting;
    }

    public Long getActiveGoodBiting() {
        return activeGoodBiting;
    }

    public void setActiveGoodBiting(Long activeBiting) {
        this.activeGoodBiting = activeBiting;
    }

    public int getHasBittenCount() {
        return snakeHasBittenOtherSnake;
    }

    public void setHasBittenCount(int snakeHasBittenOtherSnake) {
        this.snakeHasBittenOtherSnake = snakeHasBittenOtherSnake;
    }

    public HashMap<PowerUpType, Long> getActivePowerUps() {
        return activePowerUps;
    }

    public void setActivePowerUps(PowerUpType pT, Long tS) {
        this.activePowerUps.put(pT,tS);
    }

    public void setActivePowerUps(HashMap<PowerUpType, Long> activePowerUps) {
        this.activePowerUps = activePowerUps;
    }

    public void removePowerUp(PowerUpType pT){
        this.activePowerUps.remove(pT);
    }

    @Override
    public Direction getDirection() {
        return heading;
    }

    @Override
    public void setDirection(Direction dir) {
        this.heading = dir;
    }


    public int getPowerUpInfluenceCount() {
        return snakeUnderInflucenceOfPowerups;
    }

    public void setPowerUpInfluenceCount(int p) {
        this.snakeUnderInflucenceOfPowerups = p;
    }

    public int getHealth() {
        return health;
    }

    public void setHealth(int health) {
        System.out.println("health = [" + health + "]");
        this.health = health;
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
