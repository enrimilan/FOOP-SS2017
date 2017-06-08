package model;

public interface IGame {

    void addSnake(int id);

    void removeSnake(int id);

    IState updateState(int id, Direction direction);

    IState getState();

    boolean hasFinished();

}
