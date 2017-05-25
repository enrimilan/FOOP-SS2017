note
	description: "Summary description for {PLAYER}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	PLAYER
inherit
	THREAD

create
	make_new

feature {NONE} -- Private variables
	app: APPLICATION
	id: INTEGER
	next_direction: STRING
	running: BOOLEAN
	joined_game: BOOLEAN
	interval: INTEGER_64

feature {ANY} -- Initialization
	make_new(application: APPLICATION; id_in: INTEGER; direction: STRING)
		do
			app := application
			id := id_in
			next_direction := direction
			running := true
			joined_game := false
			interval := 10000000000
			create launch_mutex.make
		end

feature {ANY} -- Public features

	execute
	-- Start thread execution
		do
			from
			until
				not running
			loop
				app.on_new_direction(id, next_direction)
				sleep(interval)
			end
		end

	stop
		do
			running := false
		end

	set_interval(interval_in: INTEGER_64)
		-- Sending new directions interval (in seconds)
		do
			interval := interval_in * 1000000000
		end

	set_direction(direction: STRING)
		do
			next_direction := direction
		end

	set_joined_game(joined_game_in: BOOLEAN)
		do
			joined_game := joined_game_in
		end

	has_joined_game: BOOLEAN
		do
			Result := joined_game
		end

end
