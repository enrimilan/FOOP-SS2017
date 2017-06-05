package client.gui;

import javafx.application.*;
import javafx.beans.property.*;
import javafx.collections.ObservableList;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Control;
import javafx.scene.control.Label;
import javafx.scene.image.*;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import model.*;
import model.impl.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import util.Constants;

import java.util.*;

public class Board extends Application {

    private static final Logger logger = LogManager.getLogger(Board.class);
    private static OnLaunchedCallback onLaunchedCallback;
    private GridPane field;
    private StringProperty healthString = new SimpleStringProperty("100");
    private StringProperty speedString = new SimpleStringProperty("100");
    private Node foodNode;
    private ArrayList<Node> poisonNodes = new ArrayList<>();
    private ArrayList<Node> powerUpNodes = new ArrayList<>();
    private ArrayList<ISnake> snakes = new ArrayList<>();
    private Direction direction = Direction.RIGHT;

    public static void launch(OnLaunchedCallback onLaunchedCallback1) {
        onLaunchedCallback = onLaunchedCallback1;
        launch(Board.class);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Snake");
        GridPane infoPane = createInfoPane();
        this.field = createField();
        VBox vBox = new VBox();
        vBox.getChildren().add(infoPane);
        vBox.getChildren().add(field);
        Scene scene = new Scene(vBox, 870, 470);
        scene.setOnKeyPressed(keyEvent -> {
            if (keyEvent.getCode().equals(KeyCode.RIGHT)) {
                direction = Direction.RIGHT;
            }
            if (keyEvent.getCode().equals(KeyCode.LEFT)) {
                direction = Direction.LEFT;
            }
            if (keyEvent.getCode().equals(KeyCode.DOWN)) {
                direction = Direction.DOWN;
            }
            if (keyEvent.getCode().equals(KeyCode.UP)) {
                direction = Direction.UP;
            }
        });
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
        onLaunchedCallback.onApplicationLaunched(this);
    }

    public void draw(IState state, int id) {
        drawFood(state);
        drawPoisons(state);
        drawPowerUps(state);
        drawSnakes(state);
        Platform.runLater(() -> {
            healthString.set("" + state.getSnakes().get(id).getHealth());
            speedString.set("" + state.getSnakes().get(id).getSpeed());
        });
    }

    public Direction getNextDirection() {
        return direction;
    }

    private ISnake getSnake(int id) {
        for(ISnake snake : snakes) {
            if(snake.getId() == id) {
                return snake;
            }
        }
        return null;
    }

    private GridPane createInfoPane() {
        // gather images
        Image heartImg = new Image(Board.class.getResourceAsStream("/img/heart.png"));
        Image speedImg = new Image(Board.class.getResourceAsStream("/img/speed.png"));

        // infopane
        GridPane infoPane = new GridPane();
        infoPane.setHgap(10);

        //health icon
        Label healthIcon = new Label();
        healthIcon.setMinSize(30, 30);
        healthIcon.setGraphic(new ImageView(heartImg));
        infoPane.add(healthIcon,0,0);

        //health value
        Label healthValue = new Label();
        healthValue.setMinSize(30, 30);
        healthValue.textProperty().bind(healthString);
        infoPane.add(healthValue, 1, 0);

        // speed
        Label speedIcon = new Label();
        speedIcon.setMinSize(30, 30);
        speedIcon.setGraphic(new ImageView(speedImg));
        infoPane.add(speedIcon,2,0);

        // speed value
        Label speedValue = new Label();
        speedValue.setMinSize(30, 30);
        speedValue.textProperty().bind(speedString);
        infoPane.add(speedValue, 3, 0);

        return infoPane;
    }

    private GridPane createField() {
        GridPane field = new GridPane();
        for(int x = 0; x < Constants.BOARD_HEIGHT; x++) {
            for(int y = 0; y < Constants.BOARD_WIDTH; y++) {
                Label label = new Label();
                label.setMinSize(20, 20);
                label.setMaxSize(20, 20);
                field.add(label, y, x, 1, 1);
            }
        }
        for (Node n: field.getChildren()) {
            if (n instanceof Control) {
                Control control = (Control) n;
                control.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
                control.setStyle("-fx-background-color: white; -fx-alignment: center;");
            }
            if (n instanceof Pane) {
                Pane pane = (Pane) n;
                pane.setMaxSize(Double.MAX_VALUE, Double.MAX_VALUE);
                pane.setStyle("-fx-background-color: white; -fx-alignment: center;");
            }
        }
        field.setStyle("-fx-background-color: white; -fx-border-color: black; -fx-padding: 2; -fx-hgap: 2; -fx-vgap: 2;");
        return field;
    }

