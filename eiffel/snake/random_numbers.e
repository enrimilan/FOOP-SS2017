note
	description	: "System's root class"
	date: "$Date$"
	revision: "$Revision$"

class
	RANDOM_NUMBERS

create
	make

feature -- Initialization

	make
			-- Creation procedure.
		local
			clock: DT_SYSTEM_CLOCK
			l_time: DT_TIME
			l_seed: INTEGER
		do
			create clock.make
			create l_time.make_from_second_count (1) -- dummy value
			l_time := clock.time_now
			l_seed := l_time.hour
			l_seed := l_seed * 60 + l_time.minute
			l_seed := l_seed * 60 + l_time.second
			l_seed := l_seed * 1000 + l_time.millisecond
			create random_sequence.set_seed (l_seed)
		end
feature -- Access

	random_integer: INTEGER
			-- Random integer.
		do
			random_sequence.forth
			Result := random_sequence.item
		end

	random_double: DOUBLE
			-- Random integer.
		do
			random_sequence.forth
			Result := random_sequence.double_item
		end

feature {NONE} -- Implementation		

	random_sequence: RANDOM
			-- Random sequence

invariant
	random_sequence_attached: random_sequence /= Void

end -- class RANDOM_NUMBERS
