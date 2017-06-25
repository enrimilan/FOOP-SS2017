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

	add_snake(id: INTEGER; character_representation_in: CHARACTER) deferred end

	has_finished: BOOLEAN deferred end

	get_state : STATE deferred end

	update_state(id: INTEGER; direction: STRING)
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

	calculate_snake_direction(snake: SNAKE; direction: STRING): STRING deferred end

	add_new_head(snake: SNAKE): POINT deferred end

	remove_snake_tail(snake: SNAKE; index: INTEGER) deferred end

	eats_food(snake: SNAKE; head: POINT): BOOLEAN deferred end

	eats_poison(snake: SNAKE; head: POINT): BOOLEAN deferred end

	eats_power_up(snake: SNAKE; head: POINT): BOOLEAN deferred end

	bites_itself_or_other_snake(snake: SNAKE): BOOLEAN deferred end

	collides_with_border(snake: SNAKE; head:POINT): BOOLEAN deferred end

	place_poisons_and_power_ups deferred end

	check_timeouts(snake: SNAKE) deferred end

	update_game_result deferred end

end
