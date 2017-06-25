note
	description: "Implementation of the snake behaviour and characteristics"
	author: "Gruzdev"
	date: "$09.06.17$"
	revision: "$Revision$"

class
	SNAKE_IMPL
inherit
	SNAKE

create
	make

feature {NONE} -- Private variables
	id: INTEGER
	character_representation: CHARACTER
	speed: INTEGER
	health: INTEGER
	direct: DIRECTION
	direction: STRING
	playing: BOOLEAN
	points: LINKED_LIST[POINT]
	influences: LINKED_LIST[INFLUENCE]

feature {ANY} -- Initialization

	make(snakeId: INTEGER; character_representation_in: CHARACTER)
		do
			id := snakeId
			character_representation := character_representation_in
			speed := 100
			health := 100
			create direct
			direction := direct.right
			playing := true
			create points.make
			create influences.make
		end

feature {ANY} -- Public functions

	is_playing: BOOLEAN
		do
			Result := playing
		end

	set_direction(newDirection: STRING)
		do
			direction := newDirection
		end

	set_health(newHealth: INTEGER)
		do
			health := newHealth
		end

	set_is_playing(newIsPlaying: BOOLEAN)
		do
			playing := newIsPlaying
		end

	set_speed(newSpeed: INTEGER)
		do
			speed := newSpeed
		end

	add_head(newHead: POINT)
		do
			points.extend (newHead)
		end

	get_head: POINT
		do
			Result := points.last
		end

	get_direction: String
		do
			Result := direction
		end

	get_health: INTEGER
		do
			Result := health
		end

	get_id: INTEGER
		do
			Result := id
		end

	get_length: INTEGER
		do
			Result := points.count
		end

	get_points: LINKED_LIST[POINT]
		do
			Result := points
		end

	get_speed: INTEGER
		do
			Result := speed
		end

	get_tail: POINT
		do
			Result := points.last
		end

	get_influences: LINKED_LIST[INFLUENCE]
		do
			Result := influences
		end

	get_character_representation: CHARACTER
		do
			Result := character_representation
		end
end
