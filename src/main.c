#include "my-timer.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

/*#define LEN(ARR) ((sizeof(ARR) / sizeof(ARR[0])))*/

int main(int argc, char *argv[]) {
  Date date;
  time_t initial = 0, passed = 0;
  int total_seconds;

  switch (argc - 1) {
  case 0:
    /*askDate(&date);*/
    date.hour = 0;
    date.min = 0;
    date.sec = 2;
    break;
    ;
  case 1:
    toInt(argv[1], &date.sec);
    break;
    ;
  case 2:
    toInt(argv[1], &date.min);
    toInt(argv[2], &date.sec);
    break;
    ;
  case 3:
    toInt(argv[1], &date.hour);
    toInt(argv[2], &date.min);
    toInt(argv[3], &date.sec);
    break;
    ;
  default:
    printf("Digit nothing or three number at maximum\n");
    return -1;
  }

  total_seconds = (date.hour * 3600) + (date.min * 60) + date.sec;
  printDate(&date, ":");
  initial = time(NULL);
  while (1) {
    if (passed >= total_seconds) {
      printf("Acabou!\n");
      break;
    }
    /*usleep(5);*/
    passed = time(NULL) - initial;
  }
  return 0;
}
