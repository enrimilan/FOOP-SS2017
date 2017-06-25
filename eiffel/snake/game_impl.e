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
			state.getsnakes.extend (snake)

			-- Place food
			food := state.getfood
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
			snake := state.getsnakes.at (id)
			if(snake.isplaying = true) then
				snake.setdirection (current.calculate_snake_direction (snake, direction))
				head := current.add_new_head (snake)
				if not (current.eats_food (snake, head)) then
					current.remove_snake_tail (snake, snake.getlength)
				end
				flag := current.eats_poison (snake, head)
				flag := current.eats_power_up (snake, head)
				flag := current.bites_itself_or_other_snake (snake)
				flag := current.collides_with_border (snake, head)
				current.check_timeouts (snake)
				-- Place poisons and power-ups
				if(state.getposions.count < constants.poison_max) then
					place_poison
				end
				if(state.getpowerups.count < constants.power_up_max) then
					place_power_up
				end

				timeElapsed := clock.time_now - startingTime
				state.settimeelapsed (timeElapsed.second_count)
				game := current.update_game_result
			end
		end

	calculate_snake_direction(snake: SNAKE; direction: STRING): STRING
		-- ensure that the snake cannot move in the opposite direction, if it's length is bigger than 1
		do
			Result := direction
			if (snake.getlength > 1) then
				if(direction.is_equal ("LEFT") and snake.getdirection.is_equal ("RIGHT")) then
					Result := "RIGHT"
				end
				if(direction.is_equal ("RIGHT") and snake.getdirection.is_equal ("LEFT")) then
					Result := "LEFT"
				end
				if(direction.is_equal ("UP") and snake.getdirection.is_equal ("DOWN")) then
					Result := "DOWN"
				end
				if(direction.is_equal ("DOWN") and snake.getdirection.is_equal ("UP")) then
					Result := "UP"
				end
			end
		end

	add_new_head(snake: SNAKE): POINT
		local
			head: POINT
			p: POINT
		do
			head := snake.gethead
			if(snake.getdirection.is_equal ("RIGHT")) then
				create p.make (head.get_x + 1, head.get_y)
				snake.addhead (p)
			end
			if(snake.getdirection.is_equal ("LEFT")) then
				create p.make (head.get_x - 1, head.get_y)
				snake.addhead (p)
			end
			if(snake.getdirection.is_equal ("UP")) then
				create p.make (head.get_x, head.get_y - 1)
				snake.addhead (p)
			end
			if(snake.getdirection.is_equal ("DOWN")) then
				create p.make (head.get_x, head.get_y + 1)
				snake.addhead (p)
			end
			head := snake.gethead
			occupy_point (head)
			Result := head
		end

	remove_snake_tail(snake: SNAKE; index: INTEGER)
		local
			toRemove: LINKED_LIST[POINT]
			point: POINT
		do
			create toRemove.make

			from snake.getpoints.start
			until snake.getpoints.exhausted
			loop
				toRemove.put_front (snake.getpoints.item)
				snake.getpoints.forth
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

			snake.getpoints.wipe_out
			from toRemove.start
			until toRemove.exhausted
			loop
				snake.getpoints.put_front (toRemove.item)
				toRemove.forth
			end
		end

	eats_food(snake: SNAKE; head: POINT): BOOLEAN
		local
			food: POINT
		do
			food := state.getfood
			if ((food.get_x = head.get_x) and (food.get_y = head.get_y)) then
				if(snake.getspeed + constants.food_speed > constants.max_speed) then
					snake.setspeed (constants.max_speed)
				else
					snake.setspeed (snake.getspeed + constants.food_speed)
				end
				snake.sethealth (snake.gethealth + constants.food_health)
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
			poisons := state.getposions

			from poisons.start
			until poisons.off
			loop
				poison := poisons.item
				if ((poison.get_x = head.get_x) and (poison.get_y = head.get_y)) then
					--Decrease health or speed randomly
					randomNumber := get_random_number
					if(randomNumber < 0.5)
					then
						snake.sethealth (snake.gethealth - constants.poison_health)
					else
						if (snake.getspeed - constants.poison_speed >= constants.min_speed) then
							snake.setspeed (snake.getspeed - constants.poison_speed)
						end
					end
					-- add poison to list to be removed
					state.removepoison(poison)
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
			powerUps := state.getpowerups
			from powerUps.start
			until powerUps.off
			loop
				powerUp := powerUps.item
				if ((powerUp.get_x = head.get_x) and (powerUp.get_y = head.get_y)) then
					if((powerUp.gettype.is_equal ("SPEED")) and (snake.getspeed + constants.power_up_speed <= constants.max_speed))
					then
						snake.setspeed (snake.getspeed + constants.power_up_speed)
						snake.getinfluences.extend (factory.create_influence (constants.power_up_duration, constants.power_up_speed, 0, clock.time_now))
					else
						snake.sethealth (snake.gethealth + constants.power_up_health)
						snake.getinfluences.extend (factory.create_influence (constants.power_up_duration, 0, constants.poison_health, clock.time_now))
					end
					-- remove powerUp from list
					state.removepowerup (powerUp)
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
			snakeHead := snake.gethead
			-- biting itself

			if (snake.getlength > 4) then
				snakePoints := snake.getpoints
				from i := 1
				until i >=  (snakePoints.count - 1)
				loop
					snakePoint := snakePoints.at (i)
					if(snakeHead.get_x = snakePoint.get_x and snakeHead.get_y = snakePoint.get_y)
					then
						Current.remove_snake_tail (snake, snake.getlength)
						snake.sethealth (0)
						snake.setspeed (0)
						snake.setisplaying (false)
						Result := true
					end
					i := i + 1
				end
			end

			-- biting other snake
			snakes := state.getsnakes
			index := 0
			from snakes.start
			until snakes.off
			loop
				bittenSnake := snakes.item
				if not(bittenSnake.getid = snake.getid)	then
					--georgs rewritten code
					from bittenSnake.getpoints.start
					until bittenSnake.getpoints.exhausted
					loop

						if(snakeHead.get_x = bittenSnake.getpoints.item.get_x and snakeHead.get_y = bittenSnake.getpoints.item.get_y)then
							--snake bit bittensnake
							remove_snake_tail (bittenSnake, bittenSnake.getlength-index)

							--speed up bitersnake
							if (snake.getspeed + constants.bitting_speed > constants.max_speed)
							then
								snake.setspeed (constants.max_speed)
							else
								snake.setspeed (snake.getspeed+constants.bitting_speed)
							end

							--more health for biter:
							snake.sethealth (snake.gethealth + constants.bitting_health)

							--alter bitten snake
							if bittenSnake.getlength=0 then
								--snake got bitten in head, it is kill
								bittenSnake.sethealth (0)
								bittenSnake.setspeed (0)
								bittenSnake.setisplaying (false)
							else
								r := (snake.getlength / bittenSnake.getlength) * constants.bitting_health
								bittenSnake.sethealth (bittenSnake.gethealth - r.rounded)
							end
						end
						index := index+1
						bittenSnake.getpoints.forth
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
				snake.sethealth (0)
				snake.setspeed (0)
				snake.setisplaying(false)
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
			poisons.copy (state.getposions)
			itemNr := 0
			from poisons.start
			until poisons.exhausted
			loop
				poison := poisons.item
				difference := clock.time_now - poison.gettimeplaced
				if (difference.second_count >= constants.max_artifact_time)
				then
					state.removepoison (poison)
					make_point_available(poison.getpoisonpoint)

				end
				poisons.forth
				itemNr := itemNr + 1
			end

			-- Check for timeouts for powerUps
			powerUps := state.getpowerups
			itemNr := 0
			from powerUps.start
			until powerUps.exhausted
			loop
				powerUp := powerUps.item
				difference := clock.time_now - powerUp.gettimeplaced
				if (difference.second_count >= constants.max_artifact_time)
				then
					state.removepowerup (powerUp)
					make_point_available(powerUp.getpoweruppoint)

				end
				powerUps.forth
				itemNr := itemNr + 1
			end

			-- Check for timeouts for influences
			influences := snake.getinfluences
			itemNr := 0
			from influences.start
			until influences.off
			loop
				influence := influences.item
				difference := clock.time_now - influence.getstarttime
				if(difference.second_count >= influence.getduration)
				then
					if (snake.getspeed - influence.getspeed < constants.min_speed)
					then snake.setspeed (constants.min_speed)
					else snake.setspeed (snake.getspeed - influence.getspeed)
					end
					snake.sethealth (snake.gethealth - influence.gethealth)
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
			snakesPlayingNumber := state.getsnakes.count
			greatestLength := 0
			-- Snake that lost while playing
			snakesPlaying := state.getsnakes
			from snakesPlaying.start
			until snakesPlaying.off
			loop
				snake := snakesPlaying.item
				if (snake.gethealth = 0 or snake.getlength = 0)
				then
					snake.setisplaying (false)
					snakesPlayingNumber := snakesPlayingNumber - 1
				else
					if(snake.getlength > greatestLength)
					then
						greatestLength := snake.getlength
					end
				end
				snakesPlaying.forth
			end

			-- If all are out and only one remains playing
			if(state.getsnakes.count = constants.max_players and snakesPlaying.count = 1)
			then
				snakesPlaying := state.getsnakes
				from snakesPlaying.start
				until snakesPlaying.off
				loop
					snake := snakesPlaying.item
					if(snake.isplaying = true)
					then
						state.setresults ("Player " + snake.getid.out + " won")
						snake.setisplaying (false)
						finished := true
						Result := current
					end
				end
			end

			-- Time is up, elect winner
			if(state.gettimeelapsed >= constants.game_duration)
			then
				state.settimeelapsed (constants.game_duration)
				finished := true
				snakesPlaying := state.getsnakes
				from snakesPlaying.start
				until snakesPlaying.off
				loop
					snake := snakesPlaying.item
					if(snake.isplaying = true and snake.getlength = greatestLength)
					then
						if (longestSnake = void)
						then longestSnake := snake
						else state.setresults ("It is draw")
							Result := current
						end
					end
				end
				if(longestSnake /= void)
				then state.setresults ("Player " + longestSnake.getid.out + " won")
					 Result := current
				end
			end
			Result := current
		end

