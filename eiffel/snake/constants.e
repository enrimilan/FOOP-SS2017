note
	description: "Constants dictionary for the Snake game"
	author: "Gruzdev"
	date: "12.06.17"
	revision: "$Revision$"

class
	CONSTANTS

feature

	BOARD_HEIGHT: INTEGER
		-- Result is an integer constant denoting board height
		once
			Result := 20
		end

	BOARD_WIDTH: INTEGER
		-- Rseult is an integer constant denoting board width
		once
			Result := 40
		end

	BITTING_SPEED: INTEGER
		-- Result is an integer constant
		once
			Result := 10
		end

	BITTING_DURATION: INTEGER
		-- Result is an integer constant
		once
			Result := 5
		end

	BITTING_HEALTH: INTEGER
		-- Result is an integer constant
		once
			Result := 10
		end

	FOOD_HEALTH: INTEGER
		-- Result is an integer constant denoting health increase after eating the food
		once
			Result := 50
		end

	FOOD_SPEED: INTEGER
		-- Result is an integer constant denoting speed increase after eating the food
		once
			Result := 30
		end

	GAME_DURATION: INTEGER
		-- Result is an integer constant denoting the duration of each game in seconds
		once
			Result := 2*60 -- seconds
		end

	MAX_ARTIFACT_TIME: INTEGER
		-- Result is an integer constant denoting the maximal time a posion or a powerUp can be visible and reachable by a snake on the board in seconds
		once
			Result := 10 -- seconds
		end

	MAX_PLAYERS: INTEGER
		-- Result is an integer constant denoting the maximal number of players that can play the game in the same point of time
		once
			Result := 3
		end

	MAX_SPEED: INTEGER
		-- Result is an integer constant denoting the maximal speed of each snake
		once
			Result := 550
		end

	MIN_SPEED: INTEGER
		-- Result is an integer constant denoting the minimal speed of each snake
		once
			Result := 50
		end

	POISON_CHANCE: INTEGER
		-- Result is an integer constant
		once
			Result := 5
		end

	POISON_HEALTH: INTEGER
		-- Result is an integer constant
		once
			Result := 30
		end

	POISON_MAX: INTEGER
		-- Result is an integer constant
		once
			Result := 3
		end

	POISON_SPEED: INTEGER
		-- Result is an integer constant
		once
			Result := 50
		end

	POWER_UP_CHANCE: INTEGER
		-- Result is an integer constant
		once
			Result := 20
		end

	POWER_UP_DURATION: INTEGER
		-- Result is an integer constant
		once
			Result := 10
		end

	POWER_UP_HEALTH: INTEGER
		-- Result is an integer constant
		once
			Result := 100
		end

	POWER_UP_MAX: INTEGER
		-- Result is an integer constant
		once
			Result := 2
		end

	POWER_UP_SPEED: INTEGER
		-- Result is an integer constant
		once
			Result := 50
		end
end
