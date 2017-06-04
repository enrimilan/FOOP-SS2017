# Advanced Object-oriented programming
A snake game in 3 different languages: Java, Smalltalk and Eiffel

## Protocol
The game consists of these artifacts:

* Snake: has properties such as speed (default 600, max 100), health level(default 100) and length(default 1)

* Food: makes the snake grow and increases its health level and speed

* Poison: makes the snake shrink and decreases its health level and speed

* Power-up: increases the speed of a snake for an amount of time

The following tables lists all possible situations that can occur during the game:

|           Situation          |                  Length                 |     Health     |           Speed           | Effect                                              |
|:----------------------------:|:---------------------------------------:|:--------------:|:-------------------------:|-----------------------------------------------------|
|        Snake eats food       |                    +1                   |       +10      | if speed >= 100 then -15  | forever                                             |
|       Snake eats poison      |                    -1                   |       -10      |            +15            | forever                                             |
|      Snake eats power-up     |          if speed < 100 then +1         | doesn't change |  if speed >= 100 then -25 | some seconds for the speed,  forever for the length |
| Snake bites itself           | 0                                       | 0              | doesn't change            | forever                                             |
| Snake bites another snake    | doesn't change                          | +10            | if speed >= 100 then -15  | some seconds                                        |
| Snake gets bitten by another | -index_where_bitten (the tail falls of) | -50            | doesn't change            | forever                                             |
| Snakes collides with border  | 0                                       | 0              | doesn't change            | forever                                             |


A snakes loses because of eating poison, biting itself, getting bitten by another snake or colliding with the borders if

* health<=0

* length = 0


The winner is elected as follows:

* If only one snake remains on the field, it is elected automatically as the winner of the game else

* The duration of the game is 2 minutes. The winner is the longest snake on the field else

* If some snakes are tied regarding their length, then the snake with the greatest health level wins else 

* If some snakes are tied regarding their health, then the fastest snake wins else

* If some snakes are tied regarding their speed, then there is no winner for this game