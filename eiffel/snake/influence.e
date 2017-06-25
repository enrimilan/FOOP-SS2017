note
	description: "Influences last for a limited amount of time We have only positive influences for the speed and health. These values mean by how much the speed and health of a snake should increase."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	INFLUENCE

feature {ANY}

	set_duration(newDuration: INTEGER) deferred end

	set_speed(newSpeed: INTEGER) deferred end

	set_health(newHealth: INTEGER) deferred end

	set_start_time(newStartTime: DT_TIME) deferred end

	get_duration: INTEGER
	-- @return the duration of the influence
		deferred
		end

	get_speed: INTEGER deferred end

	get_health: INTEGER deferred end

	get_start_time: DT_TIME
	-- @return the starting time of the influence
		deferred
		end

end
