package model;

public abstract class AbstractGame {

    protected IState state;

    public AbstractGame(IState state) {
        this.state = state;
    }

    /**
     * Adds a new snake to the game
     * @param id the id of the snake
     */
    public abstract void addSnake(int id);

    /**
     * Removes a snake from the game
     * @param id the id of the snake
     */
    public abstract void removeSnake(int id);

    public abstract IState getState();

    public abstract boolean hasFinished();

    /**
     * Update the state of the game.
     * @param id the id of the snake
     * @param direction the new direction of the snake
     * @return the new state
     */
    public IState updateState(int id, Direction direction) {
        ISnake snake = state.getSnakes().get(id);
        if(!canUpdateState(snake, id)) {
            return null;
        }
        snake.setDirection(calculateDirection(snake, direction));
        IPoint head = addNewHead(snake);

        if(!eatsFood(snake, head)) {
            // the snake didn't eat anything, normal movement
            removeSnakeTail(snake, 0);
        }
        eatsPoison(snake, head);
        eatsPowerUp(snake, head);
        bitesItselfOrOtherSnake(snake);
        collidesWithBorder(snake, head);
        checkTimeouts(snake);
        placePoisonAndPowerUpRandomly();
        updateGameResult();
        return state;
    }

    /**
     * Checks if the state can be updated for a given snake
     * @param snake the snake
     * @param id the id of the snake
     * @return false if the snake doesn't exist, isn't playing anymore or the game has finished, else true.
     */
    protected abstract boolean canUpdateState(ISnake snake, int id);

    /**
     * Ensure the snake can't move in the opposite direction if it is longer than 1
     * @param snake the snake
     * @param direction the new direction
     * @return the old direction if the snake wants to move in the opposite direction, else the new direction
     */
    protected abstract Direction calculateDirection(ISnake snake, Direction direction);

    /**
     * Adds a new head to the snake depending on it's current direction
     * @param snake the snake
     * @return the new head of the snake
     */
    protected abstract IPoint addNewHead(ISnake snake);

    /**
     * Removes the tail of the snake
     * @param snake the snake
     * @param i the cut-off index (i+1 is the length of the to be removed tail)
     */
    protected abstract void removeSnakeTail(ISnake snake, int i);

    /**
     * Checks if the snake can eat food. If so, its speed and health level will increase.
     * Check the protocol in the readme for more info.
     * @param snake the snake
     * @param head the head of the snake
     * @return true if snake ate food, else false
     */
    protected abstract boolean eatsFood(ISnake snake, IPoint head);

    /**
     * Checks if the snake eats poison. If so, its speed or its health level decreases.
     * Check the protocol in the readme for more info.
     * @param snake the snake
     * @param head  the head of the snake
     * @return true if the snake ate poison, else false
     */
    protected abstract boolean eatsPoison(ISnake snake, IPoint head);

    /**
     * Checks if the snake eats a power-up. If so, its speed or its health level increases for a while.
     * Check the protocol in the readme for more info.
     * @param snake the snake
     * @param head  the head of the snake
     * @return true if the snake ate a power-up, else false
     */
    protected abstract boolean eatsPowerUp(ISnake snake, IPoint head);

    /**
     * Checks if a snake bites itself or another snake.
     * If a snake bites itself (its length must be longer than 3) it dies
     * If a snake bites another one their speed and health level change accordingly.
     * Check the protocol in the readme for the details.
     * @param snake the snake
     * @return true if the snake bites ifself or another one, else false
     */
    protected abstract boolean bitesItselfOrOtherSnake(ISnake snake);

    /**
     * Checks if the snake collides with a border. If so, the snake immediately dies.
     * @param snake the snake
     * @param head the head of the snake
     * @return true if the snake collides with a border, else false
     */
    protected abstract boolean collidesWithBorder(ISnake snake, IPoint head);

    /**
     * Check if poisons and power-ups timeout. If so, they should be removed.
     * Check also if power-up or biting influences for a snake timeout. If so, they should be removed.
     * @param snake the snake
     */
    protected abstract void checkTimeouts(ISnake snake);

    /**
     * Add poisons and power-ups if possible (if the max number hasn't been reached yet)
     */
    protected abstract void placePoisonAndPowerUpRandomly();

    /**
     * Updates the elapsed time of the state
     * Tries to elect a winner if possible. Check the readme for the details.
     */
    protected abstract void updateGameResult();















}
