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

	getTimePlaced: DT_TIME
		do
			Result := timePlaced
		end

	setTimePlaced(newTimePlaced: DT_TIME)
		do
			timePlaced := newTimePlaced
		end

	getType: STRING
		do
			Result := type
		end

	setType(newType: STRING)
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

	getPowerUpPoint: POINT
		do
			Result := point
		end
end
