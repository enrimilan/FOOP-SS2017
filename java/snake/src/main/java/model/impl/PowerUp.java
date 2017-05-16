package model.impl;

import model.*;

import java.io.*;
import java.util.*;

/**
 * Created by skep on 12.05.2017.
 */
public class PowerUp extends PointDecorator implements Serializable {


    Random rand = new Random();
    int arttype = 0;
    PowerUpType type;

    public PowerUp(IPoint point) {
        super(point);
        arttype = rand.nextInt(4);
        switch (arttype){
            case 0: type = PowerUpType.HEALTH; break;
            case 1: type = PowerUpType.SPEED; break;
            case 2: type = PowerUpType.INVINCIBILITY; break;
            case 3: type = PowerUpType.LENGTH;
        }

    }

    public int getArt(){
        return arttype;
    }

    public PowerUpType getType(){
        return type;
    }
}
