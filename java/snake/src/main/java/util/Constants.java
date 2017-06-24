package util;

public class Constants {

    // connecting
    public static final String HOST = "localhost";
    public static final int PORT = 1337;

    // game
    public static final int BOARD_WIDTH = 40;
    public static final int BOARD_HEIGHT= 20;
    public static final int GAME_DURATION = 2 * 60 * 1000;
    public static final int MAX_PLAYERS = 4;

    // colors
    public static final String BLUE = "blue";
    public static final String DARKRED = "darkred";
    public static final String DARKGREEN = "darkgreen";
    public static final String DARKORANGE = "darkorange";


    public static final int MAX_SPEED = 550;
    public static final int MIN_SPEED = 50;
    public static final int MAX_ARTIFACT_TIME = 10000;

    public static final int FOOD_SPEED = 30;
    public static final int FOOD_HEALTH = 50;

    public static final int POISON_CHANCE = 5;
    public static final int POISON_MAX = 3;
    public static final int POISON_SPEED = 50;
    public static final int POISON_HEALTH = 30;

    public static final int POWER_UP_CHANCE = 20;
    public static final int POWER_UP_MAX = 2;
    public static final int POWER_UP_DURATION = 10000;
    public static final int POWER_UP_SPEED = 50;
    public static final int POWER_UP_HEALTH = 100;

    public static final int BITING_DURATION = 5000;
    public static final int BITING_HEALTH = 10;
    public static final int BITING_SPEED = 10;

    // game results
    public static final String LOST_MESSAGE = "You lost";
    public static final String WON_MESSAGE = "You won";
    public static final String DRAW_MESSAGE = "It's a draw";

}
