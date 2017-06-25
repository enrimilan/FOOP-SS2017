note
	description: "Summary description for {STATE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	STATE

feature

	get_available_points: LINKED_LIST[POINT] deferred end
	get_food: POINT deferred end
	set_food(newFood: POINT) deferred end
	get_results: STRING deferred end
	set_results(newResult: STRING) deferred end
	get_time_elapsed: INTEGER deferred end
	set_time_elapsed(newTime: INTEGER) deferred end
	get_poisons: LINKED_LIST[POISON] deferred end
	add_poison(newPoison: POISON) deferred end
	get_power_ups: LINKED_LIST[POWERUP] deferred end
	add_power_up(newPowerUp: POWERUP) deferred end
	get_snakes: LINKED_LIST[SNAKE] deferred end
	remove_poison(poison: POISON) deferred end
	remove_power_up(powerup: POWERUP) deferred end
	remove_available_point(point: POINT) deferred end
end
