package model;

import java.util.HashMap;
import java.util.List;

/**
 * Represents the state of the game.
 */
public interface IState {

    /**
     * @return the snake which are part of the game
     */
    HashMap<Integer, ISnake> getSnakes();

    void setFood(Food food);

    Food getFood();

    List<Poison> getPoisons();

    List<PowerUp> getPowerUps();

    /**
     * @return a list with non-occupied points on the board.
     */
    List<IPoint> getAvailablePoints();

    /**
     * Adds a game result for a specific snake
     * @param id the id of the snake
     * @param result the game result for this snake
     */
    void addResult(int id, String result);

    /**
     * @param id the id of the snake
     * @return the game result for this snake
     */
    String getResult(int id);

    /**
     * Sets the elapsed time for this state from the moment it was initialized
     * @param timeElapsed the updated elapsed time
     */
    void setTimeElapsed(long timeElapsed);

    /**
     * @return the elapsed time for this state from the moment it was initialized
     */
    Long getTimeElapsed();

}
