note
	description: "Summary description for {INFLUENCE_IMPL}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	INFLUENCE_IMPL
inherit
	INFLUENCE

create
	make

feature {NONE}
	duration: INTEGER
	speed: INTEGER
	health: INTEGER
	startTime: DT_TIME

feature{ANY}

	make(newDuration: INTEGER; newSpeed: INTEGER; newHealth: INTEGER; newStartTime: DT_TIME)
		do
			duration := newDuration
			speed := newSpeed
			health := newHealth
			startTime := newStartTime
		end

feature {ANY}

	set_duration(newDuration: INTEGER)
		do
			duration := newDuration
		end

	set_speed(newSpeed: INTEGER)
		do
			speed := newSpeed
		end

	set_health(newHealth: INTEGER)
		do
			health := newHealth
		end

	set_start_time(newStartTime: DT_TIME)
		do
			startTime := newStartTime
		end

	get_duration: INTEGER
		do
			Result := duration
		end

	get_speed: INTEGER
		do
			Result := speed
		end

	get_health: INTEGER
		do
			Result := health
		end

	get_start_time: DT_TIME
		do
			Result := startTime
		end

end
