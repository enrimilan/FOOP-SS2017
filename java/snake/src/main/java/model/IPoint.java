package model;

import model.impl.*;

public interface IPoint {

    int getX();

    void setX(int x);

    int getY();

    void setY(int y);

    PointType getType();

    void setType(PointType type);

    int getArt();

    void setArt(int artID);


}
