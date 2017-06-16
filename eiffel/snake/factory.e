note
	description: "Summary description for {FACTORY}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	FACTORY

feature {ANY} -- This class is used to create instances. This should be the only place where we inject the implementations.

	create_game(factory: FACTORY): GAME
		local
			state: STATE
			state_impl: STATE_IMPL
			game: GAME_IMPL
		do
			create state_impl.make
			state := state_impl
			create game.make(state, factory)
			Result := game
		end

	create_snake(id: INTEGER; newhead: POINT): SNAKE
		local
			snake: SNAKE
			snake_impl: SNAKE_IMPL
		do
			create snake_impl.make(id)
			snake_impl.addhead (newhead)
			snake := snake_impl
			Result := snake
		end

	create_poison(point: POINT): POISON
		local
			poison: POISON
		do
			create poison.make(point)
			Result := poison
		end

	create_powerUp(point:POINT): POWERUP
		local
			powerUp: POWERUP
		do
			create powerUp.make(point)
			Result := powerUp
		end

	create_influence(duration:INTEGER; speed: INTEGER; health: INTEGER; startTime: DT_TIME): INFLUENCE
		local
			influence: INFLUENCE
		do
			create influence.make (duration, speed, health, startTime)
			Result := influence
		end

end
