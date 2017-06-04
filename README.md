# Advanced Object-oriented programming
A snake game in 3 different languages: Java, Smalltalk and Eiffel

## Protocol
The game consists of these artifacts:

* Snake: has properties such as speed (max 100), health level and length

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