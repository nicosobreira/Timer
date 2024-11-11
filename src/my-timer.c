#include "my-timer.h"
#include <curses.h>
#include <stdio.h>
#include <time.h>

void loop(int total_seconds, Date *date) {
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
void askDate(Date *date) {
  printf("\tDigit the following values:\n");
  printf("Hours: ");
  scanf("%i", &date->hour);

  printf("Minutes: ");
  scanf("%i", &date->min);

  printf("Seconds: ");
  scanf("%i", &date->sec);
}

int setDate(int argc, char *argv[], Date *date) {
  switch (argc) {
  case 0:
    askDate(date);
    break;
    ;
  case 1:
    toInt(argv[1], &date->sec);
    break;
    ;
  case 2:
    toInt(argv[1], &date->min);
    toInt(argv[2], &date->sec);
    break;
    ;
  case 3:
    toInt(argv[1], &date->hour);
    toInt(argv[2], &date->min);
    toInt(argv[3], &date->sec);
    break;
    ;
  default:
    printf("Digit nothing or three number at maximum\n");
    return -1;
  }
  return 0;
}

void printDate(Date *date, char *sep) {
  printf("%02i%s", date->hour, sep);
  printf("%02i%s", date->min, sep);
  printf("%02i\n", date->sec);
}

void toInt(char *str, int *num) { sscanf(str, "%d", num); }
