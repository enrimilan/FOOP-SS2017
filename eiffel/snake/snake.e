note
	description: "Summary description for {SNAKE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	SNAKE

feature

	is_playing: BOOLEAN deferred end
	set_direction(newDirection: STRING) deferred end
	set_health(newHealth: INTEGER) deferred end
	set_is_playing(newIsPlaying: BOOLEAN) deferred end
	set_speed(newSpeed: INTEGER) deferred end
	add_head(newHead: POINT) deferred end
	get_head: Point deferred end
	get_direction: STRING deferred end
	get_health: INTEGER deferred end
	get_id: INTEGER deferred end
	get_length: INTEGER deferred end
	get_points: LINKED_LIST[POINT] deferred end
	get_speed: INTEGER deferred end
	get_influences: LINKED_LIST[INFLUENCE] deferred end
	get_tail: POINT deferred end
	get_character_representation: CHARACTER deferred end

end
