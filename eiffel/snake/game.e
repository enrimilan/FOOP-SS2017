note
	description: "Summary description for {GAME}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	GAME

feature

	add_snake(id: INTEGER) deferred end

	remove_snake(id: INTEGER) deferred end

	update_state(id: INTEGER; direction: STRING) deferred end

	get_state : STATE deferred end

end
