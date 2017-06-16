note
	description: "Summary description for {POINT}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	POINT

create
	make

feature {NONE}
	x: INTEGER
	y: INTEGER

feature {ANY} -- Initialization

	make(x_in: INTEGER; y_in:INTEGER)
		do
			x := x_in
			y := y_in
		end

feature {ANY} -- Public features

	get_x: INTEGER
		do
			Result := x
		end

	get_y: INTEGER
		do
			Result := y
		end

	set_x(newX: INTEGER)
		do
			x := newX
		end

	set_y(newY: INTEGER)
		do
			y := newY
		end

end
