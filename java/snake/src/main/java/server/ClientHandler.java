package server;

import model.Direction;
import model.IState;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.*;
import java.net.Socket;

/**
 * Handles a new request (direction) received from a client
 */
public class ClientHandler implements Runnable {

    private static final Logger logger = LogManager.getLogger(ClientHandler.class);
    private boolean running = true;
    private Socket socket;
    private ObjectOutputStream out;
    private ObjectInputStream in;
    private Server server;
    private int clientId;

    public ClientHandler(Socket socket, Server server) throws IOException {
        this.socket = socket;
        this.out = new ObjectOutputStream(socket.getOutputStream());
        this.in = new ObjectInputStream(socket.getInputStream());
        this.server = server;
        this.clientId = socket.getPort();
    }

    @Override
    public void run() {
        logger.debug("Start new ClientHandler for client {}", clientId);
        try {
            while(running) {
                logger.debug("recv direction from client {}",clientId);
                Direction direction = (Direction) in.readObject();
                server.onDirectionReceived(clientId, direction);
            }
        } catch (IOException e) {
            logger.debug(e.getMessage());
        } catch (ClassNotFoundException e) {
            logger.fatal(e.getMessage());
        }
        server.getClientHandlers().remove(this);
        server.onClientLeft(clientId);
    }

    public void stop() {
        logger.debug("Stop ClientHandler for client {}", clientId);
        running = false;
        try {out.close();} catch (IOException e) {logger.debug(e.getMessage());}
        try {in.close();} catch (IOException e) {logger.debug(e.getMessage());}
        try {socket.close();} catch (IOException e) {logger.debug(e.getMessage());}
    }

    public void notifyClient(IState state) {
        logger.debug("Notify client {} with new state", clientId);
        try {
            out.reset();
            out.writeObject(state);
        } catch (IOException e) {
            logger.error(e.getMessage());
        }
    }

}