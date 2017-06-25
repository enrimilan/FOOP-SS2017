note
	description: "Summary description for {POISON}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	POISON

create
	make

feature{NONE} -- Private variables
	point: POINT
	timePlaced: DT_TIME

feature{ANY} -- Initialization

	make(newPoint: POINT)
		do
			point := newPoint
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

	get_x: INTEGER
		do
			Result := point.get_x
		end

	get_y: INTEGER
		do
			Result := point.get_y
		end

	get_poison_point: POINT
		do
			Result := point
		end
end
