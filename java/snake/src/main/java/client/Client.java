package client;

import client.gui.Board;
import client.gui.OnLaunchedCallback;
import model.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import util.Constants;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
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

    private SnakeAlgorithm snakeAlgorithm;
    private Direction lastDirection; // denotes the last direction of the snake

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

    public synchronized void onGameStateChanged(IState state) {
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

    public synchronized Direction getNextDirectionFromBoard() {
        return board.getNextDirection();
    }

    /* Author: Gruzdev Eugen */
    public synchronized Direction getNextDirectionUsingAlgorithm() {
        snakeAlgorithm = new SnakeAlgorithm(state, id, this);
       if(lastDirection == null){  // If the first direction is null (the game beginning for this snake)
            lastDirection = snakeAlgorithm.getFirstDirection();
            return lastDirection;
        } else {
            lastDirection = snakeAlgorithm.getNextSnakeDirection(lastDirection);
            return lastDirection;
        }
    }

    public synchronized ISnake getSnake() {
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
