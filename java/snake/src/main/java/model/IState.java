package model;

import java.util.HashMap;
import java.util.List;

public interface IState {

    HashMap<Integer, ISnake> getSnakes();

    void setFood(Food food);

    Food getFood();

    List<Poison> getPoisons();

    List<PowerUp> getPowerUps();

    List<IPoint> getAvailablePoints();

    void addResult(int id, String result);

    String getResult(int id);

    void setTimeElapsed(long timeElapsed);

    Long getTimeElapsed();

}
