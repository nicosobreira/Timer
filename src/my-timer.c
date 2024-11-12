#include "my-timer.h"
#include <curses.h>
#include <stdio.h>
#include <time.h>

void newScreen(void) {
  initscr();
  cbreak();
  /*noecho();*/
  keypad(stdscr, TRUE);
}

void closeScreen(void) {
  keypad(stdscr, FALSE);
  echo();
  nocbreak();
  endwin();
}

void loop(int total_seconds, Date *pdate) {
  time_t initial, passed;
  initial = time(NULL);
  while (1) {
    passed = time(NULL) - initial;
    if (passed >= total_seconds) {
      printf("Acabou!\n");
      break;
    }
    napms(3);
  }
}
int askDate(const char *message) {
  int time;
  refresh();
  printw("%s", message);
  scanf("%i", &time);
  return time;
}

int setDate(int argc, char *argv[], Date *pdate) {
  switch (argc) {
  case 0:
    addstr("\tDigit the following values:\n");
    pdate->hour = askDate("Hours: ");
    pdate->min = askDate("Minutes: ");
    pdate->sec = askDate("Seconds: ");
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
