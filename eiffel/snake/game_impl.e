note
	description: "Summary description for {GAME_IMPL}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	GAME_IMPL
inherit
	GAME

create
	make

feature {NONE} -- Private variables
	state: STATE
	factory: FACTORY
	constants: CONSTANTS
	finished: BOOLEAN
	startingTime: DT_TIME
	clock: DT_SYSTEM_CLOCK

feature {ANY} -- Initialization

	make(state_in: STATE; newFactory: FACTORY)
		do
			create constants
			state := state_in
			factory := newFactory
			finished := false

			-- Obtaining current time
			create clock.make
			create startingTime.make_from_second_count (1) -- dummy value
			startingTime := clock.time_now
			--
		end

feature {ANY} -- Public features

	add_snake(id: INTEGER; character_representation_in: CHARACTER)
		-- Adding the snake and placing the food
		local
			point: POINT
			snake: SNAKE
			food: POINT
		do
			-- Adding the snake
			point := occupy_random_point
			snake := factory.create_snake (id, point, character_representation_in)
			state.get_snakes.extend (snake)

			-- Place food
			food := state.get_food
			if food.get_x = -1 then
				place_food
			end
		end

	has_finished: BOOLEAN
		do
			Result := finished
		end

	get_state : STATE
		do
			Result := state
		end

	update_state(id: INTEGER; direction: STRING)
		local
			snake: SNAKE
			head: POINT
			flag: BOOLEAN
			timeElapsed: DT_TIME_DURATION
			game: GAME
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
				-- Place poisons and power-ups
				if(state.get_poisons.count < constants.poison_max) then
					place_poison
				end
				if(state.get_power_ups.count < constants.power_up_max) then
					place_power_up
				end

				timeElapsed := clock.time_now - startingTime
				state.set_time_elapsed (timeElapsed.second_count)
				game := current.update_game_result
			end
		end

	calculate_snake_direction(snake: SNAKE; direction: STRING): STRING
		-- ensure that the snake cannot move in the opposite direction, if it's length is bigger than 1
		do
			Result := direction
			if (snake.get_length > 1) then
				if(direction.is_equal ("LEFT") and snake.get_direction.is_equal ("RIGHT")) then
					Result := "RIGHT"
				end
				if(direction.is_equal ("RIGHT") and snake.get_direction.is_equal ("LEFT")) then
					Result := "LEFT"
				end
				if(direction.is_equal ("UP") and snake.get_direction.is_equal ("DOWN")) then
					Result := "DOWN"
				end
				if(direction.is_equal ("DOWN") and snake.get_direction.is_equal ("UP")) then
					Result := "UP"
				end
			end
		end

	add_new_head(snake: SNAKE): POINT
		local
			head: POINT
			p: POINT
		do
			head := snake.get_head
			if(snake.get_direction.is_equal ("RIGHT")) then
				create p.make (head.get_x + 1, head.get_y)
				snake.add_head (p)
			end
			if(snake.get_direction.is_equal ("LEFT")) then
				create p.make (head.get_x - 1, head.get_y)
				snake.add_head (p)
			end
			if(snake.get_direction.is_equal ("UP")) then
				create p.make (head.get_x, head.get_y - 1)
				snake.add_head (p)
			end
			if(snake.get_direction.is_equal ("DOWN")) then
				create p.make (head.get_x, head.get_y + 1)
				snake.add_head (p)
			end
			head := snake.get_head
			occupy_point (head)
			Result := head
		end

	remove_snake_tail(snake: SNAKE; index: INTEGER)
		local
			toRemove: LINKED_LIST[POINT]
			point: POINT
		do
			create toRemove.make

			from snake.get_points.start
			until snake.get_points.exhausted
			loop
				toRemove.put_front (snake.get_points.item)
				snake.get_points.forth
			end

			point := toRemove.at (index)

			from
				toRemove.start
			until
				toRemove.exhausted
			loop
				point := toremove.at (index)
				toRemove.prune (point)
				make_point_available(point)
			end

			snake.get_points.wipe_out
			from toRemove.start
			until toRemove.exhausted
			loop
				snake.get_points.put_front (toRemove.item)
				toRemove.forth
			end
		end

	eats_food(snake: SNAKE; head: POINT): BOOLEAN
		local
			food: POINT
		do
			food := state.get_food
			if ((food.get_x = head.get_x) and (food.get_y = head.get_y)) then
				if(snake.get_speed + constants.food_speed > constants.max_speed) then
					snake.set_speed (constants.max_speed)
				else
					snake.set_speed (snake.get_speed + constants.food_speed)
				end
				snake.set_health (snake.get_health + constants.food_health)
				place_food
				Result := true
			else
				Result := false
			end
		end

	eats_poison(snake: SNAKE; head: POINT): BOOLEAN
		local
			poisons: LINKED_LIST[POISON]
			poison: POISON
			randomNumber: REAL
		do
			poisons := state.get_poisons

			from poisons.start
			until poisons.off
			loop
				poison := poisons.item
				if ((poison.get_x = head.get_x) and (poison.get_y = head.get_y)) then
					--Decrease health or speed randomly
					randomNumber := get_random_number
					if(randomNumber < 0.5)
					then
						snake.set_health (snake.get_health - constants.poison_health)
					else
						if (snake.get_speed - constants.poison_speed >= constants.min_speed) then
							snake.set_speed (snake.get_speed - constants.poison_speed)
						end
					end
					-- add poison to list to be removed
					state.remove_poison(poison)
					poisons.finish
					Result := true
				end
				poisons.forth
			end
			Result := false
		end

	eats_power_up(snake: SNAKE; head: POINT): BOOLEAN
		local
			powerUps: LINKED_LIST[POWERUP]
			powerUp : POWERUP
		do
			powerUps := state.get_power_ups
			from powerUps.start
			until powerUps.off
			loop
				powerUp := powerUps.item
				if ((powerUp.get_x = head.get_x) and (powerUp.get_y = head.get_y)) then
					if((powerUp.get_type.is_equal ("SPEED")) and (snake.get_speed + constants.power_up_speed <= constants.max_speed))
					then
						snake.set_speed (snake.get_speed + constants.power_up_speed)
						snake.get_influences.extend (factory.create_influence (constants.power_up_duration, constants.power_up_speed, 0, clock.time_now))
					else
						snake.set_health (snake.get_health + constants.power_up_health)
						snake.get_influences.extend (factory.create_influence (constants.power_up_duration, 0, constants.poison_health, clock.time_now))
					end
					-- remove powerUp from list
					state.remove_power_up (powerUp)
					powerUps.finish
					Result := true
				end
				powerUps.forth
			end
			Result := false
		end

	bites_itself_or_other_snake(snake: SNAKE): BOOLEAN
		local
			index: INTEGER
			snakePoints: LINKED_LIST[POINT]
			snakeHead: POINT
			snakePoint: POINT
			snakes: LINKED_LIST[SNAKE]
			bittenSnake: SNAKE
			r: REAL_64
			i: INTEGER
		do
			Result := false
			snakeHead := snake.get_head
			-- biting itself

			if (snake.get_length > 4) then
				snakePoints := snake.get_points
				from i := 1
				until i >=  (snakePoints.count - 1)
				loop
					snakePoint := snakePoints.at (i)
					if(snakeHead.get_x = snakePoint.get_x and snakeHead.get_y = snakePoint.get_y)
					then
						Current.remove_snake_tail (snake, 1)
						snake.set_health (0)
						snake.set_speed (0)
						snake.set_is_playing (false)
						Result := true
					end
					i := i + 1
				end
			end

			-- biting other snake
			snakes := state.get_snakes
			index := 0
			from snakes.start
			until snakes.off
			loop
				bittenSnake := snakes.item
				if not(bittenSnake.get_id = snake.get_id)	then
					--georgs rewritten code
					from bittenSnake.get_points.start
					until bittenSnake.get_points.exhausted
					loop

						if(snakeHead.get_x = bittenSnake.get_points.item.get_x and snakeHead.get_y = bittenSnake.get_points.item.get_y)then
							--snake bit bittensnake
							remove_snake_tail (bittenSnake, bittenSnake.get_length-index)

							--speed up bitersnake
							if (snake.get_speed + constants.bitting_speed > constants.max_speed)
							then
								snake.set_speed (constants.max_speed)
							else
								snake.set_speed (snake.get_speed+constants.bitting_speed)
							end

							--more health for biter:
							snake.set_health (snake.get_health + constants.bitting_health)

							--alter bitten snake
							if bittenSnake.get_length=0 then
								--snake got bitten in head, it is kill
								bittenSnake.set_health (0)
								bittenSnake.set_speed (0)
								bittenSnake.set_is_playing (false)
							else
								r := (snake.get_length / bittenSnake.get_length) * constants.bitting_health
								bittenSnake.set_health (bittenSnake.get_health - r.rounded)
							end
						end
						index := index+1
						bittenSnake.get_points.forth
					end
				end
				snakes.forth
			end
		end

	collides_with_border(snake: SNAKE; head:POINT): BOOLEAN
		do
			Result := false
			if (head.get_x < 0 or head.get_x >= (constants.board_width) or head.get_y < 0 or head.get_y >= (constants.board_height))
			then
				remove_snake_tail(snake, 1)
				snake.set_health (0)
				snake.set_speed (0)
				snake.set_is_playing(false)
				Result := true
			end
		end

	check_timeouts(snake: SNAKE)
		local
			poisons: LINKED_LIST[POISON]
			poison: POISON
			powerUps: LINKED_LIST[POWERUP]
			powerUp: POWERUP
			influences: LINKED_LIST[INFLUENCE]
			influence: INFLUENCE
			difference: DT_TIME_DURATION
			itemNr: INTEGER
		do
			-- Check for timeouts for poisons
			create poisons.make
			poisons.copy (state.get_poisons)
			itemNr := 0
			from poisons.start
			until poisons.exhausted
			loop
				poison := poisons.item
				difference := clock.time_now - poison.get_time_placed
				if (difference.second_count >= constants.max_artifact_time)
				then
					state.remove_poison (poison)
					make_point_available(poison.get_poison_point)

				end
				poisons.forth
				itemNr := itemNr + 1
			end

			-- Check for timeouts for powerUps
			powerUps := state.get_power_ups
			itemNr := 0
			from powerUps.start
			until powerUps.exhausted
			loop
				powerUp := powerUps.item
				difference := clock.time_now - powerUp.get_time_placed
				if (difference.second_count >= constants.max_artifact_time)
				then
					state.remove_power_up (powerUp)
					make_point_available(powerUp.get_power_up_point)

				end
				powerUps.forth
				itemNr := itemNr + 1
			end

			-- Check for timeouts for influences
			influences := snake.get_influences
			itemNr := 0
			from influences.start
			until influences.off
			loop
				influence := influences.item
				difference := clock.time_now - influence.get_start_time
				if(difference.second_count >= influence.get_duration)
				then
					if (snake.get_speed - influence.get_speed < constants.min_speed)
					then snake.set_speed (constants.min_speed)
					else snake.set_speed (snake.get_speed - influence.get_speed)
					end
					snake.set_health (snake.get_health - influence.get_health)
					influences.remove
					influences.finish
				end
				influences.forth
				itemNr := itemNr + 1
			end
		end

	update_game_result: GAME
		local
			snakesPlayingNumber: INTEGER
			snakesPlaying: LINKED_LIST[SNAKE]
			greatestLength: INTEGER
			longestSnake: SNAKE
			snake: SNAKE
		do
			snakesPlayingNumber := state.get_snakes.count
			greatestLength := 0
			-- Snake that lost while playing
			snakesPlaying := state.get_snakes
			from snakesPlaying.start
			until snakesPlaying.off
			loop
				snake := snakesPlaying.item
				if (snake.get_health = 0 or snake.get_length = 0)
				then
					snake.set_is_playing (false)
					snakesPlayingNumber := snakesPlayingNumber - 1
				else
					if(snake.get_length > greatestLength)
					then
						greatestLength := snake.get_length
					end
				end
				snakesPlaying.forth
			end

			-- If all are out and only one remains playing
			if(state.get_snakes.count = constants.max_players and snakesPlaying.count = 1)
			then
				snakesPlaying := state.get_snakes
				from snakesPlaying.start
				until snakesPlaying.off
				loop
					snake := snakesPlaying.item
					if(snake.is_playing = true)
					then
						state.set_results ("Player " + snake.get_id.out + " won")
						snake.set_is_playing (false)
						finished := true
						Result := current
					end
				end
			end

			-- Time is up, elect winner
			if(state.get_time_elapsed >= constants.game_duration)
			then
				state.set_time_elapsed (constants.game_duration)
				finished := true
				snakesPlaying := state.get_snakes
				from snakesPlaying.start
				until snakesPlaying.off
				loop
					snake := snakesPlaying.item
					if(snake.is_playing = true and snake.get_length = greatestLength)
					then
						if (longestSnake = void)
						then longestSnake := snake
						else state.set_results ("It is draw")
							Result := current
						end
					end
				end
				if(longestSnake /= void)
				then state.set_results ("Player " + longestSnake.get_id.out + " won")
					 Result := current
				end
			end
			Result := current
		end

