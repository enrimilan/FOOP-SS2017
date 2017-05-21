package client;

import model.impl.State;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.IOException;
import java.io.ObjectInputStream;

public class GameUpdateListener implements Runnable {

    private static final Logger logger = LogManager.getLogger(GameUpdateListener.class);
    private boolean running = true;
    private Client client;
    private ObjectInputStream in;

    public GameUpdateListener(Client client, ObjectInputStream in) {
        this.client = client;
        this.in = in;
    }

    @Override
    public void run() {
        logger.debug("Start GameUpdateListener");
        try {
            while(running) {
                State state = (State) in.readObject();
                client.onGameStateChanged(state);
                logger.debug("got state.");
            }
        } catch (IOException e) {
            logger.debug(e.getMessage());
        } catch (ClassNotFoundException e) {
            logger.fatal(e.getMessage());
        }
    }

    public void stop() {
        logger.debug("Stop GameUpdateListener");
        running = false;
        try {
            in.close();
        } catch (IOException e) {
            logger.debug(e.getMessage());
        }
    }
}
