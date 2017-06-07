package model;

import java.io.*;
import java.util.*;

public class Poison extends PointDecorator implements Serializable {

    private Long systemTime;
    private int type = 0;

    public Poison(IPoint point) {
        super(point);
        this.systemTime = System.currentTimeMillis();
        Random rand = new Random();
        type = rand.nextInt(4);
    }

    public Long getSystemTime() {
        return systemTime;
    }

    public int getType(){
        return type;
    }

}