feature {NONE} -- Private features

	place_food
		do
			state.set_food (occupy_random_point)
		end

	place_poison
		local
			poison: POISON
			actualTime: DT_TIME
		do
			poison := factory.create_poison (occupy_random_point)

			create actualTime.make_from_second_count (1) -- dummy value
			actualTime := clock.time_now
			poison.set_time_placed (actualTime)

			state.add_poison (poison)

		end

	place_power_up
		local
			powerUp: POWERUP
			randomNr: REAL
			type: STRING
			actualTime: DT_TIME
		do
			powerUp := factory.create_powerup (occupy_random_point)

			randomNr := get_random_number
			if randomNr > 0.5
			then type := "SPEED"
			else type := "HEALTH"
			end
			powerUp.set_type (type)

			create actualTime.make_from_second_count (1) -- dummy value
			actualTime := clock.time_now
			powerUp.set_time_placed (actualTime)

			state.add_power_up(powerUp)
		end

	make_point_available(point: POINT)
		do
			if not(state.get_available_points.has (point))
			then
				if((point.get_x >= 0 and point.get_x <= (constants.board_width)) and
				  (point.get_y >= 0 and point.get_y <= (constants.board_height)))
				then
					state.get_available_points.extend (point)
				end
			end
		end

	get_random_number: REAL
		local
			rn2: RANDOM
		do
			create rn2.make
			Result := rn2.real_item
		end

	occupy_point(point: POINT)
		do
			state.remove_available_point (point)
		end

	occupy_random_point: POINT
		local
			p: POINT
			avaliablePoints: LINKED_LIST[POINT]
			number: INTEGER
			rn: RANDOM_NUMBERS
		do
			create p.make (0,0)
			avaliablePoints := state.get_available_points
			create rn.make
			number := rn.random_integer \\ (avaliablePoints.count) + 1
			p := avaliablePoints.at (number)
			avaliablePoints.go_i_th (number)
			avaliablePoints.remove
			Result := p
		end

end
