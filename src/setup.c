#include "setup.h"
#include "my-timer.h"
#include <curses.h>

void setInputScreen(void) {
  echo();
  nocbreak();
  keypad(stdscr, TRUE);
}

void closeScreen(void) {
  keypad(stdscr, FALSE);
  echo();
  nocbreak();
  endwin();
}

int askDate(const char *message, int limit) {
  int time;
  char *str;
  while (1) {
    printw("%s", message);
    refresh();
    getstr(str);
    printw("\n");
    toInt(str, &time);

    if (time <= limit) {
      break;
    }
    printw("Error: digit a number less equal to %i\n", limit);
  }
  return time;
}

int setDate(int argc, char *argv[], Date *pdate) {
  switch (argc) {
  case 0:
    printw("\tDigit the following values:\n");
    pdate->hour = askDate("Hours: ", 99);
    pdate->min = askDate("Minutes: ", 60);
    pdate->sec = askDate("Seconds: ", 60);
    break;
    ;
  case 1:
    toInt(argv[1], &pdate->sec);
    break;
    ;
  case 2:
    toInt(argv[1], &pdate->min);
    toInt(argv[2], &pdate->sec);
    break;
    ;
  case 3:
    toInt(argv[1], &pdate->hour);
    toInt(argv[2], &pdate->min);
    toInt(argv[3], &pdate->sec);
    break;
    ;
  default:
    printf("Digit nothing or three number at maximum\n");
    return -1;
  }
  return 0;
}

void printDate(Date *pdate, char *sep) {
  printf("%02i%s", pdate->hour, sep);
  printf("%02i%s", pdate->min, sep);
  printf("%02i\n", pdate->sec);
}

void toInt(char *str, int *num) { sscanf(str, "%d", num); }
