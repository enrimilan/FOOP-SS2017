package model.impl;

import model.*;
import java.util.Random;
import java.io.*;

/**
 * Created by skep on 12.05.2017.
 */
public class Food extends PointDecorator implements Serializable {

    Random rand = new Random();
    int arttype = 0;

    public Food(IPoint point) {
        super(point);
        arttype = rand.nextInt(4);
    }

    public int getArt(){
        return arttype;
    }


}
