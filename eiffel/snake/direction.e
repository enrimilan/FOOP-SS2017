note
	description: "Summary description for {DIRECTION}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	DIRECTION

feature

	UP: STRING
		-- Result is a string constant denoting up direction
		once
			Result := "UP"
		end

	DOWN: STRING
		-- Result is a string constant denoting down direction
		once
			Result := "DOWN"
		end

	RIGHT: STRING
		-- Result is a string constant denoting right direction
		once
			Result := "RIGHT"
		end

	LEFT: STRING
		-- Result is a string constant denoting right direction
		once
			Result := "LEFT"
		end

end
