note
	description: "Implementation of the snake behaviour and characteristics"
	author: "Gruzdev Eugen"
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
--	points: LINKED_LIST[POINT]
	snakeWasBittenByOtherSnake: INTEGER
	snakeHasBittenOtherSnake: INTEGER
	snakeUnderInflucenceOfPowerups: INTEGER
--	direction: STRING

feature {NONE} -- Initialization

	make
		do

		end

end
