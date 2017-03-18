package server;

import model.*;
import model.impl.Game;
import model.impl.State;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import util.Constants;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Server {

    private static final Logger logger = LogManager.getLogger(Server.class);
    private ExecutorService executor;
    private List<ClientHandler> clientHandlers = new CopyOnWriteArrayList<ClientHandler>();
    private ClientListener clientListener;
    private IGame game;

    public Server(IGame game) {
        this.game = game;
        this.executor = Executors.newCachedThreadPool();
    }

    private void start() throws IOException {
        logger.debug("Start server");
        this.clientListener = new ClientListener(new ServerSocket(Constants.PORT), this);
        executor.submit(clientListener);
        readFromStdIn();
    }

    private void stop() {
        logger.debug("Stop server");
        clientListener.stop();
        for(ClientHandler clientHandler : clientHandlers) {
            clientHandler.stop();
        }
        executor.shutdown();
    }

    private void readFromStdIn() {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine())  {
            String input = sc.nextLine();
            if(input.equals("stop")) {
                stop();
                break;
            }
        }
    }

    public synchronized void onClientJoined(Socket socket) {
        int id = socket.getPort();
        logger.debug("New client {}", id);
        game.addSnake(id);
        notifyClients();
    }

    public synchronized void onDirectionReceived(int id, Direction direction) {
        logger.debug("Received new direction {} from client {}", direction, id);
        game.updateState(id, direction);
        notifyClients();
    }

    private synchronized void notifyClients() {
        logger.debug("Notify clients with new state");
        for(ClientHandler clientHandler : clientHandlers) {
            clientHandler.notifyClient(game.getState());
        }
    }

    public List<ClientHandler> getClientHandlers() {
        return clientHandlers;
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        // inject implementations
        IState state = new State();
        IGame game = new Game(state);
        Server server = new Server(game);
        server.start();
    }
}
