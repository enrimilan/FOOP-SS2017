note
	description: "Summary description for {GAME}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	GAME

feature

	add_snake(id: INTEGER; character_representation_in: CHARACTER) deferred end

	has_finished: BOOLEAN deferred end

	get_state : STATE deferred end

	update_state(id: INTEGER; direction: STRING) deferred end

	calculate_snake_direction(snake: SNAKE; direction: STRING): STRING deferred end

	add_new_head(snake: SNAKE): POINT deferred end

	remove_snake_tail(snake: SNAKE; index: INTEGER) deferred end

	eats_food(snake: SNAKE; head: POINT): BOOLEAN deferred end

	eats_poison(snake: SNAKE; head: POINT): BOOLEAN deferred end

	eats_power_up(snake: SNAKE; head: POINT): BOOLEAN deferred end

	bites_itself_or_other_snake(snake: SNAKE): BOOLEAN deferred end

	collides_with_border(snake: SNAKE; head:POINT): BOOLEAN deferred end

	check_timeouts(snake: SNAKE) deferred end

	update_game_result: GAME deferred end

end