feature {NONE} -- Private features

	place_food
		do
			state.setfood (occupy_random_point)
		end

	place_poison
		local
			poison: POISON
			actualTime: DT_TIME
		do
			poison := factory.create_poison (occupy_random_point)

			create actualTime.make_from_second_count (1) -- dummy value
			actualTime := clock.time_now
			poison.settimeplaced (actualTime)

			state.addpoison (poison)

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
			powerUp.settype (type)

			create actualTime.make_from_second_count (1) -- dummy value
			actualTime := clock.time_now
			powerUp.settimeplaced (actualTime)

			state.addpowerup(powerUp)
		end

	make_point_available(point: POINT)
		do
			if not(state.getavaliablepoints.has (point))
			then
				if((point.get_x >= 0 and point.get_x <= (constants.board_width)) and
				  (point.get_y >= 0 and point.get_y <= (constants.board_height)))
				then
					state.getavaliablepoints.extend (point)
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
			state.removeavaliablepoint (point)
		end

	occupy_random_point: POINT
		local
			p: POINT
			avaliablePoints: LINKED_LIST[POINT]
			number: INTEGER
			rn: RANDOM_NUMBERS
		do
			create p.make (0,0)
			avaliablePoints := state.getavaliablepoints
			create rn.make
			number := rn.random_integer \\ (avaliablePoints.count) + 1
			p := avaliablePoints.at (number)
			avaliablePoints.go_i_th (number)
			avaliablePoints.remove
			Result := p
		end

end
