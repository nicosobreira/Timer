#include "my-timer.h"
#include <curses.h>

int timer(int, char *[]);
void newScreen(void);
void closeScreen(void);

int timer(int argc, char *argv[]) {
  Date date;

  setDate(argc - 1, argv, &date);

  int total_seconds = (date.hour * 3600) + (date.min * 60) + date.sec;
  printDate(&date, ":");
  loop(total_seconds, &date);
  return 0;
}

void newScreen(void) {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
}

void closeScreen(void) {
  keypad(stdscr, FALSE);
  echo();
  nocbreak();
  endwin();
}

/* Function as a wrapper  for curses */
int main(int argc, char *argv[]) {
  newScreen();
  timer(argc, argv);
  closeScreen();
  return 0;
}
