note
	description: "snake application root class"
	date: "$Date$"
	revision: "$Revision$"

class
	APPLICATION

inherit
	ARGUMENTS

create
	make

feature {NONE} -- Private variables
	game: GAME
	keyboard_definition: KEYBOARD_DEFINITION
	player1: PLAYER
	player2: PLAYER
	player3: PLAYER

feature {NONE} -- Initialization and main entry point

	make
		local
			factory: FACTORY
		do
			create factory
			game := factory.create_game
			create keyboard_definition
			create player1.make_new(current, 1, "RIGHT")
			create player2.make_new(current, 2, "RIGHT")
			create player3.make_new(current, 3, "RIGHT")
			draw_game

			-- Start playing
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
		do
			state := game.get_state
			--TODO draw the game board!
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
            	if(c = 'x') then
            		-- New player to join
            		if(not player1.has_joined_game) then
            			game.add_snake(1)
            			draw_game
            			player1.set_joined_game(true)
            			player1.launch
            		elseif(not player2.has_joined_game) then
            			game.add_snake(2)
            			draw_game
            			player2.set_joined_game(true)
            			player2.launch
            		elseif(not player3.has_joined_game) then
            			game.add_snake(3)
            			draw_game
            			player3.set_joined_game(true)
            			player3.launch
            		end
            	else
            		-- Prepare next direction
            		if(keyboard_definition.get_player_id_for_input(c) = 1) then
            			player1.set_direction(keyboard_definition.translate_input_to_direction(c))
            		end
            		if(keyboard_definition.get_player_id_for_input(c) = 2) then
						player2.set_direction(keyboard_definition.translate_input_to_direction(c))
					end
					if(keyboard_definition.get_player_id_for_input(c) = 3) then
						player3.set_direction(keyboard_definition.translate_input_to_direction(c))
					end
            	end

            	-- TODO used for debugging atm, later to be removed!
            	io.put_character(c)
            	io.put_new_line
        	end

        	-- End of the game, stop players
        	player1.stop
        	player2.stop
       		player3.stop
		end

	read_char: CHARACTER
		-- Read input from keyboard without waiting for the user to press ENTER
		external "C inline use <conio.h>"
        	alias "return getch();"
    	end

end
