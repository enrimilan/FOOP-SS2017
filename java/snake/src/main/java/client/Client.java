package client;

import client.gui.Board;
import client.gui.OnLaunchedCallback;
import model.*;
import model.impl.Point;
import model.Poison;
import model.PowerUp;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import util.Constants;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Client {

    private static final Logger logger = LogManager.getLogger(Client.class);
    private Board board;
    private ExecutorService executor;
    private ObjectInputStream in;
    private ObjectOutputStream out;
    private int id;
    private boolean firstState;
    private IState state;
    private GameUpdateListener gameUpdateListener;
    private SnakeDirectionSender snakeDirectionSender;
    private Socket socket;
    private Mode mode;

    private Direction lastDirection; // denotes the last direction of the snake
    private boolean flag = false;  // flag to show the snake's current state
    private boolean contraryDirectionFlag = false; // flag to denote that the snake have to go in contrary direction

    public Client(Mode mode) {
        this.executor = Executors.newCachedThreadPool();
        this.mode = mode;
    }

    public void join() throws IOException {
        this.socket = new Socket(Constants.HOST, Constants.PORT);
        this.id = socket.getLocalPort();
        logger.debug("Join with id {}", id);
        this.out = new ObjectOutputStream(socket.getOutputStream());
        this.in = new ObjectInputStream(socket.getInputStream());
        this.gameUpdateListener = new GameUpdateListener(this, in);
        executor.submit(gameUpdateListener);
    }

    public void onGameStateChanged(IState state) {
        this.state = state;
        if(!firstState) {
            logger.debug("First state arrived");
            firstState = true;
            this.snakeDirectionSender = new SnakeDirectionSender(this, out);
            executor.submit(snakeDirectionSender);
        }
        logger.debug("New state");
        if(!state.getSnakes().get(id).isPlaying()) {
            snakeDirectionSender.stop();
            close();
            logger.debug("Stop playing");
        }
        board.draw(state, this.id);
    }

    public Direction getNextDirectionFromBoard() {
        return board.getNextDirection();
    }

    /* Author: Gruzdev Eugen */
    public Direction getNextDirectionUsingAlgorithm() {
       if(lastDirection == null){  // If the first direction is null (the game beginning for this snake)
            lastDirection = getFirstDirection();
            return lastDirection;
        } else {
            lastDirection = getNextSnakeDirection(lastDirection);
            return lastDirection;
        }
    }

    public Direction getFirstDirection(){
        HashMap<Integer, ISnake> allSnakes = this.state.getSnakes(); //all in the beginning generated snakes
        IPoint myPosition = this.getSnake().getPoints().get(0);   // the point where the current snake is situated
        IPoint food = this.state.getFood();     // the point where the food is situated
        ArrayList<ISnake> allSnakesAsList = new ArrayList<ISnake>();
        List<Poison> poisons = this.state.getPoisons();
        List<PowerUp> powerUps = this.state.getPowerUps();
        int currentSpeed = this.getSnake().getSpeed();

        logger.debug("All Snakes size:" + allSnakes.size());
        logger.debug(allSnakes.get(this.id));

        for(Integer key : allSnakes.keySet()){
            if(key != this.id){
                try {
                    allSnakesAsList.add(allSnakes.get(key));
                } catch (NullPointerException e){
                    logger.fatal("NullPointerException: " + e);
                }
            }
        }

        if (allSnakesAsList != null) {
            List<IPoint> occupiedPoints = this.getOccupiedPoints(allSnakesAsList, poisons, powerUps, currentSpeed);
            Direction direction = getDirectionRelativeToFood(myPosition, food);
            if(nextDirectionStepIsNotOccupied(myPosition,direction,occupiedPoints)){
                return direction;
            } else {
                return this.getNewDirectionAfterOccupiedPrevious(myPosition,direction,food,occupiedPoints);
            }
        } else {
            return getDirectionRelativeToFood(myPosition, food);
        }
    }

    public Direction getNextSnakeDirection(Direction lastDirection){
        HashMap<Integer, ISnake> allSnakes = this.state.getSnakes(); //all generated snakes
        IPoint myPosition = this.getSnake().getPoints().get(this.getSnake().getPoints().size() - 1);
        int currentSnakeLength = this.getSnake().getPoints().size(); // the size of the current snake
        List<IPoint> thisSnake = new ArrayList<IPoint>(this.getSnake().getPoints()); // all the points of the current snake
        IPoint food = this.state.getFood();     // the point where the food is situated
        ArrayList<ISnake> allSnakesAsList = new ArrayList<ISnake>();
        List<Poison> poisons = this.state.getPoisons();
        List<PowerUp> powerUps = this.state.getPowerUps();
        int currentSpeed = this.getSnake().getSpeed();

        for(Integer key : allSnakes.keySet()){
            if(key != this.id){
                try {
                    allSnakesAsList.add(allSnakes.get(key));
                } catch (NullPointerException e){
                    logger.fatal("NullPointerException: " + e);
                }
            }
        }

        List<IPoint> occupiedPoints = new ArrayList<IPoint>();   // list of all currently occupied points on the board
        // here including the current snake

        if(allSnakesAsList.size() >= 0) {
            occupiedPoints.addAll(this.getOccupiedPoints(allSnakesAsList, poisons, powerUps, currentSpeed));
            occupiedPoints.addAll(thisSnake);
        }

        if(this.differenceOfPoints(myPosition, food) == 1){
            flag = true;
            return getDirectionRelativeToFood(myPosition, food);
        } else {
            Direction direction = getDirectionRelativeToFood(myPosition, food);
            if(nextDirectionStepIsNotOccupied(myPosition,direction,occupiedPoints)){
                return direction;
            } else {
                direction = getNewDirectionAfterOccupiedPrevious(myPosition,direction,food, occupiedPoints);
                return direction;
            }
        }
    }

    public int differenceOfPoints(IPoint pointA, IPoint pointB){
        return (Math.abs(pointA.getX() - pointB.getX()) + Math.abs(pointA.getY() - pointB.getY()));
    }

    public Direction contraryDirection(Direction direction){
        if(direction == Direction.DOWN){
            return Direction.UP;
        } else if (direction == Direction.UP){
            return Direction.DOWN;
        } else if (direction == Direction.LEFT){
            return Direction.RIGHT;
        } else if (direction == Direction.RIGHT){
            return Direction.LEFT;
        }
        return null;
    }

    public Direction sideDirectionRelativeToFood (Direction direction){
        if(direction == Direction.DOWN){
            return Direction.LEFT;
        } else if (direction == Direction.UP){
            return Direction.RIGHT;
        } else if (direction == Direction.LEFT){
            return Direction.UP;
        } else if (direction == Direction.RIGHT){
            return Direction.DOWN;
        }
        return null;
    }

    public boolean isContraryDirection(Direction direction1, Direction direction2){
        if(contraryDirection(direction1).equals(direction2)){
            return true;
        }
        return false;
    }

    public Direction contraryDirectionHandler(IPoint myPosition, Direction previousDirection, IPoint food, List<IPoint> occupiedPoints){
        Direction newDirection;
        Direction directionRelativeToFood = this.getDirectionRelativeToFood(myPosition,food);

        if(!isContraryDirection(directionRelativeToFood, previousDirection)){
            contraryDirectionFlag = false;
            return sideDirectionRelativeToFood(directionRelativeToFood);
        }

        if(previousDirection == Direction.LEFT){
            newDirection = Direction.DOWN;
            if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                return newDirection;
            } else {
                newDirection = Direction.UP;
                if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                    return newDirection;
                }
            }
            return previousDirection;
        }


        if(previousDirection == Direction.RIGHT){
            newDirection = Direction.DOWN;
            if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                return newDirection;
            } else {
                newDirection = Direction.UP;
                if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                    return newDirection;
                }
            }
            return previousDirection;
        }

        if(previousDirection == Direction.UP){
            newDirection = Direction.LEFT;
            if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                return newDirection;
            } else {
                newDirection = Direction.RIGHT;
                if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                    return newDirection;
                }
            }
            return previousDirection;
        }

        if(previousDirection == Direction.DOWN){
            newDirection = Direction.LEFT;
            if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                return newDirection;
            } else {
                newDirection = Direction.RIGHT;
                if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                    return newDirection;
                }
            }
            return previousDirection;
        }
        // Should not be reached
        return previousDirection;
    }

    public Direction getNewDirectionAfterOccupiedPrevious
            (IPoint myPosition, Direction previousDirection, IPoint food, List<IPoint> occupiedPoints){

        Direction newDirection;
        Direction directionRelativeToFood = this.getDirectionRelativeToFood(myPosition,food);

        if(contraryDirectionFlag){
            return contraryDirectionHandler(myPosition, previousDirection, food, occupiedPoints);
        }

        if(isContraryDirection(previousDirection, directionRelativeToFood)){
            contraryDirectionFlag = true;
            return contraryDirectionHandler(myPosition, previousDirection,food, occupiedPoints);
        } else {
            if (previousDirection == Direction.DOWN) {
                newDirection = Direction.LEFT;
                if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                    return newDirection;
                } else {
                    newDirection = Direction.RIGHT;
                    if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                        return newDirection;
                    }
                }
                return Direction.UP;
            } else if (previousDirection == Direction.UP) {
                newDirection = Direction.LEFT;
                if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                    return newDirection;
                } else {
                    newDirection = Direction.RIGHT;
                    if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                        return newDirection;
                    }
                }
                return Direction.DOWN;
            } else if (previousDirection == Direction.LEFT) {
                newDirection = Direction.DOWN;
                if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                    return newDirection;
                } else {
                    newDirection = Direction.UP;
                    if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                        return newDirection;
                    }
                }
                return Direction.RIGHT;
            } else if (previousDirection == Direction.RIGHT) {
                newDirection = Direction.DOWN;
                if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                    return newDirection;
                } else {
                    newDirection = Direction.UP;
                    if (nextDirectionStepIsNotOccupied(myPosition, newDirection, occupiedPoints)) {
                        return newDirection;
                    }
                }
                return Direction.LEFT;
            }
        }
        return previousDirection;
    }

    public ArrayList<IPoint> getOccupiedPoints
            (ArrayList<ISnake> allSnakes, List<Poison> poisons, List<PowerUp> powerUps, int speed){
        ArrayList<IPoint> occupiedPoints = new ArrayList<IPoint>();
        for(ISnake snake : allSnakes){
            List<IPoint> points = snake.getPoints();
            for(IPoint point : points){
                occupiedPoints.add(point);
            }
        }

        for(Poison p : poisons){
            occupiedPoints.add(new Point(p.getX(), p.getY()));
        }

        if(speed >= 300){
            for(PowerUp p : powerUps){
                occupiedPoints.add(new Point(p.getX(), p.getY()));
            }
        }

        return occupiedPoints;
    }

    public Direction getDirectionRelativeToFood(IPoint myPosition, IPoint foodPosition){
        /*Coordinates of my position */
        int x_1 = myPosition.getX();
        int y_1 = myPosition.getY();
        /* Coordinates of food position */
        int x_2 = foodPosition.getX();
        int y_2 = foodPosition.getY();

        if((x_1 < x_2) && (y_1 == y_2)){
            return Direction.RIGHT;
        } else if((x_1 < x_2) && (y_1 > y_2)){
            return Direction.UP;
        } else if((x_1 < x_2) && (y_1 < y_2)){
            return Direction.DOWN;
        }
        else if ((x_1 > x_2) && (y_1 == y_2)){
            return Direction.LEFT;
        } else if((x_1 > x_2) && (y_1 < y_2)){
            return Direction.DOWN;
        } else if((x_1 > x_2) && (y_1 > y_2)){
            return Direction.UP;
        }
        else if ((x_1 == x_2) && (y_1 == y_2)){
            return Direction.RIGHT;
        } else if((x_1 == x_2) && (y_1 < y_2)){
            return Direction.DOWN;
        } else if((x_1 == x_2) && (y_1 > y_2)){
            return Direction.UP;
        }
        // Should never be reached
        return Direction.RIGHT;
    }

    public boolean nextDirectionStepIsNotOccupied(IPoint myPosition, Direction direction, List<IPoint> occupiedPoints){
        /* Coordinates of my position */
        int x = myPosition.getX();
        int y = myPosition.getY();

        /* Coordinates of next position */
        int a = 0, b = 0;

        boolean noBorder = true; // in the current position there is any border
        boolean notOccupied = false; // the current position is occupied

        /* STEP */
        if(direction == Direction.DOWN){
            a = x;
            b = y + 1;
        }
        if(direction == Direction.UP){
            a = x;
            b = y - 1;
        }
        if(direction == Direction.LEFT){
            a = x - 1;
            b = y;
        }
        if(direction == Direction.RIGHT){
            a = x + 1;
            b = y;
        }

        if((a >= Constants.BOARD_WIDTH) || (a < 0)){
            noBorder = false;
        }
        if((b >= Constants.BOARD_HEIGHT) || (b < 0)){
            noBorder = false;
        }

        Point newPoint = new Point(a,b);

        if(!occupiedPoints.contains(newPoint)){
            notOccupied = true;
        }

        return noBorder && notOccupied; // next direction step is not occupied
    }


    public Direction getNextDirection(Direction direction){
        if(direction == Direction.DOWN){
            return Direction.LEFT;
        } else if(direction == Direction.UP){
            return Direction.RIGHT;
        } else if(direction == Direction.LEFT){
            return Direction.UP;
        }
        return Direction.DOWN;
    }

    public ISnake getSnake() {
        return state.getSnakes().get(id);
    }

    public Mode getMode() {
        return mode;
    }

    private void close() {
        logger.debug("Close client");
        gameUpdateListener.stop();
        snakeDirectionSender.stop();
        try {
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        executor.shutdown();
    }

    public static void main(String[] args) {
        if(args.length != 1) {
            throw new IllegalArgumentException("Usage: Client [PLAYER | COMPUTER]");
        }
        final Client client = new Client(Mode.valueOf(args[0]));

        //blocks until window closed by user
        Board.launch(new OnLaunchedCallback() {
            @Override
            public void onApplicationLaunched(final Board board) {

                //spawn a new thread, since the main thread belongs to the UI.
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        try {

                            // workaround: wait 2 seconds for the UI
                            Thread.sleep(2000);

                            client.board = board;
                            client.join();
                        } catch (InterruptedException | IOException e) {
                            e.printStackTrace();
                        }
                    }
                }).start();
            }
        });

        // window has been closed at this point, so close the client
        client.close();

    }
}
