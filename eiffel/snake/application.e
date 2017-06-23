note
	description: "snake application root class"
	date: "$Date$"
	revision: "$Revision$"

class
	APPLICATION

inherit
	--ARGUMENTS
	EXECUTION_ENVIRONMENT

create
	make

feature {NONE} -- Private variables
	game: separate GAME
	keyboard_definition: KEYBOARD_DEFINITION
	direct: DIRECTION
	player1: PLAYER
	player2: PLAYER
	constants: CONSTANTS
	board: ARRAY2[CHARACTER]

feature {NONE} -- Initialization and main entry point

	make
		local
			factory: FACTORY
			direction: STRING
		do
			create factory
			create direct
			create constants
			direction := direct.right			-- default direction: right

			game := factory.create_game
			board := build_board

			create keyboard_definition

			create player1.make_new(current, 1, direction)
			create player2.make_new(current, 2, direction)

			game.add_snake(1, 'o')
			player1.set_joined_game(true)
            player1.set_interval(8)

			game.add_snake(2, 'a')
			player2.set_joined_game(true)
            player2.set_interval(8)

            draw_game

			-- Start playing
			player1.launch
			player2.launch
			--important: this operation blocks)
			listen_for_keyboard_input
		end

feature {ANY} -- Public features

	on_new_direction(player_id: INTEGER; direction: STRING)
		do
			print(player_id)
			print(" ")
			print(direction)
			print("%N")
			game.update_state(player_id, direction)
			-- maybe change the interval or stop a player here if he lost

			draw_game
		end

feature {NONE} -- Private features

	draw_game
		local
			state: STATE
			i: INTEGER
			j: INTEGER

		do
			state := game.get_state
			board.fill_with (' ')

			--food
			if state.getfood.get_y /= -1 then
				board.put ('F', state.getfood.get_y//constants.cell_side_length, state.getfood.get_x//constants.cell_side_length)
					print("Food at: ")
					print(state.getfood.get_x)
					print("/")
					print(state.getfood.get_y)
					print("%N")
			end

			--poison
			from state.getposions.start
			until state.getposions.exhausted
			loop
				board.put ('P',state.getposions.item.get_y//constants.cell_side_length,state.getposions.item.get_x//constants.cell_side_length)
				state.getposions.forth
			end

			--powerups
			from state.getpowerups.start
			until state.getpowerups.exhausted
			loop
				board.put('U',state.getpowerups.item.get_y//constants.cell_side_length,state.getpowerups.item.get_x//constants.cell_side_length)
				state.getpowerups.forth
			end

			--snakes
			from state.getsnakes.start
			until state.getsnakes.exhausted
			loop
				from state.getsnakes.item.getpoints.start
				until state.getsnakes.item.getpoints.exhausted
				loop
					board.put (state.getsnakes.item.get_character_representation, state.getsnakes.item.getpoints.item.get_y//constants.cell_side_length, state.getsnakes.item.getpoints.item.get_x//constants.cell_side_length)
				--	print("Snake at: ")
				--	print(state.getsnakes.item.getpoints.item.get_x)
				--	print("/")
				--	print(state.getsnakes.item.getpoints.item.get_y)
				--	print("%N")
					state.getsnakes.item.getpoints.forth
				end

				print("Snake ")
				print(state.getsnakes.item.getid)
				print(" has influence: ")
				if state.getsnakes.item.getinfluences.count > 0 then
					print(state.getsnakes.item.getinfluences.first.getstarttime)
				else
					print("none")
				end

				print("%N")
				state.getsnakes.forth
			end


			--CHANGE THIS ACCORDING TO OS
			--OR REMOVE IT FOR A "DEBUG" VIEW
			system("cls")
			--print("--------------------------------------%N")
			from i:= 1
			until i >= (constants.board_height//constants.cell_side_length)
			loop
				from j := 1
				until j >= (constants.board_width//constants.cell_side_length)

				loop
					print(board.item(i,j))
					j := j+1
				end
				--print("|")
				print("%N")
				--print("|")
				i := i+1
			end
			--print("---------------------------------------%N")

		end

	build_board:ARRAY2[CHARACTER]
		require
			constants.board_width > 0 and constants.board_height > 0
		local
			width: INTEGER
			height: INTEGER
		do
			width := (constants.board_width)//constants.cell_side_length
			height := (constants.board_height)//constants.cell_side_length

			create board.make_filled('x',height,width)
			Result := board
		ensure
			Result.count = 	constants.board_width//constants.cell_side_length*constants.board_height//constants.cell_side_length
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
            	io.put_character(c)
            	io.put_new_line
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
