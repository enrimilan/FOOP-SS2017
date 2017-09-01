# Advanced Object-oriented programming
A snake game in 3 different languages: Java, Smalltalk and Eiffel <a href="https://www.youtube.com/watch?v=QRTL4xGf1xo" target="_blank">Click for demo</a>

## Protocol
The game consists of these artifacts:

* Snake: has properties such as speed (default 100, min 50, max 550), health level(default 100) and length(default 1)

* Food(only 1 artifact at the same time, shows up as long as it is not eaten): makes the snake grow and increases its health level and speed

* Poison(max 3 artifacts at the same time, shows up for 10 seconds): decreases the health level or speed of a snake

* Power-up(max 2 artifacts at the same time, shows up for 10 seconds): increases the health level or speed of a snake for 10 seconds

The following tables lists all possible situations that can occur during the game:

|           Situation          |                  Length                 |     Health     |           Speed           | Effect                                              |
|:----------------------------:|:---------------------------------------:|:--------------:|:-------------------------:|-----------------------------------------------------|
|        Snake eats food       |                    +1                   |       +50    |  +30           | forever                                             |
|       Snake eats poison      |                    doesn't change       |       -30      | or         -50            | forever                                             |
|      Snake eats power-up     |          doesn't change         | +100 | or  +50 | 10 seconds |
| Snake bites itself           | 0                                       | 0              | doesn't change            | forever                                             |
| Snake A bites snake B | A: doesn't change; B: -index_where_bitten (the tail falls of) | A: +10; B: doesn't change             | A: +10; B: -((A.length/B.length) * 10)      | A: 5 seconds; B: forever                                             |
| Snakes collides with border  | 0                                       | 0              | doesn't change            | forever                                             |


A snakes loses (because of eating poison, biting itself, getting bitten by another snake, colliding with the borders or because the time is up) if

* health<=0

* length = 0


The winner is elected as follows:

* If only one snake remains on the field, it is elected automatically as the winner of the game else

* The duration of the game is 2 minutes. The winner is the longest snake on the field else

* If some snakes are tied regarding their length, then it is a draw
