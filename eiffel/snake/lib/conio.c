#include <termios.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "conio.h"

static struct termios old, new;
int timeout = 0;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  if(timeout)
  {
    struct timeval tmo;
    fd_set readfds;
    /* wait only 0.5 seconds for user input */
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);
    tmo.tv_sec = 0.5;
    tmo.tv_usec = 0;
    switch (select(1, &readfds, NULL, NULL, &tmo)) {
    case -1:
        break;
    case 0:
        return 1;
    }
  }
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}

int _kbhit()
{
  timeout = 1;
  return 1;
}
