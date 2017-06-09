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
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import util.Constants;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

public class Board extends Application {

    private static final Logger logger = LogManager.getLogger(Board.class);
    private static OnLaunchedCallback onLaunchedCallback;
    private GridPane field;
    private StringProperty healthString = new SimpleStringProperty("100");
    private StringProperty speedString = new SimpleStringProperty("100");
    private StringProperty timeString = new SimpleStringProperty();
    private StringProperty gameResultString = new SimpleStringProperty();
    private Direction direction = Direction.RIGHT;
    private IState lastState;

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
        logger.debug("Start drawing");
        clear(state);

        // drawSnakes
        for(ISnake snake : state.getSnakes().values()) {
            for (IPoint p : snake.getPoints()) {
                getNodeByRowColumnIndex(p.getY(), p.getX(), field).setStyle("-fx-background-color: " + snake.getColor() + ";");
            }
        }

        // draw food
        Food food = state.getFood();
        if(food != null) {
            logger.debug("Draw food of type {} ", food.getType());
            Node n = getNodeByRowColumnIndex(food.getY(), food.getX(), field);
            n.setStyle("-fx-background-image: url(\"/img/food"+food.getType()+".png\");");
        }

        // draw poisons
        for(Poison p : state.getPoisons()) {
            logger.debug("Draw poison of type {}", p.getType());
            Node n = getNodeByRowColumnIndex(p.getY(), p.getX(), field);
            n.setStyle("-fx-background-image: url(\"/img/poison" + p.getType() + ".png\");");
        }

        // draw power-ups
        for (PowerUp powerUp : state.getPowerUps()) {
            logger.debug("Draw power-up of type {} ({})", powerUp.getType().ordinal(), powerUp.getType());
            Node n = getNodeByRowColumnIndex(powerUp.getY(), powerUp.getX(), field);
            n.setStyle("-fx-background-image: url(\"/img/powerup" + powerUp.getType().ordinal() + ".png\");");
        }

        FutureTask<Void> task = new FutureTask<>(() -> {
            healthString.set("" + state.getSnakes().get(id).getHealth());
            speedString.set("" + state.getSnakes().get(id).getSpeed());
            long millis = Constants.GAME_DURATION - state.getTimeElapsed();
            timeString.set((millis / 1000) / 60 + ":" + (millis / 1000) % 60);
            String result = state.getResult(id);
            if (result != null) gameResultString.set(result);
            return null;
        });
        Platform.runLater(task);
        try {
            task.get();
            logger.debug("Updated info pane");
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace();
        }
        logger.debug("Finished drawing");
        lastState = state;
    }

    public Direction getNextDirection() {
        return direction;
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

        // time
        Label time = new Label();
        time.textProperty().bind(timeString);
        infoPane.add(time,4,0);

        // game result
        Label gameResult = new Label();
        gameResult.textProperty().bind(gameResultString);
        infoPane.add(gameResult, 5, 0);

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

    private Node getNodeByRowColumnIndex (final int y, final int x, GridPane gridPane) {
        if(y < 0 || y >= Constants.BOARD_HEIGHT || x < 0 || x >= Constants.BOARD_WIDTH) {
            throw new IllegalArgumentException(y + ", " + x + " are invalid coordinates");
        }
        ObservableList<Node> children = gridPane.getChildren();
        for (Node node : children) {
            if(GridPane.getRowIndex(node) == y && GridPane.getColumnIndex(node) == x) return node;
        }
        throw new IllegalArgumentException(y + ", " + x + " are invalid coordinates");
    }

    private void clear(IState state) {
        if(lastState != null) {

            logger.debug("clear food");
            Food food = lastState.getFood();
            if(lastState.getFood() != null) {
                if(!food.equals(state.getFood())) {
                    Node n = getNodeByRowColumnIndex(food.getY(), food.getX(), field);
                    n.setStyle("-fx-background-color: white;");
                }
            }

            logger.debug("clear poisons");
            for(Poison poison : lastState.getPoisons()) {
                if(!state.getPoisons().contains(poison)) {
                    getNodeByRowColumnIndex(poison.getY(), poison.getX(), field).setStyle("-fx-background-color: white;");
                }
            }

            logger.debug("clear power-ups");
            for(PowerUp powerUp : lastState.getPowerUps()) {
                if(!state.getPowerUps().contains(powerUp)) {
                    getNodeByRowColumnIndex(powerUp.getY(), powerUp.getX(), field).setStyle("-fx-background-color: white;");
                }
            }

            logger.debug("clear snakes");
            for(ISnake snake : lastState.getSnakes().values()) {
                ISnake newerSnake = state.getSnakes().get(snake.getId());
                for(IPoint p : snake.getPoints()) {
                    if(newerSnake != null && !newerSnake.getPoints().contains(p)) {
                        getNodeByRowColumnIndex(p.getY(), p.getX(), field).setStyle("-fx-background-color: white;");
                    }
                }
            }
        }
    }

}
