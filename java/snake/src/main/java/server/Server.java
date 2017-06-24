package server;

import model.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import util.Constants;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Server {

    private static final Logger logger = LogManager.getLogger(Server.class);
    private ExecutorService executor;
    private List<ClientHandler> clientHandlers = new CopyOnWriteArrayList<ClientHandler>();
    private ClientListener clientListener;
    private AbstractGame game;

    public Server(AbstractGame game) {
        this.game = game;
        this.executor = Executors.newCachedThreadPool();
    }

    public synchronized void onClientJoined(Socket socket) {
        int id = socket.getPort();
        logger.debug("New client {}", id);
        game.addSnake(id);
        notifyClients();
    }

    public synchronized void onClientLeft(int id) {
        logger.debug("Client {} left", id);
        game.removeSnake(id);
        notifyClients();
    }

    public synchronized void onDirectionReceived(int id, Direction direction) {
        logger.debug("Received new direction {} from client {}", direction, id);
        IState state = game.updateState(id, direction);
        if(state != null) {
            notifyClients();
        }
        if(game.hasFinished()) {
            logger.debug("Game finished");
            stop();
        }
    }

    private void start() throws IOException {
        logger.debug("Start server");
        this.clientListener = new ClientListener(new ServerSocket(Constants.PORT), this);
        executor.submit(clientListener);
    }

    private void stop() {
        logger.debug("Stop server");
        clientListener.stop();
        for(ClientHandler clientHandler : clientHandlers) {
            clientHandler.stop();
        }
        executor.shutdown();
    }

    private void notifyClients() {
        logger.debug("Notify clients with new state");
        for(ClientHandler clientHandler : clientHandlers) {
            clientHandler.notifyClient(game.getState());
        }
    }

    public List<ClientHandler> getClientHandlers() {
        return clientHandlers;
    }

    public AbstractGame getGame() {
        return game;
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        // inject implementations
        IState state = Factory.createState();
        AbstractGame game = Factory.createGame(state);
        Server server = new Server(game);
        server.start();
    }
}
