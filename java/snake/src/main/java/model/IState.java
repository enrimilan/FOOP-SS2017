package model;

import model.impl.*;

import java.util.HashMap;
import java.util.List;

public interface IState {

    HashMap<Integer, ISnake> getSnakes();

    List<IPoint> getToRemove();

    void setToRemove(List<IPoint> toRemove);

    void setFood(Food food);

    Food getFood();

    List<IPoint> getAvailablePoints();

    IPoint occupyRandomPoint();

    void setPoison(Poison poison);

    List<Poison> getPoison();

}
