package model;

import java.util.List;

public interface ISnake {

    int getId();

    int getSpeed();

    List<IPoint> getPoints();

    void setPoints(List<IPoint> points);

}
