package client.gui;

import javafx.application.Application;
import javafx.collections.ObservableList;
import javafx.event.EventHandler;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Control;
import javafx.scene.control.Label;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import model.IPoint;
import model.IState;
import model.Direction;
import model.impl.Snake;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import util.Constants;

import java.util.Iterator;
import java.util.Map;

public class Board extends Application {

    private static final Logger logger = LogManager.getLogger(Board.class);
    private static OnLaunchedCallback onLaunchedCallback;
    private GridPane gridPane;
    private Direction direction = Direction.RIGHT;

    public static void launch(OnLaunchedCallback onLaunchedCallback1) {
        onLaunchedCallback = onLaunchedCallback1;
        launch(Board.class);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Snake");
        this.gridPane = new GridPane();

        for(int x = 0; x < Constants.BOARD_HEIGHT; x++) {
            for(int y = 0; y < Constants.BOARD_WIDTH; y++) {
                Label label = new Label();
                label.setMinSize(15, 15);
                label.setMaxSize(15, 15);
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

        HBox hBox = new HBox();
        hBox.getChildren().add(gridPane);


        Scene scene = new Scene(hBox, 1500, 540);
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

    public void draw(IState state) {
        logger.debug("Draw");

        // clear
        for(IPoint p : state.getToRemove()) {
            Node n = getNodeByRowColumnIndex(p.getY(), p.getX(), gridPane);
            n.setStyle("-fx-background-color: white;");
        }

        IPoint food = state.getFood();
        if(food != null) {
            Node n = getNodeByRowColumnIndex(food.getY(), food.getX(), gridPane);
            n.setStyle("-fx-background-color: red; -fx-background-radius: 25;");
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
