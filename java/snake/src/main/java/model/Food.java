package model;

import java.util.Random;
import java.io.*;

public class Food extends PointDecorator implements Serializable {

    private int type = 0;

    public Food(IPoint point) {
        super(point);
        Random rand = new Random();
        type = rand.nextInt(4);
    }

    public int getType(){
        return type;
    }

    @Override
    public boolean equals(Object obj) {
        return obj.getClass() == Food.class && this.decoratedPoint.equals(((Food)obj).decoratedPoint);
    }

}
