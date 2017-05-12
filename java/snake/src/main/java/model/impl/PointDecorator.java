package model.impl;

import model.*;

import java.io.*;

/**
 * Created by skep on 12.05.2017.
 */
public abstract class PointDecorator implements IPoint, Serializable {

    protected IPoint decoratedPoint;

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
