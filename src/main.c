#include "my-timer.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void loop(int total_seconds, Date *date) {
  time_t initial, passed;
  initial = time(NULL);
  while (1) {
    passed = time(NULL) - initial;
    printDate(date, ":");
    if (passed >= total_seconds) {
      printf("Acabou!\n");
      break;
    }
    usleep(3);
  }
}

int main(int argc, char *argv[]) {
  Date date;

  setDate(argc - 1, argv, &date);

  int total_seconds = (date.hour * 3600) + (date.min * 60) + date.sec;
  loop(total_seconds, &date);
  return 0;
}
