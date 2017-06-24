package model;

import java.util.*;

/**
 * Represents a snake for the game. Its initial speed and health are 100.
 */
public interface ISnake {

    int getId();

    void setSpeed(int speed);

    int getSpeed();

    void setHealth(int health);

    int getHealth();

    int getLength();

    void addHead(IPoint point);

    /**
     * A snake's body consists of many points
     * @return the snake body (includes head and tail of course)
     */
    List<IPoint> getPoints();

    IPoint getHead();

    IPoint getTail();

    String getColor();

    Direction getDirection();

    void setDirection(Direction dir);

    /**
     * @return a list with influences for the snake. Can be speed and health influences.
     */
    List<IInfluence> getInfluences();

    void setIsPlaying(boolean playing);

    boolean isPlaying();

}
