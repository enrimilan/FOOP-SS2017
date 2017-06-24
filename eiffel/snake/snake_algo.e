note
	description: "Summary description for {SNAKE_ALGO}."
	author: "georg aschl"
	date: "$Date$"
	revision: "$Revision$"

class
	SNAKE_ALGO

create
	make

feature {NONE} -- Private variables
	player_id: INTEGER
	game: GAME
	dir: DIRECTION
	constants: CONSTANTS

feature {ANY} -- Initialization and main entry point

	make(game_: GAME; player_: INTEGER)
		require
			game_.hasfinished = false
		do
			game := game_
			player_id := player_
			create constants
			create dir

		end



feature {ANY} -- Public features

	get_next_direction:STRING
		require
		local
		do
			Result:=dir.up
		end

end
