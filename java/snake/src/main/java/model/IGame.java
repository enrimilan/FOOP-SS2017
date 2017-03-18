package model;

public interface IGame {

    void addSnake(int id);

    IState updateState(int id, Direction direction);

    IState getState();

}
