note
	description: "Summary description for {GAME_IMPL}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	GAME_IMPL
inherit
	GAME

create
	make

feature {NONE} -- Private variables
	state: STATE

feature {ANY} -- Initialization

	make(state_in: STATE)
		do
			state := state_in
		end

feature {ANY} -- Public features

	add_snake(id: INTEGER)
		do
			--TODO!
		end

	remove_snake(id: INTEGER)
		do
			--TODO!
		end

	update_state(id: INTEGER; direction: STRING)
		do
			--TODO!
		end

	get_state : STATE
		do
			Result := state
		end

end
