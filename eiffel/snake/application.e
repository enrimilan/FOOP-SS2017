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
	game: GAME
	keyboard_definition: KEYBOARD_DEFINITION
	direct: DIRECTION
	player1: PLAYER
	player2: PLAYER
	constants: CONSTANTS
	board: ARRAY2[CHARACTER]
	my_mutex: MUTEX
	mode: MODE

feature {NONE} -- Initialization and main entry point

	make
		local
			factory: FACTORY
			direction: STRING
			mode_value: STRING
			mode_value2: STRING
		do
			create factory
			create direct
			create constants
			create mode
			create my_mutex.make
			direction := direct.right			-- default direction: right
			mode_value := mode.player
			mode_value2 := mode.computer
			game := factory.create_game
			board := build_board


			create keyboard_definition

			create player1.make_new(current, 1, direction, mode_value2, game)
			create player2.make_new(current, 2, direction, mode_value2, game)


			game.add_snake(1, 'o')
			player1.set_joined_game(true)
            player1.set_interval(8)

			game.add_snake(2, 'a')
			player2.set_joined_game(true)
            player2.set_interval(8)

			-- Start playing
			player1.launch
			player2.launch
			--important: this operation blocks)
			listen_for_keyboard_input
		end

feature {ANY} -- Public features

	on_new_direction(player_id: INTEGER; direction: STRING)
		do
			my_mutex.lock
			--print(player_id)
			--print(" ")
			--print(direction)
			--print("%N")
			game.update_state(player_id, direction)
			-- maybe change the interval or stop a player here if he lost

			draw_game
			my_mutex.unlock
		end

feature {NONE} -- Private features

	draw_game
		local
			state: STATE
			i: INTEGER
			j: INTEGER
			output: STRING

		do
			--print("Start drawing %N")
			output := ""
			state := game.get_state
			board.fill_with (' ')

			--print("Draw food %N")
			--food
			if state.getfood.get_y /= -1 then
				board.put ('F', state.getfood.get_y+1, state.getfood.get_x+1)
					--print("Food at: ")
					--print(state.getfood.get_x)
					--print("/")
					--print(state.getfood.get_y)
					--print("%N")
			end


			--print("Draw poisons %N")
			--poison
			from state.getposions.start
			until state.getposions.exhausted
			loop
				board.put ('P',state.getposions.item.get_y+1,state.getposions.item.get_x+1)
				state.getposions.forth
			end

			--print("Draw power-ups %N")
			--powerups
			from state.getpowerups.start
			until state.getpowerups.exhausted
			loop
				board.put('U',state.getpowerups.item.get_y+1, state.getpowerups.item.get_x+1)
				state.getpowerups.forth
			end

			--print("Draw snakes %N")
			--snakes
			from state.getsnakes.start
			until state.getsnakes.exhausted
			loop
				from state.getsnakes.item.getpoints.start
				until state.getsnakes.item.getpoints.exhausted
				loop
					board.put (state.getsnakes.item.get_character_representation, state.getsnakes.item.getpoints.item.get_y+1, state.getsnakes.item.getpoints.item.get_x+1)
					--print("Snake at: ")
					--print(state.getsnakes.item.getpoints.item.get_x)
					--print("/")
					--print(state.getsnakes.item.getpoints.item.get_y)
					--print("%N")
					state.getsnakes.item.getpoints.forth
				end

				--print("Snake ")
				--print(state.getsnakes.item.getid)
				--print(" has influence: ")
				--if state.getsnakes.item.getinfluences.count > 0 then
				--	print(state.getsnakes.item.getinfluences.first.getstarttime)
				--else
				--	print("none")
				--end

				print("%N")
				state.getsnakes.forth
			end


			--CHANGE THIS ACCORDING TO OS
			--OR REMOVE IT FOR A "DEBUG" VIEW
			system("cls")
			output := output + "-----------------------------------------%N"
			from i:= 1
			until i >= (constants.board_height)
			loop
				output := output + "|"
				from j := 1
				until j >= (constants.board_width)
				loop
					output := output + board.item(i,j).out
					j := j+1
				end
				output := output + "|%N"
				i := i+1
			end
			output := output + "-----------------------------------------%N"
			print(output)
			--print("Finished drawing %N")

		end

	build_board:ARRAY2[CHARACTER]
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
		local
			c: CHARACTER
		do
			from
        	until
            	c = 'q'
        	loop
            	c := read_char
            	-- Prepare next direction
            	if(keyboard_definition.get_player_id_for_input(c) = 1) then
            		player1.set_direction(keyboard_definition.translate_input_to_direction(c))
            	end
            	if(keyboard_definition.get_player_id_for_input(c) = 2) then
					player2.set_direction(keyboard_definition.translate_input_to_direction(c))
				end

            	-- TODO used for debugging atm, later to be removed!
            	--io.put_character(c)
            	--io.put_new_line
        	end

        	-- End of the game, stop players
        	player1.stop
        	player2.stop
		end

	read_char: CHARACTER
		-- Read input from keyboard without waiting for the user to press ENTER
		external "C inline use <conio.h>"
        	alias "return getch();"
    	end



end
