note
	description: "Represents the state of the game."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	STATE

feature

	get_available_points: LINKED_LIST[POINT]
	-- @return a list with non-occupied points on the board.
		deferred
		end

	get_food: POINT deferred end

	set_food(newFood: POINT)
		require
			newFood.get_x >= 0 AND newFood.get_x < 40
			newFood.get_y >= 0 AND newFood.get_y < 20
		deferred
		end

	get_results: STRING
	-- @return the game result.
		deferred
		end

	set_results(newResult: STRING)
	-- Adds a game result for a specific snake
    -- @param newResult the game result for this snake
		deferred
		end

	get_time_elapsed: INTEGER
	-- @return the elapsed time for this state from the moment it was initialized
		deferred
		end

	set_time_elapsed(newTime: INTEGER)
	-- Sets the elapsed time for this state from the moment it was initialized
    -- @param newTime the updated elapsed time
    	require
    		newTime >= 0
		deferred
		end

	get_poisons: LINKED_LIST[POISON] deferred end

	add_poison(newPoison: POISON)
		require
			newPoison.get_x >= 0 AND newPoison.get_x < 40
			newPoison.get_y >= 0 AND newPoison.get_y < 20
		deferred
		ensure
			get_poisons.count = old get_poisons.count + 1
		end

	get_power_ups: LINKED_LIST[POWERUP] deferred end

	add_power_up(newPowerUp: POWERUP)
		require
			newPowerUp.get_x >= 0 AND newPowerUp.get_x < 40
			newPowerUp.get_y >= 0 AND newPowerUp.get_y < 20
		deferred
		ensure
			get_power_ups.count = old get_power_ups.count + 1
		end

	get_snakes: LINKED_LIST[SNAKE]
	-- @return the snakes which are part of the game
		deferred
		end

	remove_poison(poison: POISON)
		deferred
		ensure
			get_poisons.count = old get_poisons.count - 1
		end

	remove_power_up(powerup: POWERUP)
		deferred
		ensure
			get_power_ups.count = old get_power_ups.count - 1
		end

	remove_available_point(point: POINT) deferred end

end