    private Node getNodeByRowColumnIndex (final int row, final int column, GridPane gridPane) {
        ObservableList<Node> children = gridPane.getChildren();
        for (Node node : children) {
            if(GridPane.getRowIndex(node) == row && GridPane.getColumnIndex(node) == column) {
                return node;
            }
        }
        throw new IllegalArgumentException(column + ", " + row + " are invalid coordinates");
    }

    private void drawFood(IState state) {
        Food food = state.getFood();
        if(food != null) {
            if(foodNode != null) {
                foodNode.setStyle("-fx-background-color: white;");
            }
            foodNode = getNodeByRowColumnIndex(food.getY(), food.getX(), field);
            logger.debug("Setting Food, type is: "+food.getArt());
            foodNode.setStyle("-fx-background-image: url(\"/img/food"+food.getArt()+".png\");");
        }
    }

    private void drawPoisons(IState state) {
        List<Poison> poison = state.getPoisons();
        for(Node poisonNode : poisonNodes) {
            poisonNode.setStyle("-fx-background-color: white;");
        }
        poisonNodes.clear();
        for(Poison p : poison) {
            Node n = getNodeByRowColumnIndex(p.getY(), p.getX(), field);
            n.setStyle("-fx-background-image: url(\"/img/poison" + p.getArt() + ".png\");");
            poisonNodes.add(n);
        }
    }

    private void drawPowerUps(IState state) {
        List<PowerUp> powerUps = state.getPowerUps();
        for (Node powerUpNode : powerUpNodes) {
            powerUpNode.setStyle("-fx-background-color: white;");
        }
        powerUpNodes.clear();
        for (PowerUp powerUp : powerUps) {
            Node n = getNodeByRowColumnIndex(powerUp.getY(), powerUp.getX(), field);
            n.setStyle("-fx-background-image: url(\"/img/powerup" + powerUp.getArt() + ".png\");");
            powerUpNodes.add(n);
        }
    }

    private void drawSnakes(IState state) {
        for(ISnake snake : state.getSnakes().values()) {
            ISnake snakeFromPreviousState = getSnake(snake.getId());
            if(snakeFromPreviousState == null) {
                snakes.add(snake);
                Node n = getNodeByRowColumnIndex(snake.getHead().getY(), snake.getHead().getX(), field);
                n.setStyle("-fx-background-color: "+snake.getColor()+";");
                continue;
            }
            snakes.remove(snakeFromPreviousState);
            snakes.add(snake);

            if(snakeFromPreviousState.getHead().equals(snake.getHead())) {
                // the snake shrank, i.e it was bitten
                if(snake.getPoints().size() < snakeFromPreviousState.getPoints().size()) {
                    int tailLengthToCut = snakeFromPreviousState.getPoints().size() - snake.getPoints().size();
                    int i = 0;
                    while(i < tailLengthToCut) {
                        IPoint tail = snakeFromPreviousState.getPoints().get(i);
                        getNodeByRowColumnIndex(tail.getY(), tail.getX(), field).setStyle("-fx-background-color: white;");
                        i++;
                    }
                }
                continue;
            }

            // normal movement
            if(snakeFromPreviousState.getPoints().size() == snake.getPoints().size()) {
                // delete tail
                IPoint tail = snakeFromPreviousState.getTail();
                getNodeByRowColumnIndex(tail.getY(), tail.getX(), field).setStyle("-fx-background-color: white;");
                // add new head
                IPoint newHead = snake.getHead();
                getNodeByRowColumnIndex(newHead.getY(), newHead.getX(), field).setStyle("-fx-background-color: "+snake.getColor()+";");
            }

            // the snake grew
            if(snakeFromPreviousState.getPoints().size() < snake.getPoints().size()) {
                // add new head
                IPoint newHead = snake.getHead();
                getNodeByRowColumnIndex(newHead.getY(), newHead.getX(), field).setStyle("-fx-background-color: "+snake.getColor()+";");
            }
        }
    }

}
