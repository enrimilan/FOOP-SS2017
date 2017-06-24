package model;

import model.impl.*;

public class Factory {

    public static IState createState() {
        return new State();
    }

    public static AbstractGame createGame(IState state) {
        return new Game(state);
    }

    public static ISnake createSnake(int id, String color, IPoint head) {
        return new Snake(id, color, head);
    }

    public static IPoint createPoint(int x, int y) {
        return new Point(x,y);
    }

    public static Food createFood(IPoint point) {
        return new Food(point);
    }

    public static Poison createPoison(IPoint point) {
        return new Poison(point);
    }

    public static PowerUp createPowerUp(IPoint point) {
        return new PowerUp(point);
    }

    public static IInfluence createInfluence(int duration, int speed, int health, long startTime) {
        return new Influence(duration, speed, health, startTime);
    }
}
