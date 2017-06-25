note
	description: "Summary description for {INFLUENCE}."
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

	get_duration: INTEGER deferred end

	get_speed: INTEGER deferred end

	get_health: INTEGER deferred end

	get_start_time: DT_TIME deferred end

end
