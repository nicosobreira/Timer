#include "my-timer.h"
#include <curses.h>
#include <stdio.h>
#include <time.h>

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
