note
	description: "Summary description for {POINT}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	POINT
inherit
	ANY
		redefine
			is_equal
		end

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

	is_equal(other: POINT): BOOLEAN
		do
			Result := current.get_x.is_equal (other.get_x) and current.get_y.is_equal (other.get_y)
		end

end
