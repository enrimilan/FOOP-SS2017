package model;

import java.util.HashMap;
import java.util.List;

public interface IState {

    HashMap<Integer, ISnake> getSnakes();

    List<IPoint> getToRemove();

    void setToRemove(List<IPoint> toRemove);
}
