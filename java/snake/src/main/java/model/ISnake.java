package model;

import java.util.List;

public interface ISnake {

    int getId();

    void setSpeed(int speed);

    int getSpeed();

    List<IPoint> getPoints();

    void setPoints(List<IPoint> points);

    void setColor(String color);

    String getColor();


}
