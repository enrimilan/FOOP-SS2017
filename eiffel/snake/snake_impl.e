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

feature {NONE} -- Initialization

	make(snakeId: INTEGER; character_representation_in: CHARACTER)
		do
			id := snakeId
			character_representation := character_representation_in
			speed := 1000
			health := 100
			create direct
			direction := direct.right
			playing := true
			create points.make
			create influences.make
		end

feature {ANY} -- Public functions

	isPlaying: BOOLEAN
		do
			Result := playing
		end

	setDirection(newDirection: STRING)
		do
			direction := newDirection
		end

	setHealth(newHealth: INTEGER)
		do
			health := newHealth
		end

	setIsPlaying(newIsPlaying: BOOLEAN)
		do
			playing := newIsPlaying
		end

	setSpeed(newSpeed: INTEGER)
		do
			speed := newSpeed
		end

	addHead(newHead: POINT)
		do
			points.extend (newHead)
		end

	getHead: POINT
		do
			Result := points.last
		end

	getDirection: String
		do
			Result := direction
		end

	getHealth: INTEGER
		do
			Result := health
		end

	getId: INTEGER
		do
			Result := id
		end

	getLength: INTEGER
		do
			Result := points.count
		end

	getPoints: LINKED_LIST[POINT]
		do
			Result := points
		end

	getSpeed: INTEGER
		do
			Result := speed
		end

	getTail: POINT
		do
			Result := points.last
		end

	getInfluences: LINKED_LIST[INFLUENCE]
		do
			Result := influences
		end

	get_character_representation: CHARACTER
		do
			Result := character_representation
		end
end
