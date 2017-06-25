note
	description: "State implementation"
	author: "Gruzdev"
	date: "13.06.2017"
	revision: "$Revision$"

class
	STATE_IMPL
inherit
	STATE

create
	make

feature {NONE} -- variables
	snakes: LINKED_LIST[SNAKE]
	poisons: LINKED_LIST[POISON]
	powerUps: LINKED_LIST[POWERUP]
	availablePoints:LINKED_LIST[POINT]
	constants: CONSTANTS
	timeElapsed: INTEGER
	food: POINT
	theResult: STRING

feature {ANY} -- Initialization

	make
		local
			p: POINT
			i: INTEGER_32
			j: INTEGER_32
		do
			create snakes.make
			create poisons.make
			create powerUps.make
			create availablePoints.make
			create constants
			timeElapsed := 0
			availablePoints.compare_objects

			create food.make(-1,-1) -- dummy values
			theResult := " " -- dummy value

			from i := 0
			invariant (i >= 0) and (i <= constants.board_width)
			until i >= constants.board_width
			loop
				from j := 0
				invariant (j >= 0) and (j <= constants.board_height)
				until j >= constants.board_height
				loop
					create p.make(i,j)
					availablePoints.extend (p)
					j := j + 1
				end
				i := i + 1
			end
		end

feature {ANY} -- Public features

	remove_available_point(point: POINT)
		do
			availablePoints.prune(point)
		end

	remove_poison(poison: POISON)
		local
			i: INTEGER
		do
			i := poisons.index_of(poison,1)

			poisons.go_i_th (i)
			poisons.remove
		end

	remove_power_up(powerup: POWERUP)
		local
			i: INTEGER
		do
			i := powerups.index_of(powerup,1)

			powerups.go_i_th (i)
			powerups.remove
		end

	get_available_points: LINKED_LIST[POINT]
		do
			Result := availablePoints
		end

	get_food: POINT
		do
			Result := food
		end

	set_food(newFood: POINT)
		do
			food := newFood
		end

	get_results: STRING
		do
			Result := theResult
		end

	set_results(newResult: STRING)
		do
			theResult := newResult
		end

	get_time_elapsed: INTEGER
		do
			Result := timeElapsed
		end

	set_time_elapsed(newTime: INTEGER)
		do
			timeElapsed:= newTime
		end

	get_poisons: LINKED_LIST[POISON]
		do
			Result := poisons
		end

	add_poison(newPoison: POISON)
		do
			poisons.extend (newPoison)
		end

	get_power_ups: LINKED_LIST[POWERUP]
		do
			Result := powerUps
		end

	add_power_up(newPowerUp: POWERUP)
		do
			powerUps.extend (newPowerUp)
		end

	get_snakes: LINKED_LIST[SNAKE]
		do
			Result := snakes
		end
	
end
