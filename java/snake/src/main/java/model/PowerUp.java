package model;

import java.io.*;
import java.util.*;

public class PowerUp extends PointDecorator implements Serializable {

    private Long systemTime;
    private PowerUpType type;

    public PowerUp(IPoint point) {
        super(point);
        this.systemTime = System.currentTimeMillis();
        Random rand = new Random();
        switch (rand.nextInt(2)){
            case 0: type = PowerUpType.HEALTH; break;
            case 1: type = PowerUpType.SPEED; break;
            case 2: type = PowerUpType.INVINCIBILITY; break;
            case 3: type = PowerUpType.LENGTH;
        }
    }

    public Long getSystemTime() {
        return systemTime;
    }

    public PowerUpType getType(){
        return type;
    }

}
