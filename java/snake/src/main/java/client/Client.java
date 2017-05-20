package client;

import client.gui.Board;
import client.gui.OnLaunchedCallback;
import model.*;
import model.impl.Point;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.omg.PortableInterceptor.DISCARDING;
import util.Constants;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.*;
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

    /* Global variables for the snake bot */
    /* --- */
    private Direction lastDirection = null; // the variable saves the last direction of the current snake
                                            // initially the snake has no direction
    boolean flag = false; // flag denotes the state when the snake is not near the food
                          // if the snake is near to food (is left one single step), then flag is true
                         // otherwise false
    /* --- */

    public Client(Mode mode) {
        this.executor = Executors.newCachedThreadPool();
        this.mode = mode;
        //this.mode = Mode.COMPUTER;
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
        board.draw(state);
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
        List<IPoint> occupiedPoints = this.getOccupiedPoints(allSnakesAsList);
        Direction direction = getDirectionRelativeToFood(myPosition, food);

      /*  int counter = 0;
        while(counter < 4) { // try all possible directions if needed
            if (nextDirectionStepIsNotOccupied(myPosition, direction, occupiedPoints)) {
                return direction;
            } else {
                direction = getNextDirection(direction);
                counter++;
            }
        }*/
        return direction;
        } else {
            return getDirectionRelativeToFood(myPosition, food);
        }
    }

    public Direction getNextSnakeDirection(Direction lastDirection){
        HashMap<Integer, ISnake> allSnakes = this.state.getSnakes(); //all generated snakes
        IPoint myPosition = this.getSnake().getPoints().get(this.getSnake().getPoints().size() - 1);
                                                // the point where the head current snake is situated
        int currentSnakeLength = this.getSnake().getPoints().size(); // the size of the current snake
        List<IPoint> thisSnake = new ArrayList<IPoint>(this.getSnake().getPoints()); // all the points of the current snake
        IPoint food = this.state.getFood();     // the point where the food is situated
        ArrayList<ISnake> allSnakesAsList = new ArrayList<ISnake>();

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
            occupiedPoints.addAll(this.getOccupiedPoints(allSnakesAsList));
            occupiedPoints.addAll(thisSnake);
        }

        if(this.differenceOfPoints(myPosition, food) == 1){
            flag = true;
            return lastDirection;
        } else {
                Direction direction = getDirectionRelativeToFood(myPosition, food);
                if(nextDirectionStepIsNotOccupied(myPosition,direction,occupiedPoints)){
                    return direction;
                } else {
                    //logger.debug("I AM HERE!");
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

    public Direction getNewDirectionAfterOccupiedPrevious
            (IPoint myPosition, Direction previousDirection, IPoint food, List<IPoint> occupiedPoints){

        Direction newDirection;

        if(previousDirection == Direction.DOWN){
            newDirection = Direction.RIGHT;
            if(nextDirectionStepIsNotOccupied(myPosition,newDirection,occupiedPoints)){
                return newDirection;
            } else {
                newDirection = Direction.LEFT;
                if(nextDirectionStepIsNotOccupied(myPosition,newDirection,occupiedPoints)){
                    return newDirection;
                }
            }
            return Direction.UP;
        }
        else
        if(previousDirection == Direction.UP){
            newDirection = Direction.RIGHT;
            if(nextDirectionStepIsNotOccupied(myPosition,newDirection,occupiedPoints)){
                return newDirection;
            } else {
                newDirection = Direction.LEFT;
                if(nextDirectionStepIsNotOccupied(myPosition,newDirection,occupiedPoints)){
                    return newDirection;
                }
            }
            return Direction.DOWN;
        }
        else if (previousDirection == Direction.LEFT){
            newDirection = Direction.UP;
            if(nextDirectionStepIsNotOccupied(myPosition,newDirection,occupiedPoints)){
                return newDirection;
            } else {
                newDirection = Direction.DOWN;
                if(nextDirectionStepIsNotOccupied(myPosition,newDirection,occupiedPoints)){
                    return newDirection;
                }
            }
            return Direction.RIGHT;
        }
        else if (previousDirection == Direction.RIGHT){
            newDirection = Direction.UP;
            if(nextDirectionStepIsNotOccupied(myPosition,newDirection,occupiedPoints)){
                return newDirection;
            } else {
                newDirection = Direction.DOWN;
                if(nextDirectionStepIsNotOccupied(myPosition,newDirection,occupiedPoints)){
                    return newDirection;
                }
            }
            return Direction.LEFT;
        }
        return previousDirection;
    }

    public ArrayList<IPoint> getOccupiedPoints(ArrayList<ISnake> allSnakes){
        ArrayList<IPoint> occupiedPoints = new ArrayList<IPoint>();
        for(ISnake snake : allSnakes){
            List<IPoint> points = snake.getPoints();
            for(IPoint point : points){
                occupiedPoints.add(point);
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

        if((a > Constants.BOARD_WIDTH) || (a < 0)){
            noBorder = false;
        }
        if((b > Constants.BOARD_HEIGHT) || (b < 0)){
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
        final Client client = new Client(Mode.PLAYER);

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
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        } catch (IOException e) {
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
