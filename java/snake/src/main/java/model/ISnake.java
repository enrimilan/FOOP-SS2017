package model;

import model.impl.*;

import java.util.*;

public interface ISnake {

    int getId();

    void setSpeed(int speed);

    int getSpeed();

    List<IPoint> getPoints();

    void setPoints(List<IPoint> points);

    void setColor(String color);

    String getColor();

    void setHealth(int health);

    int getHealth();

    int getPowerUpInfluenceCount();

    void setPowerUpInfluenceCount(int playerUnderPowerUPInfluence);

    HashMap<PowerUpType, Long> getActivePowerUps();

    void setActivePowerUps(PowerUpType powerUpType, Long timestamp);

     void setActivePowerUps(HashMap<PowerUpType, Long> activePowerUps);

    void removePowerUp(PowerUpType pT);




}
