package model;

/**
 * Influences last for a limited amount of time
 * We have only positive influences for the speed and health.
 * These values mean by how much the speed and health of a snake should increase.
 */
public interface IInfluence {

    /**
     * @return the duration of the influence
     */
    int getDuration();

    /**
     * @return the starting time of the influence
     */
    long getStartTime();

    void setSpeed(int speed);

    int getSpeed();

    int getHealth();

}
