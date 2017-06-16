note
	description: "Summary description for {INFLUENCE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
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

	setDuration(newDuration: INTEGER)
		do
			duration := newDuration
		end

	setSpeed(newSpeed: INTEGER)
		do
			speed := newSpeed
		end

	setHealth(newHealth: INTEGER)
		do
			health := newHealth
		end

	setStartTime(newStartTime: DT_TIME)
		do
			startTime := newStartTime
		end

	getDuration: INTEGER
		do
			Result := duration
		end

	getSpeed: INTEGER
		do
			Result := speed
		end

	getHealth: INTEGER
		do
			Result := health
		end

	getStartTime: DT_TIME
		do
			Result := startTime
		end

end
