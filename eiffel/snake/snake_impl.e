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
	speed: INTEGER
	health: INTEGER
	direct: DIRECTION
	direction: STRING
	playing: BOOLEAN
	points: LINKED_LIST[POINT]
	influences: LINKED_LIST[INFLUENCE]

feature {NONE} -- Initialization

	make(snakeId: INTEGER)
		do
			id := snakeId
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
			Result := points.first
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
end
