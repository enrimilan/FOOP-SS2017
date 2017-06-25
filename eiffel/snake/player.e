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
	interval: INTEGER_64
	mode: MODE
	mode_value: STRING
	game: GAME
	mutex: MUTEX

feature {ANY} -- Initialization
	make_new(application: APPLICATION; id_in: INTEGER; direction: STRING; mode_in: STRING; game_: GAME)
		do
			create mode
			create mutex.make
			game:=game_
			app := application
			id := id_in
			mode_value := mode_in
			next_direction := direction
			running := true
			interval := 10000000000
			create launch_mutex.make
		end

feature {ANY} -- Public features

	execute
	local
		algo: SNAKE_ALGO
	-- Start thread execution
		do
			create algo.make (game)
			if(mode_value.is_equal(mode.computer)) then
				algo.set_player_id (id)
			end
			from
			until
				not running
			loop
				if(mode_value.is_equal(mode.computer)) then
					mutex.lock
					next_direction := algo.get_next_direction
					mutex.unlock
				end
				app.on_new_direction(id, next_direction)
				sleep(interval)
			end
		end

	stop
		do
			running := false
		end

	set_interval(interval_in: INTEGER_64)
		-- Sending new directions interval (in nanoseconds)
		do
			interval := interval_in
		end

	set_direction(direction: STRING)
		do
			if(mode_value.is_equal(mode.player)) then
				mutex.lock
				next_direction := direction
				mutex.unlock
			end
		end

	get_mode: STRING
		do
			Result := mode_value
		end

	get_id:INTEGER
		do
			Result := id
		end

end
