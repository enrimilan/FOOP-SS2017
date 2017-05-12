package model.impl;

import model.*;

import java.io.*;
import java.util.*;

/**
 * Created by skep on 12.05.2017.
 */
public class Poison extends PointDecorator implements Serializable {

    Random rand = new Random();
    int arttype = 0;

    public Poison(IPoint point) {
        super(point);
        arttype = rand.nextInt(4);
    }

    public int getArt(){
        return arttype;
    }
}
