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
	avaliablePoints: LINKED_LIST[POINT]
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
			create avaliablePoints.make
			create constants
			timeElapsed := 0

			create food.make(-1,-1) -- dummy values
			theResult := " " -- dummy value

			--io.put_string ("I AM HERE")

			from i := 0
			invariant (i >= 0) and (i <= constants.board_width)
			until i >= (constants.board_width - constants.cell_side_length)
			loop
				from j := 0
				invariant (j >= 0) and (j <= constants.board_height)
				until j >= (constants.board_height - constants.cell_side_length)
				loop
					create p.make(i,j)
					avaliablePoints.extend (p)
					j := j + constants.cell_side_length
				end
				i := i + constants.cell_side_length
			end

			--io.put_string ("AND NOW HERE")

			-- FOR TESTING PURPOSES
			--across
            --            avaliablePoints as aP
            --loop
            --           p := aP.item
            --           io.put_integer (p.get_x)
            --            io.put_string (" ; ")
            --            io.put_integer (p.get_y)
            --            io.put_new_line
            -- end
		end

feature {ANY} -- Public features

	removeAvaliablePoint(point: POINT)
		local
			avaliablePoint: POINT
		do
			from avaliablePoints.start
			until avaliablePoints.exhausted
			loop
				if(avaliablePoints.item.get_x = point.get_x and avaliablePoints.item.get_y = point.get_y)
				then
					avaliablePoints.remove
					avaliablePoints.finish
				end
				avaliablePoints.forth
			end
		end


	removePoison(poison: POISON)
		local
			i: INTEGER
		do
			i := poisons.index_of(poison,1)

			poisons.go_i_th (i)
			poisons.remove
		end

	removePowerUp(powerup: POWERUP)
		local
			i: INTEGER
		do
			i := powerups.index_of(powerup,1)

			powerups.go_i_th (i)
			powerups.remove
		end

	getAvaliablePoints: LINKED_LIST[POINT]
		do
			Result := avaliablePoints
		end

	getFood: POINT
		do
			Result := food
		end

	setFood(newFood: POINT)
		do
			food := newFood
		end

	getResults: STRING
		do
			Result := theResult
		end

	setResults(newResult: STRING)
		do
			theResult := newResult
		end

	getTimeElapsed: INTEGER
		do
			Result := timeElapsed
		end

	setTimeElapsed(newTime: INTEGER)
		do
			timeElapsed:= newTime
		end

	getPosions: LINKED_LIST[POISON]
		do
			Result := poisons
		end

	addPoison(newPoison: POISON)
		do
			poisons.extend (newPoison)
		end

	getPowerUps: LINKED_LIST[POWERUP]
		do
			Result := powerUps
		end

	addPowerUp(newPowerUp: POWERUP)
		do
			powerUps.extend (newPowerUp)
		end

	getSnakes: LINKED_LIST[SNAKE]
		do
			Result := snakes
		end
end
