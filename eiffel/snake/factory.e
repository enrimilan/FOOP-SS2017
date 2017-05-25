note
	description: "Summary description for {FACTORY}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	FACTORY

feature {ANY} -- This class is used to create instances. This should be the only place where we inject the implementations.

	create_game: GAME
		local
			state: STATE
			state_impl: STATE_IMPL
			game: GAME_IMPL
		do
			create state_impl
			state := state_impl
			create game.make(state)
			Result := game
		end

	create_snake: SNAKE
		local
			snake: SNAKE
			snake_impl: SNAKE_IMPL
		do
			create snake_impl.make
			snake := snake_impl
			Result := snake
		end

end
