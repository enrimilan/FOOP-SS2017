package model;

import model.impl.*;

import java.util.HashMap;
import java.util.List;

public interface IState {

    HashMap<Integer, ISnake> getSnakes();

    void setFood(Food food);

    Food getFood();

    List<Poison> getPoisons();

    List<PowerUp> getPowerUps();

    List<IPoint> getAvailablePoints();

    IPoint occupyRandomPoint();

    void occupyPoint(IPoint point);

}
