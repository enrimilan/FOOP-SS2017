note
	description: "Represents a snake for the game. Its initial speed and health are 100."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	SNAKE

feature

	is_playing: BOOLEAN deferred end

	set_direction(newDirection: STRING)
		require
			newDirection.is_equal ("RIGHT") OR newDirection.is_equal ("LEFT") OR newDirection.is_equal ("UP") OR newDirection.is_equal ("DOWN")
		deferred
		end

	set_health(newHealth: INTEGER) deferred end

	set_is_playing(newIsPlaying: BOOLEAN) deferred end

	set_speed(newSpeed: INTEGER)
		require
			newSpeed >= 50
			newSpeed <= 550
		deferred
		end

	add_head(newHead: POINT)
		deferred
		ensure
			get_length = old get_length + 1
		end

	get_head: Point deferred end

	get_direction: STRING
		deferred
		ensure
			get_direction.is_equal ("RIGHT") OR get_direction.is_equal ("LEFT") OR get_direction.is_equal ("UP") OR get_direction.is_equal ("DOWN")
		end

	get_health: INTEGER deferred end

	get_id: INTEGER deferred end

	get_length: INTEGER
		deferred
		ensure
			get_length >= 0
		end

	get_points: LINKED_LIST[POINT]
	-- A snake's body consists of many points
    -- @return the snake body (includes head and tail of course)
    	deferred
    	end

	get_speed: INTEGER
		deferred
		ensure
			get_speed >= 50
			get_speed <= 550
		end

	get_influences: LINKED_LIST[INFLUENCE]
	-- @return a list with influences for the snake. Can be speed and health influences.
		deferred
		end

	get_tail: POINT deferred end

	get_character_representation: CHARACTER deferred end

end
