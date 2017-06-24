package client;

import model.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import util.Constants;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Created by Eugen Gruzdev
 */
public class SnakeAlgorithm {

    private static final Logger logger = LogManager.getLogger(Client.class);
    private IState state;
    private int id;
    private Client client;
    private boolean flag = false;  // flag to show the snake's current state
    private boolean contraryDirectionFlag = false; // flag to denote that the snake have to go in contrary direction


    public SnakeAlgorithm(IState state,  int id, Client client){
        this.state = state;
        this.id = id;
        this. client = client;
    }

    public Direction getFirstDirection(){
        HashMap<Integer, ISnake> allSnakes = this.state.getSnakes(); //all in the beginning generated snakes
        IPoint myPosition = client.getSnake().getPoints().get(0);   // the point where the current snake is situated
        IPoint food = this.state.getFood();     // the point where the food is situated
        ArrayList<ISnake> allSnakesAsList = new ArrayList<ISnake>();
        List<Poison> poisons = this.state.getPoisons();
        List<PowerUp> powerUps = this.state.getPowerUps();
        int currentSpeed = client.getSnake().getSpeed();

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
        IPoint myPosition = client.getSnake().getPoints().get(client.getSnake().getPoints().size() - 1);
        int currentSnakeLength = client.getSnake().getPoints().size(); // the size of the current snake
        List<IPoint> thisSnake = new ArrayList<IPoint>(client.getSnake().getPoints()); // all the points of the current snake
        IPoint food = this.state.getFood();     // the point where the food is situated
        ArrayList<ISnake> allSnakesAsList = new ArrayList<ISnake>();
        List<Poison> poisons = this.state.getPoisons();
        List<PowerUp> powerUps = this.state.getPowerUps();
        int currentSpeed = client.getSnake().getSpeed();

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

    private int differenceOfPoints(IPoint pointA, IPoint pointB){
        return (Math.abs(pointA.getX() - pointB.getX()) + Math.abs(pointA.getY() - pointB.getY()));
    }

    private Direction contraryDirection(Direction direction){
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

    private Direction sideDirectionRelativeToFood (Direction direction){
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

    private boolean isContraryDirection(Direction direction1, Direction direction2){
        if(contraryDirection(direction1).equals(direction2)){
            return true;
        }
        return false;
    }

    private Direction contraryDirectionHandler(IPoint myPosition, Direction previousDirection, IPoint food, List<IPoint> occupiedPoints){
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

    private Direction getNewDirectionAfterOccupiedPrevious
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

    private ArrayList<IPoint> getOccupiedPoints
            (ArrayList<ISnake> allSnakes, List<Poison> poisons, List<PowerUp> powerUps, int speed){
        ArrayList<IPoint> occupiedPoints = new ArrayList<IPoint>();
        for(ISnake snake : allSnakes){
            List<IPoint> points = snake.getPoints();
            for(IPoint point : points){
                occupiedPoints.add(point);
            }
        }

        for(Poison p : poisons){
            occupiedPoints.add(Factory.createPoint(p.getX(), p.getY()));
        }

        if(speed >= 300){
            for(PowerUp p : powerUps){
                occupiedPoints.add(Factory.createPoint(p.getX(), p.getY()));
            }
        }

        return occupiedPoints;
    }

    private Direction getDirectionRelativeToFood(IPoint myPosition, IPoint foodPosition){
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

    private boolean nextDirectionStepIsNotOccupied(IPoint myPosition, Direction direction, List<IPoint> occupiedPoints){
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

        IPoint newPoint = Factory.createPoint(a,b);

        if(!occupiedPoints.contains(newPoint)){
            notOccupied = true;
        }

        return noBorder && notOccupied; // next direction step is not occupied
    }

}
