note
	description: "Summary description for {GAME}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	GAME

feature
	state: STATE

feature

	set_state(state_in: STATE)
		do
			state := state_in
		end

	get_state: STATE
		do
			Result := state
		end

	add_snake(id: INTEGER; character_representation_in: CHARACTER)
	-- Adds a new snake to the game
    -- @param id the id of the snake
    -- @param character_representation_in a character representing the snake, such as 'o', 'a' etc.
		require
			state.get_snakes.count <= 2
			id >= 0
		deferred
		ensure
			state.get_snakes.count = old state.get_snakes.count + 1
		end

	has_finished: BOOLEAN deferred end

	update_state(id: INTEGER; direction: STRING)
	-- Update the state of the game.
    -- @param id the id of the snake
    -- @param direction the new direction of the snake
		require
			id > 0 and id < 3
			direction.is_equal ("UP") or
			direction.is_equal ("DOWN") or
			direction.is_equal ("LEFT") or
			direction.is_equal ("RIGHT")
		local
			snake: SNAKE
			head: POINT
			flag: BOOLEAN
		do
			snake := state.get_snakes.at (id)
			if(snake.is_playing = true) then
				snake.set_direction (current.calculate_snake_direction (snake, direction))
				head := current.add_new_head (snake)
				if not (current.eats_food (snake, head)) then
					current.remove_snake_tail (snake, snake.get_length)
				end
				flag := current.eats_poison (snake, head)
				flag := current.eats_power_up (snake, head)
				flag := current.bites_itself_or_other_snake (snake)
				flag := current.collides_with_border (snake, head)
				current.check_timeouts (snake)
				place_poisons_and_power_ups
				update_game_result
			end
		end

	calculate_snake_direction(snake: SNAKE; direction: STRING): STRING
	-- Ensure the snake can't move in the opposite direction if it is longer than 1
	-- @param snake the snake
    -- @param direction the new direction
    -- @return the old direction if the snake wants to move in the opposite direction, else the new direction
		require
			snake.get_id >= 0 and snake.get_id <= 2
			direction.is_equal ("UP") or
			direction.is_equal ("DOWN") or
			direction.is_equal ("LEFT") or
			direction.is_equal ("RIGHT")
		deferred
		ensure
			Result.is_equal ("UP") or
			Result.is_equal ("DOWN") or
			Result.is_equal ("LEFT") or
			Result.is_equal ("RIGHT")
		end

	add_new_head(snake: SNAKE): POINT
	-- Adds a new head to the snake depending on its current direction
    -- @param snake the snake
    -- @return the new head of the snake
		require
			snake.get_id >= 0 and snake.get_id <= 2
		deferred
		ensure
			Result.get_x >= 0 AND Result.get_x <= 40
			Result.get_y >= 0 AND Result.get_y <= 20
			snake.get_length = old snake.get_length + 1
		end

	remove_snake_tail(snake: SNAKE; index: INTEGER)
	-- Removes the tail of the snake
    -- @param snake the snake
    -- @param index the cut-off index (index is the length of the to be removed tail)
		require
			snake.get_id >= 0 and snake.get_id <= 2
			index <= snake.get_length
		deferred
		end

	eats_food(snake: SNAKE; head: POINT): BOOLEAN
	-- Checks if the snake can eat food. If so, its speed and health level will increase.
    -- Check the protocol in the readme for more info.
    -- @param snake the snake
    -- @param head the head of the snake
    -- @return true if snake ate food, else false
		require
			snake.get_id >= 0 and snake.get_id <= 2
		deferred
		ensure
			(not Result) OR (snake.get_health > old snake.get_health)
		end

	eats_poison(snake: SNAKE; head: POINT): BOOLEAN
	-- Checks if the snake eats poison. If so, its speed or its health level decreases.
    -- Check the protocol in the readme for more info.
    -- @param snake the snake
    -- @param head the head of the snake
    -- @return true if the snake ate poison, else false
		require
			snake.get_id >= 0 and snake.get_id <= 2
		deferred
		ensure
			(not Result) OR (snake.get_health < old snake.get_health OR snake.get_speed <= old snake.get_speed)
		end

	eats_power_up(snake: SNAKE; head: POINT): BOOLEAN
	-- Checks if the snake eats a power-up. If so, its speed or its health level increases for a while.
    -- Check the protocol in the readme for more info.
    -- @param snake the snake
    -- @param head the head of the snake
    -- @return true if the snake ate a power-up, else false
		require
			snake.get_id >= 0 and snake.get_id <= 2
		deferred
		ensure
			(not Result) OR (snake.get_health > old snake.get_health OR snake.get_speed >= old snake.get_speed)
		end

	bites_itself_or_other_snake(snake: SNAKE): BOOLEAN
	-- Checks if a snake bites itself or another snake.
    -- If a snake bites itself (its length must be longer than 3) it dies
    -- If a snake bites another one their speed and health level change accordingly.
    -- Check the protocol in the readme for the details.
    -- @param snake the snake
    -- @return true if the snake bites ifself or another one, else false
		require
			snake.get_id >= 0 and snake.get_id <= 2
		deferred
		end

	collides_with_border(snake: SNAKE; head:POINT): BOOLEAN
	-- Checks if the snake collides with a border. If so, the snake immediately dies.
    -- @param snake the snake
    -- @param head the head of the snake
    -- @return true if the snake collides with a border, else false
		require
			snake.get_id >= 0 and snake.get_id <= 2
		deferred
		ensure
			(not Result) OR (snake.get_health = 0 AND snake.get_length = 0)
		end

	place_poisons_and_power_ups
	-- Add poisons and power-ups if possible (if the max number hasn't been reached yet)
		deferred
		ensure
			state.get_poisons.count <= 3 AND state.get_power_ups.count <= 2
		end

	check_timeouts(snake: SNAKE)
	-- Check if poisons and power-ups timeout. If so, they should be removed.
    -- Check also if power-up or biting influences for a snake timeout. If so, they should be removed.
    -- @param snake the snake
		require
			snake.get_id >= 0 and snake.get_id <= 2
		deferred
		end

	update_game_result
	-- Updates the elapsed time of the state
    -- Tries to elect a winner if possible. Check the readme for the details.
	deferred
	end

end
