note
	description: "Summary description for {GAME}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	GAME

feature

	add_snake(id: INTEGER; character_representation_in: CHARACTER) deferred end

	hasFinished: BOOLEAN deferred end

	update_state(id: INTEGER; direction: STRING) deferred end

	get_state : STATE deferred end

end
