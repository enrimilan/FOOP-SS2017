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

	add_snake(id: INTEGER)
		-- Adding the snake and placing the food
		local
			point: POINT
			snake: SNAKE
			food: POINT
		do
			-- Adding the snake
			point := occupyRandomPoint
			snake := factory.create_snake (id, point)
			state.getsnakes.extend (snake)

			-- Place food
			food := state.getfood
			if food.get_x = -1 then
				placeFood
			end
		end

	bitesItselfOrOtherSnake(snake: SNAKE): BOOLEAN
		local
			index: INTEGER
			speedGain:INTEGER
			snakePoints: LINKED_LIST[POINT]
			snakeHead: POINT
			snakePoint: POINT
			snakes: LINKED_LIST[SNAKE]
			bittenSnake: SNAKE
			r: REAL_64
			i: INTEGER
		do
			-- biting itself
			if (snake.getlength > 3) then
				snakePoints := snake.getpoints
				snakeHead := snake.gethead
				from i := 1
				until i >=  (snakePoints.count - 1)
				loop
					snakePoint := snakePoints.at (i)
					if(snakeHead.get_x = snakePoint.get_x and snakeHead.get_y = snakePoint.get_y)
					then
						Current.removesnaketail (snake, snake.getlength)
						snake.sethealth (0)
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
				if not(bittenSnake.getid = snake.getid)
				then
					index := bittenSnake.getpoints.index_of (snake.gethead, 1)
					if not (index = 0)
					then
						if (snake.getspeed + constants.bitting_speed > constants.max_speed)
						then
							speedGain := constants.max_speed - snake.getspeed
						else
							speedGain := constants.bitting_speed
						end
						snake.getinfluences.extend (factory.create_influence (constants.bitting_duration, speedGain, constants.bitting_health, clock.time_now))
						snake.setspeed (snake.getspeed + speedGain)
						snake.sethealth (snake.gethealth + constants.bitting_health)
						r := (snake.getlength / bittenSnake.getlength) * constants.bitting_health
						bittenSnake.sethealth (bittenSnake.gethealth - r.rounded)
						current.removesnaketail (bittenSnake, index)
						current.occupypoint (snake.gethead)
						Result := true
					end
				end
				snakes.forth
			end
			Result := false
		end

	eatsFood(snake: SNAKE; head: POINT): BOOLEAN
		local
			food: POINT
		do
