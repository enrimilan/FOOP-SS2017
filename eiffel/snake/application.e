note
	description: "snake application root class"
	date: "$Date$"
	revision: "$Revision$"

class
	APPLICATION

inherit
	EXECUTION_ENVIRONMENT

create
	make

feature {NONE} -- Private variables
	factory: FACTORY
	constants: CONSTANTS
	direct: DIRECTION
	mode: MODE
	keyboard_definition: KEYBOARD_DEFINITION
	player1: PLAYER
	player2: PLAYER
	board: ARRAY2[CHARACTER]
	game: GAME
	mutex: MUTEX

feature {NONE} -- Initialization and main entry point

	make
		local
			c: CHARACTER
			direction: STRING
			mode_value: STRING
			mode_value2: STRING
		do
			create factory
			create direct
			create constants
			create mode
			create mutex.make
			create keyboard_definition

			-- Playing modes for the 2 players
			print("Player modes: c for Computer, p for player%N")
			print("Player mode for player 1: ")
			c := read_char
			print(c)
			if c = 'c' then
				mode_value := mode.computer
			else
				mode_value := mode.player
			end
			print("%NPlayer mode for player 2: ")
			c := read_char
			print(c)
			if c = 'c' then
				mode_value2 := mode.computer
			else
				mode_value2 := mode.player
			end

			game := factory.create_game
			board := build_board

			-- Create players and add them to the game
			direction := direct.right
			create player1.make_new(current, 1, direction, mode_value, game)
			create player2.make_new(current, 2, direction, mode_value2, game)
			game.add_snake(1, 'o')
			game.add_snake(2, 'a')

			-- Start playing
			player1.launch
			player2.launch
			-- Important: this operation blocks
			listen_for_keyboard_input

			-- Workaround, sleep to block
			current.sleep (1000000000000)
		end

feature {ANY} -- Public features

	on_new_direction(player_id: INTEGER; direction: STRING)
		local
			state: STATE
			output:STRING
		do
			mutex.lock
			state := game.get_state
			game.update_state(player_id, direction)
			player1.set_interval((600 - state.get_snakes.at(1).get_speed) * 1000000)
			player2.set_interval((600 - state.get_snakes.at(2).get_speed) * 1000000)

			if not game.has_finished then
				draw_game
			else
				system("cls")
				output := "%N%N------------------------------------------%N%N%N"
				output := output+ ("          "+game.get_state.get_results+"         %N%N")
				output := output + "%N------------------------------------------%N"
				print(output)
				player1.stop
				player2.stop
			end
			mutex.unlock
		end

feature {NONE} -- Private features

	draw_game
		local
			state: STATE
			i: INTEGER
			j: INTEGER
			output: STRING
			duration: INTEGER
		do
			output := ""
			state := game.get_state
			board.fill_with (' ')

			--food
			if state.get_food.get_y /= -1 then
				board.put ('F', state.get_food.get_y+1, state.get_food.get_x+1)
			end

			--poison
			from state.get_poisons.start
			until state.get_poisons.exhausted
			loop
				board.put ('P',state.get_poisons.item.get_y+1,state.get_poisons.item.get_x+1)
				state.get_poisons.forth
			end

			--powerups
			from state.get_power_ups.start
			until state.get_power_ups.exhausted
			loop
				board.put('U',state.get_power_ups.item.get_y+1, state.get_power_ups.item.get_x+1)
				state.get_power_ups.forth
			end

			--snakes
			from state.get_snakes.start
			until state.get_snakes.exhausted
			loop
				from state.get_snakes.item.get_points.start
				until state.get_snakes.item.get_points.exhausted
				loop
					board.put (state.get_snakes.item.get_character_representation, state.get_snakes.item.get_points.item.get_y+1, state.get_snakes.item.get_points.item.get_x+1)
					state.get_snakes.item.get_points.forth
				end
				state.get_snakes.forth
			end

			--CHANGE THIS ACCORDING TO OS
			--OR REMOVE IT FOR A "DEBUG" VIEW
			duration := constants.game_duration - state.get_time_elapsed
			system("cls")
			print((duration / 60).floor)
			print(":")
			print(duration \\ 60)
			print("%NPlayer1: Health: ")
			print(state.get_snakes.at(1).get_health)
			print(" Speed: ")
			print(state.get_snakes.at(1).get_speed)
			print("%NPlayer2: Health: ")
			print(state.get_snakes.at(2).get_health)
			print(" Speed: ")
			print(state.get_snakes.at(2).get_speed)
			output := output + "%N------------------------------------------%N"
			from i:= 1
			until i > (constants.board_height)
			loop
				output := output + "|"
				from j := 1
				until j > (constants.board_width)
				loop
					output := output + board.item(i,j).out
					j := j+1
				end
				output := output + "|%N"
				i := i+1
			end
			output := output + "------------------------------------------%N"
			print(output)
		end

	build_board:ARRAY2[CHARACTER]
	-- Initialize the playing board
		require
			constants.board_width > 0 and constants.board_height > 0
		local
			width: INTEGER
			height: INTEGER
		do
			width := (constants.board_width)
			height := (constants.board_height)

			create board.make_filled('x',height,width)
			Result := board
		ensure
			Result.count = 	constants.board_width*constants.board_height
		end

	listen_for_keyboard_input
	-- Listen for input from players
		local
			c: CHARACTER
		do
			print("Press any key to start%N")
			from
        	until
            	player1.get_mode.is_equal(mode.computer) and player2.get_mode.is_equal(mode.computer)
        	loop
            	c := read_char
            	-- Prepare next direction
            	if(keyboard_definition.get_player_id_for_input(c) = 1) then
            		player1.set_direction(keyboard_definition.translate_input_to_direction(c))
            	end
            	if(keyboard_definition.get_player_id_for_input(c) = 2) then
					player2.set_direction(keyboard_definition.translate_input_to_direction(c))
				end
        	end
		end

	read_char: CHARACTER
		-- Read input from keyboard without waiting for the user to press ENTER
		external "C inline use <conio.h>"
        	alias "return getch();"
    	end

end
