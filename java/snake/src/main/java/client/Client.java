package client;

import client.gui.Board;
import client.gui.OnLaunchedCallback;
import model.Direction;
import model.ISnake;
import model.IState;
import model.Mode;
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
        board.draw(state,this.id);
    }

    public Direction getNextDirectionFromBoard() {
        return board.getNextDirection();
    }

    public Direction getNextDirectionUsingAlgorithm() {
        //TODO implement
        Direction direction = Direction.RIGHT;
        return direction;
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