--			print("CHECKING FOODEAT: ")
--			print("Food at: ")
--			print(state.getfood.get_x)
--			print("/")
--			print(state.getfood.get_y)
--			print("%NSnake at: ")
--			print(head.get_x)
--			print("/")
--			print(head.get_y)
			food := state.getfood
			if ((food.get_x = head.get_x) and (food.get_y = head.get_y)) then
			--	print("FOOD EATEN")
				if(snake.getspeed + constants.food_speed > constants.max_speed) then
					snake.setspeed (constants.max_speed)
				else snake.setspeed (snake.getspeed + constants.food_speed)
				end
				snake.sethealth (snake.gethealth + constants.food_health)
				placeFood
				Result := true
			else
				Result := false
			end
		end

	eatsPoison(snake: SNAKE; head: POINT): BOOLEAN
		local
			poisons: LINKED_LIST[POISON]
			poison_to_remove: POISON
			poison: POISON
			itemNr: INTEGER
			randomNumber: REAL
			toRet: BOOLEAN
		do
			toRet := false
			poisons := state.getposions
			itemNr := 1

			from poisons.start
			until poisons.off
			loop
				poison := poisons.item
				if ((poison.get_x = head.get_x) and (poison.get_y = head.get_y)) then
					--Decrease health or speed randomly
					randomNumber := getRandomNumber
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
					toRet := true
				end
				poisons.forth
				itemNr := itemNr + 1
			end
			if toRet /= true then
				Result := false
			else
				Result := true
			end
			--TODO remove poison at poisonToRemove.



		end

	eatsPowerUp(snake: SNAKE; head: POINT): BOOLEAN
		local
			powerUps: LINKED_LIST[POWERUP]
			removeList: LINKED_LIST[POWERUP]
			powerUp : POWERUP
			itemNr: INTEGER
		do
			powerUps := state.getpowerups
			itemNr := 0
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
					removeList := state.getpowerups
					removeList.go_i_th (itemNr)
					removeList.remove
					Result := true
				end
				powerUps.forth
				itemNr := itemNr + 1
			end
			Result := false
		end

	collidesWithBorder(snake: SNAKE; head:POINT): BOOLEAN
		do
			if (head.get_x < 0 or head.get_x > (constants.board_width-constants.cell_side_length) or head.get_y < 0 or head.get_y > (constants.board_height-constants.cell_side_length))
			then
				--io.put_string ("GAME_IMPL.collidesWithBorderI: AM HERE")
				removeSnakeTail(snake, snake.getlength)
				snake.sethealth (0)
				Result := true
			end
			Result := false
		end

	removeSnakeTail(snake: SNAKE; index: INTEGER)
		local
			toRemove: LINKED_LIST[POINT]
			point: POINT
			i: INTEGER
		do
			toRemove := snake.getpoints
			from
				i := 1
			until
				i >= index+1
			loop
				point := toRemove.at (i)
				toRemove.go_i_th (i)
				toRemove.remove
				makePointAvailable(point)
				i := i + 1
			end
		end

	calculateSnake(snake: SNAKE; direction: STRING): STRING
		-- ensure that the snake cannot move in the opposite direction, if it's length is bigger than 1
		do
			if (snake.getlength > 1)
			then
				if(direction.is_equal ("LEFT") and snake.getdirection.is_equal ("RIGHT"))
				then
					Result := "RIGHT"
				end
				if(direction.is_equal ("RIGHT") and snake.getdirection.is_equal ("LEFT"))
					then
						Result := "LEFT"
					end
				if(direction.is_equal ("UP") and snake.getdirection.is_equal ("DOWN"))
					then
						Result := "DOWN"
					end
				if(direction.is_equal ("DOWN") and snake.getdirection.is_equal ("UP"))
					then
						Result := "UP"
					end
			end
			-- should never be reached
			Result := direction
		end

	checkTimeouts(snake: SNAKE)
		local
			-- poisons
			poisons: LINKED_LIST[POISON]
			poison: POISON
			removeListPoisons: LINKED_LIST[POISON]
			-- powerUps
			powerUps: LINKED_LIST[POWERUP]
			powerUp: POWERUP
			removeListPowerUps: LINKED_LIST[POWERUP]
			-- influences
			influences: LINKED_LIST[INFLUENCE]
			influence: INFLUENCE
			removeListInfluences: LINKED_LIST[INFLUENCE]
			-- time
			difference: DT_TIME_DURATION
			itemNr: INTEGER
		do
			-- Check for timeouts for poisons
			create poisons.make
			--poisons.fill(state.getposions)
			poisons.copy (state.getposions)
			itemNr := 0
			from poisons.start
			until poisons.off
			loop
				poison := poisons.item
				difference := clock.time_now - poison.gettimeplaced
				if (difference.second_count >= constants.max_artifact_time)
				then
					-- remove poison from list
					-- TODO!
					--makePointAvailable(poison.getpoisonpoint)
				end
				poisons.forth
				itemNr := itemNr + 1
			end

			-- Check for timeouts for powerUps
			powerUps := state.getpowerups
			itemNr := 0
			from powerUps.start
			until powerUps.off
			loop
				powerUp := powerUps.item
				difference := clock.time_now - powerUp.gettimeplaced
				if (difference.second_count >= constants.max_artifact_time)
				then
					-- remove poison from list
					-- TODO!
	--				makePointAvailable(powerUp.getpoweruppoint)
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
					-- remove Influence
					-- TODO!
				end
				powerUps.forth
				itemNr := itemNr + 1
			end

	--		io.put_string ("I AM HERE")
		end

	update_state(id: INTEGER; direction: STRING)
		local
			snake: SNAKE
			head: POINT
			x: INTEGER
			y: INTEGER
			p: POINT
			rand: INTEGER_64
			flag: BOOLEAN
			timeElapsed: DT_TIME_DURATION
			game: GAME
		do
			snake := state.getsnakes.at (id)
			snake.setdirection (current.calculatesnake (snake, direction))

			if
				(snake.getlength > 1)
			then
				print("break")
			end

			--NEW SNAKE HEAD
			head := snake.gethead
			if(snake.getdirection.is_equal ("RIGHT"))
				then
					x := head.get_x + constants.cell_side_length
					y := head.get_y
					create p.make (x, y)
					snake.addhead (p)
				end

			if(snake.getdirection.is_equal ("LEFT"))
				then
					x := head.get_x - constants.cell_side_length
					y := head.get_y
					create p.make (x, y)
					snake.addhead (p)
				end

			if(snake.getdirection.is_equal ("UP"))
				then
					x := head.get_x
					y := head.get_y - constants.cell_side_length
					create p.make (x, y)
					snake.addhead (p)
				end

			if(snake.getdirection.is_equal ("DOWN"))
				then
					x := head.get_x
					y := head.get_y + constants.cell_side_length
					create p.make (x, y)
					snake.addhead (p)
				end

			head := snake.gethead
			current.occupypoint (head)

			if not (current.eatsfood (snake, head))
			then
				current.removesnaketail (snake, 1)
			else
				print("FOOD EATEN")
			end

			io.put_string ("The length of the snake: " + snake.getpoints.count.out)
			io.new_line
			io.put_string("The head of the snake: X:  " + snake.gethead.get_x.out + " ; Y: " + snake.gethead.get_y.out)
			io.new_line

			flag := current.eatspoison (snake, head)
			flag := current.eatspowerup (snake, head)
			flag := current.bitesitselforothersnake (snake)
			flag := current.collideswithborder (snake, head)



		--	current.checktimeouts (snake)
		-- GEORG
			-- Place poisons and powerUps
		--	io.put_string ("The count of poisons in state: " + state.getposions.count.out)
		--	io.new_line
			if(state.getposions.count < constants.poison_max)
				then
					current.placepoison
		--			io.put_string("Poison count after placing a poison: " + state.getposions.count.out)
		--			io.new_line
				end
			if(state.getpowerups.count < constants.power_up_max)
				then
					current.placepowerup
				end

			timeElapsed := clock.time_now - startingTime
			state.settimeelapsed (timeElapsed.second_count)
			game := current.updategameresult

		end

	updateGameResult: GAME
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
			if(state.getsnakes.count = constants.max_players and snakesPlaying = 1)
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

	get_state : STATE
		do
			Result := state
		end

	placeFood
		do
			state.setfood (occupyRandomPoint)
		end

	hasFinished: BOOLEAN
		do
			Result := finished
		end

	placePoison
		local
			poison: POISON
			actualTime: DT_TIME
		do
			poison := factory.create_poison (occupyRandomPoint)

			create actualTime.make_from_second_count (1) -- dummy value
			actualTime := clock.time_now
			poison.settimeplaced (actualTime)

			state.addpoison (poison)

		end

	placePowerUp
		local
			powerUp: POWERUP
			randomNr: REAL
			type: STRING
			actualTime: DT_TIME
		do
			powerUp := factory.create_powerup (occupyRandomPoint)

			randomNr := getRandomNumber
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

	makePointAvailable(point: POINT)
		do
			if not(state.getavaliablepoints.has (point))
			then
				if((point.get_x >= 0 and point.get_x <= (constants.board_width - constants.cell_side_length)) and
				  (point.get_y >= 0 and point.get_y <= (constants.board_height - constants.cell_side_length)))
				then
					state.getavaliablepoints.extend (point)
				end
			end
		end

	getRandomNumber: REAL
		local
			rn2: RANDOM
		do
			create rn2.make
			Result := rn2.real_item
		end

	occupyPoint(point: POINT)
		local
			index: INTEGER
			avaliablePoints: LINKED_LIST[POINT]
			avaliablePoint: POINT
			i: INTEGER
		do
			index := -1
			avaliablePoints := state.getavaliablepoints
			avaliablePoints.start
			from i := 0
			until i >= avaliablePoints.count
			loop
				avaliablePoint := avaliablePoints.item
				if(avaliablePoint.get_x = point.get_x and avaliablePoint.get_y = avaliablePoint.get_y)
				then
					index := i
				end
				avaliablePoints.forth
				i := i + 1
			end
			if(index > -1)
			then
				avaliablePoints.go_i_th (index)
				avaliablePoints.remove
			end
		end

	occupyRandomPoint: POINT
		local
			p: POINT
			avaliablePoints: LINKED_LIST[POINT]
			number: INTEGER
			rn: RANDOM_NUMBERS
			-- FOR TESTING PURPOSES
			--random_sequence: RANDOM
			--arbTime: DT_TIME
			--dif: DT_TIME_DURATION
			--intList: LINKED_LIST[INTEGER]
			--i: INTEGER
			--index: INTEGER
		do
			create p.make (0,0)
			avaliablePoints := state.getavaliablepoints

			create rn.make
			number := rn.random_integer \\ (avaliablePoints.count) + 1

			p := avaliablePoints.at (number)

			-- FOR TESTING PURPOSES
		--	create intList.make
		--	from i:= 0
		--	until i >= 10
		--	loop
		--		intList.extend (i)
		--		i := i + 1
		--	end

		--	intList.go_i_th (4)
		--	intList.remove

		--	index := 4
		--	from i := 0
		--	until i >= index
		--	loop
		--		intList.go_i_th (intList.count)
		--		intList.remove
		--		i := i + 1
		--	end

		--	intList.start

		--	from intList.start
		--	until intList.off
		--	loop
		--		io.put_integer (intList.item)
		--		intList.forth
		--	end

			-- FOR TESTING PURPOSES
			--io.put_string ("POINT: ")
			--io.put_integer (p.get_x)
			--io.put_string (" ; ")
			--io.put_integer (p.get_y)
			--io.put_new_line

			-- FOR TESTING PURPOSES
			--create arbTime.make (12, 12, 0)
			--dif := arbTime - startingTime
			--io.put_string ("ARBITRARY TIME: " + arbTime.out)
			--io.new_line
			--io.put_string ("STARTING TIME: " + startingTime.out)
			--io.put_new_line
			--io.putint (dif.second_count)

			avaliablePoints.go_i_th (number)
			avaliablePoints.remove

			Result := p
		end

end
