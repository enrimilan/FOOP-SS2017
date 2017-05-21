package client.gui;

import javafx.application.*;
import javafx.beans.property.*;
import javafx.collections.ObservableList;
import javafx.event.EventHandler;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Control;
import javafx.scene.control.Label;
import javafx.scene.image.*;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
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
    private GridPane gridPane;
    private GridPane infoPane;
    private Direction direction = Direction.RIGHT;

    public ISnake getSnake() {
        return snake;
    }

    public void setSnake(ISnake snake) {
        this.snake = snake;
    }

    private ISnake snake;

    StringProperty healthString = new SimpleStringProperty("100");
    StringProperty speedString = new SimpleStringProperty("100");
    StringProperty lenString = new SimpleStringProperty("1");


    public static void launch(OnLaunchedCallback onLaunchedCallback1) {
        onLaunchedCallback = onLaunchedCallback1;
        launch(Board.class);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Snake");

        //gather images
        Image heartImg = new Image(Board.class.getResourceAsStream("/img/heart.png"));
        Image speedImg = new Image(Board.class.getResourceAsStream("/img/speed.png"));



        //infopane
        this.infoPane = new GridPane();
        infoPane.setHgap(10);

        //health
        Label healthIcon = new Label();
        healthIcon.setMinSize(30, 30);
        healthIcon.setGraphic(new ImageView(heartImg));

        infoPane.add(healthIcon,0,0);

        Label healthValue = new Label();
        healthValue.setMinSize(30, 30);
        healthValue.textProperty().bind(healthString);
        infoPane.add(healthValue, 1, 0);

        // speed
        Label speedIcon = new Label();
        speedIcon.setMinSize(30, 30);
        speedIcon.setGraphic(new ImageView(speedImg));
        infoPane.add(speedIcon,2,0);

        Label speedValue = new Label();
        speedValue.setMinSize(30, 30);
        speedValue.textProperty().bind(speedString);
        infoPane.add(speedValue, 3, 0);





        this.gridPane = new GridPane();

        //gridPane.add(healthIcon,0,0);

        for(int x = 0; x < Constants.BOARD_HEIGHT; x++) {
            for(int y = 0; y < Constants.BOARD_WIDTH; y++) {
                Label label = new Label();
                label.setMinSize(20, 20);
                label.setMaxSize(20, 20);

                gridPane.add(label, y, x, 1, 1);
            }
        }

        for (Node n: gridPane.getChildren()) {
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

        gridPane.setStyle("-fx-background-color: white; -fx-border-color: black; -fx-padding: 2; -fx-hgap: 2; -fx-vgap: 2;");

        VBox vBox = new VBox();
        vBox.getChildren().add(infoPane);
        vBox.getChildren().add(gridPane);


        Scene scene = new Scene(vBox, 1500, 800);
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();

        scene.setOnKeyPressed(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent keyEvent) {
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
            }
        });

        onLaunchedCallback.onApplicationLaunched(this);
    }

    public void draw(IState state, int id) {
        logger.debug("Draw with stateinformation: snakes: "+state.getSnakes().size()+" id: "+id+" health: "+state.getSnakes().get(id).getHealth()+" speed: "+state.getSnakes().get(id).getSpeed());
        logger.debug("SNAKE POINTS:");
        for(ISnake snake : state.getSnakes().values()){
            String str = snake.getId()+": ";
            for(IPoint p : snake.getPoints()){
                str+=p.getX()+"/"+p.getY();
            }
            logger.debug(str);
        }

        // clear
        for(IPoint p : state.getToRemove()) {
            Node n = getNodeByRowColumnIndex(p.getY(), p.getX(), gridPane);
            n.setStyle("-fx-background-color: white;");
        }

        //draw food
        Food food = state.getFood();
        if(food != null) {
            Node n = getNodeByRowColumnIndex(food.getY(), food.getX(), gridPane);
            //n.setStyle("-fx-background-color: red; -fx-background-radius: 25;");
            logger.debug("Setting Food, type is: "+food.getArt());

            n.setStyle("-fx-background-image: url(\"/img/food"+food.getArt()+".png\");");

        }

        //draw poisons
        ArrayList<Poison> poison = (ArrayList<Poison>) state.getPoisons();
        if(!poison.isEmpty()) {
            for(Poison p : poison) {
                Node n = getNodeByRowColumnIndex(p.getY(), p.getX(), gridPane);
                //n.setStyle("-fx-background-color: red; -fx-background-radius: 25;");
                logger.debug("Setting Poison, type is: " + p.getArt());
                n.setStyle("-fx-background-image: url(\"/img/poison" + p.getArt() + ".png\");");
            }
        }

        //draw powerups
        ArrayList<PowerUp> powerups = (ArrayList<PowerUp>) state.getPowerups();
        if(!powerups.isEmpty()) {
            for(PowerUp p : powerups) {
                Node n = getNodeByRowColumnIndex(p.getY(), p.getX(), gridPane);
                //n.setStyle("-fx-background-color: red; -fx-background-radius: 25;");
                logger.debug("Setting Powerup, type is: " + p.getArt());
                n.setStyle("-fx-background-image: url(\"/img/powerup" + p.getArt() + ".png\");");
            }
        }

        Iterator entries = state.getSnakes().entrySet().iterator();
        while (entries.hasNext()) {
            Map.Entry thisEntry = (Map.Entry) entries.next();
            Snake snake = (Snake) thisEntry.getValue();
            for(IPoint p : snake.getPoints()) {
                Node n = getNodeByRowColumnIndex(p.getY(), p.getX(), gridPane);
                n.setStyle("-fx-background-color: "+snake.getColor()+";");

            }
        }

        logger.debug("set infopane");
        logger.debug("setting health to: "+state.getSnakes().get(id).getHealth());

            //TODO Workaround because of threading expception, revisit!
        Platform.runLater(
                () -> {
                    healthString.set("" + state.getSnakes().get(id).getHealth());
                    speedString.set("" + state.getSnakes().get(id).getSpeed());
                }
        );



    }

    private Node getNodeByRowColumnIndex (final int row, final int column, GridPane gridPane) {
        ObservableList<Node> children = gridPane.getChildren();
        for (Node node : children) {
            if(GridPane.getRowIndex(node) == row && GridPane.getColumnIndex(node) == column) {
                return node;
            }
        }
        return null;
    }

    public Direction getNextDirection() {
        return direction;
    }
}
