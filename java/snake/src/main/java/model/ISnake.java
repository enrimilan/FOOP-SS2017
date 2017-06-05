package model;

import java.util.*;

public interface ISnake {

    int getId();

    void setSpeed(int speed);

    int getSpeed();

    void setHealth(int health);

    int getHealth();

    List<IPoint> getPoints();

    void setPoints(List<IPoint> points);

    IPoint getHead();

    IPoint getTail();

    void setColor(String color);

    String getColor();

    Direction getDirection();

    void setDirection(Direction dir);

    List<IInfluence> getInfluences();

}
