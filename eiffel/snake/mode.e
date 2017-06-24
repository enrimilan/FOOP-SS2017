note
	description: "Summary description for {MODE}."
	author: ""
	date: "$Date$"
	revision: "$Revision$"

class
	MODE

feature

	PLAYER: STRING
		once
			Result := "PLAYER"
		end

	COMPUTER: STRING
		once
			Result := "COMPUTER"
		end

end
