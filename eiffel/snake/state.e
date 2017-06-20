note
	description: "Summary description for {STATE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

deferred class
	STATE

feature

	getAvaliablePoints: LINKED_LIST[POINT] deferred end
	getFood: POINT deferred end
	setFood(newFood: POINT) deferred end
	getResults: STRING deferred end
	setResults(newResult: STRING) deferred end
	getTimeElapsed: INTEGER deferred end
	setTimeElapsed(newTime: INTEGER) deferred end
	getPosions: LINKED_LIST[POISON] deferred end
	addPoison(newPoison: POISON) deferred end
	getPowerUps: LINKED_LIST[POWERUP] deferred end
	addPowerUp(newPowerUp: POWERUP) deferred end
	getSnakes: LINKED_LIST[SNAKE] deferred end
end
