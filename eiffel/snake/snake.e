note
	description: "Summary description for {SNAKE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	SNAKE

feature

	isPlaying: BOOLEAN deferred end
	setDirection(newDirection: STRING) deferred end
	setHealth(newHealth: INTEGER) deferred end
	setIsPlaying(newIsPlaying: BOOLEAN) deferred end
	setSpeed(newSpeed: INTEGER) deferred end
	addHead(newHead: POINT) deferred end
	getHead: Point deferred end
	getDirection: STRING deferred end
	getHealth: INTEGER deferred end
	getId: INTEGER deferred end
	getLength: INTEGER deferred end
	getPoints: LINKED_LIST[POINT] deferred end
	getSpeed: INTEGER deferred end
	getInfluences: LINKED_LIST[INFLUENCE] deferred end
	getTail: POINT deferred end

end
