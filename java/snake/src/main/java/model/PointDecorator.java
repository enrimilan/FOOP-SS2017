package model;

import java.io.*;

public abstract class PointDecorator implements IPoint, Serializable {

    public IPoint decoratedPoint;

    public PointDecorator(IPoint point) {
        this.decoratedPoint = point;
    }

    @Override
    public int getX() {
        return decoratedPoint.getX();
    }

    @Override
    public void setX(int x) {
        decoratedPoint.setX(x);
    }

    @Override
    public int getY() {
        return decoratedPoint.getY();
    }

    @Override
    public void setY(int y) {
        decoratedPoint.setY(y);
    }

}
