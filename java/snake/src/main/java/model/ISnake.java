package model;

import java.util.*;

public interface ISnake {

    int getId();

    void setSpeed(int speed);

    int getSpeed();

    void setHealth(int health);

    int getHealth();

    int getLength();

    void addHead(IPoint point);

    List<IPoint> getPoints();

    IPoint getHead();

    IPoint getTail();

    String getColor();

    Direction getDirection();

    void setDirection(Direction dir);

    List<IInfluence> getInfluences();

    void setIsPlaying(boolean playing);

    boolean isPlaying();

}
