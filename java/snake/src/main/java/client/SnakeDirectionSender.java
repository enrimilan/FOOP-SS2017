package client;

import model.ISnake;
import model.Mode;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.IOException;
import java.io.ObjectOutputStream;

public class SnakeDirectionSender implements Runnable {

    private static final Logger logger = LogManager.getLogger(SnakeDirectionSender.class);
    private boolean running = true;
    private Client client;
    private ObjectOutputStream out;

    public SnakeDirectionSender(Client client, ObjectOutputStream out) {
        this.client = client;
        this.out = out;
    }

    @Override
    public void run() {
        logger.debug("Start SnakeDirectionSender");
        try {
            while(running) {
                int speed = client.getSnake().getSpeed();
                Thread.sleep(600 - speed);
                if(client.getMode() == Mode.PLAYER) {
                    out.writeObject(client.getNextDirectionFromBoard());
                }
                else {
                    out.writeObject(client.getNextDirectionUsingAlgorithm());
                }
            }

        } catch (InterruptedException e) {
            logger.debug(e.getMessage());
        } catch (IOException e) {
            logger.debug(e.getMessage());
        }

    }

    public void stop() {
        logger.debug("Stop SnakeDirectionSender");
        running = false;
        try {
            out.close();
        } catch (IOException e) {
            logger.debug(e.getMessage());
        }
    }
}
