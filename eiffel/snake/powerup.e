note
	description: "Summary description for {POWERUP}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	POWERUP

create
	make

feature{NONE} -- Private variables
	point: POINT
	type: STRING
	timePlaced: DT_TIME

feature{ANY} -- Initialization

	make(newPoint: POINT)
		do
			point := newPoint
			type := " " -- dummy value
			create timePlaced.make_from_second_count (1) --dummy value
		end

feature{ANY} -- Public functions

	get_time_placed: DT_TIME
		do
			Result := timePlaced
		end

	set_time_placed(newTimePlaced: DT_TIME)
		do
			timePlaced := newTimePlaced
		end

	get_type: STRING
		do
			Result := type
		end

	set_type(newType: STRING)
		do
			type := newType
		end

	get_x: INTEGER
		do
			Result := point.get_x
		end

	get_y: INTEGER
		do
			Result := point.get_y
		end

	get_power_up_point: POINT
		do
			Result := point
		end
end
