#include "my-timer.h"
#include <curses.h>

int timer(int, char *[]);
int main(int, char *[]);

int timer(int argc, char *argv[]) {
  Date date;
  Date *pdate = &date;

  setDate(argc - 1, argv, pdate);

  int total_seconds = (date.hour * 3600) + (date.min * 60) + date.sec;
  printDate(pdate, ":");
  loop(total_seconds, pdate);
  return 0;
}

/* Function as a wrapper  for curses */
int main(int argc, char *argv[]) {
  newScreen();
  timer(argc, argv);
  closeScreen();
  return 0;
}
