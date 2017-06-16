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
			speedGain:INTEGER
		do
			--TODO!
		end

	eatsFood(snake: SNAKE; head: POINT): BOOLEAN
		local
			food: POINT
		do
			food := state.getfood
			if ((food.get_x = head.get_x) and (food.get_y = head.get_y)) then
				if(snake.getspeed + constants.food_speed > constants.max_speed) then
					snake.setspeed (constants.max_speed)
				else snake.setspeed (constants.food_speed)
				end
				snake.sethealth (snake.gethealth + constants.food_health)
				placeFood
				Result := true
			end
			Result := false
		end

	eatsPoison(snake: SNAKE; head: POINT): BOOLEAN
		local
			poisons: LINKED_LIST[POISON]
			removeList: LINKED_LIST[POISON]
			poison: POISON
			itemNr: INTEGER
			randomNumber: INTEGER
		do
			poisons := state.getposions
			itemNr := 0
			from poisons.start
			until poisons.off
			loop
				poison := poisons.item
				if ((poison.get_x = head.get_x) and (poison.get_y = head.get_y)) then
					--Decrease health or speed randomly
					randomNumber := getRandomNumber
					if(randomNumber.divisible (2))
					then
						snake.sethealth (snake.gethealth - constants.poison_health)
					else
						if (snake.getspeed - constants.poison_speed >= constants.min_speed) then
							snake.setspeed (snake.getspeed - constants.poison_speed)
						end
					end
					-- remove poison from list
					removeList := state.getposions
					removeList.go_i_th (itemNr)
					removeList.remove
					Result := true
				end
				poisons.forth
				itemNr := itemNr + 1
			end
			Result := false
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
					if((powerUp.gettype = "SPEED") and (snake.getspeed + constants.power_up_speed <= constants.max_speed))
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
			if (head.get_x < 0 or head.get_x > (constants.board_width-constants.cell_side_length) or head.get_y < 0 or head.get_y < (constants.board_height-constants.cell_side_length))
			then
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
				i >= index
			loop
				point := toRemove.at (snake.getlength-i)
				toRemove.go_i_th (snake.getlength-i)
				toRemove.remove
				makePointAvailable(point)
			end
		end

	calculateSnake(snake: SNAKE; direction: STRING): STRING
		-- ensure that the snake cannot move in the opposite direction, if it's length is bigger than 1
		do
			if (snake.getlength > 1)
			then
				if(direction = "LEFT" and snake.getdirection = "RIGHT")
				then
					Result := "RIGHT"
				end
				if(direction = "RIGHT" and snake.getdirection = "LEFT")
					then
						Result := "LEFT"
					end
				if(direction = "UP" and snake.getdirection = "DOWN")
					then
						Result := "DOWN"
					end
				if(direction = "DOWN" and snake.getdirection = "UP")
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
			poisons := state.getposions
			itemNr := 0
			from poisons.start
			until poisons.off
			loop
				poison := poisons.item
				difference := clock.time_now - poison.gettimeplaced
				if (difference.second_count >= constants.max_artifact_time)
				then
					-- remove poison from list
					removeListPoisons := state.getposions
					removeListPoisons.go_i_th (itemNr)
					removeListPoisons.remove
					makePointAvailable(poison.getpoisonpoint)
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
					removeListPowerUps := state.getpowerups
					removeListPowerUps.go_i_th (itemNr)
					removeListPowerUps.remove
					makePointAvailable(powerUp.getpoweruppoint)
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
					removeListInfluences := snake.getinfluences
					removeListInfluences.go_i_th (itemNr)
					removeListInfluences.remove
				end
				powerUps.forth
				itemNr := itemNr + 1
			end
		end

	update_state(id: INTEGER; direction: STRING)
		do
			--TODO!
		end


	updateGameResult: GAME
		do
			-- TODO!
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

			state.getposions.extend (poison)
		end

	placePowerUp
		local
			powerUp: POWERUP
			randomNr: INTEGER
			type: STRING
			actualTime: DT_TIME
		do
			powerUp := factory.create_powerup (occupyRandomPoint)

			randomNr := getRandomNumber
			if randomNr.divisible (2)
			then type := "SPEED"
			else type := "HEALTH"
			end
			powerUp.settype (type)

			create actualTime.make_from_second_count (1) -- dummy value
			actualTime := clock.time_now
			powerUp.settimeplaced (actualTime)

			state.getpowerups.extend (powerUp)
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

	getRandomNumber: INTEGER
		local
			rn: RANDOM_NUMBERS
		do
			create rn.make
			Result := rn.random_integer
		end

	occupyRandomPoint: POINT
		local
			p: POINT
			avaliablePoints: LINKED_LIST[POINT]
			random_sequence: RANDOM
			number: INTEGER
			rn: RANDOM_NUMBERS
			-- FOR TESTING PURPOSES
			--arbTime: DT_TIME
			--dif: DT_TIME_DURATION
		do
			create p.make (0,0)
			avaliablePoints := state.getavaliablepoints

			create rn.make
			number := rn.random_integer \\ (avaliablePoints.count) + 1

			p := avaliablePoints.at (number)

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
