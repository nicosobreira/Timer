#include "my-timer.h"
#include <stdio.h>

/*#define LEN(ARR) ((sizeof(ARR) / sizeof(ARR[0])))*/

int main(int argc, char *argv[]) {
  Time time;
  int total_seconds = 0;

  switch (argc - 1) {
  case 0:
    askTime(&time);
    break;
    ;
  case 1:
    toInt(argv[1], &time.sec);
    break;
    ;
  case 2:
    toInt(argv[1], &time.min);
    toInt(argv[2], &time.sec);
    break;
    ;
  case 3:
    toInt(argv[1], &time.hour);
    toInt(argv[2], &time.min);
    toInt(argv[3], &time.sec);
    break;
    ;
  default:
    printf("Digit nothing or three number at maximum\n");
    return -1;
  }

  total_seconds = (time.hour * 3600) + (time.min * 60) + time.sec;
  printTime(&time, ":");
  printf("%i\n", total_seconds);
  return 0;
}
