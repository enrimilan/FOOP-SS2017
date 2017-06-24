package server;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import static util.Constants.MAX_PLAYERS;

/**
 * Listens for players joining the server
 */
public class ClientListener implements Runnable {

    private static final Logger logger = LogManager.getLogger(ClientListener.class);
    private boolean running = true;
    private ServerSocket serverSocket;
    private ExecutorService executor;
    private Server server;

    public ClientListener(ServerSocket serverSocket, Server server) throws IOException {
        this.serverSocket = serverSocket;
        this.executor = Executors.newCachedThreadPool();
        this.server = server;
    }

    @Override
    public void run() {
        logger.debug("Start ClientListener");
        try {
            while(running) {
                Socket clientSocket = serverSocket.accept();
                ClientHandler clientHandler = new ClientHandler(clientSocket, server);
                server.getClientHandlers().add(clientHandler);
                executor.submit(clientHandler);
                server.onClientJoined(clientSocket);
                if(server.getGame().getState().getSnakes().values().size() == MAX_PLAYERS) {
                    // no more players can join, stop this listener.
                    stop();
                }
            }
        } catch (IOException e) {
            logger.debug(e.getMessage());
        }
    }

    public void stop() {
        logger.debug("Stop ClientListener");
        running = false;
        try {
            serverSocket.close();
        } catch (IOException e) {
            logger.debug(e.getMessage());
        }
        executor.shutdown();
    }

}
