# Snake game in Eiffel

## Setup in linux
In linux we have written some c functions to read from stdin without blocking.
These are packed in a library `libconio.a`.

You can of course generate this library by yourself as follows:

```
gcc -Wall -c conio.c
ar -cvq libconio.a conio.o
```

To make this library available, copy it into `/libs`: 

``sudo cp libconio.a /lib``

## Building
Open EiffelStudio and hit `compile`.

## Running
```
cd EIFGENs/snake/W_code/
./snake
```

## How to play
Player 1 uses asdw keys

Player 2 uses jkli keys