#include "my-timer.h"
#include <stdio.h>

void toInt(char *str, int *num) { sscanf(str, "%04d", num); }

void askTime(Time *time) {
  printf("\tDigit the following values:");
  printf("\nHours: ");
  scanf("%i", &time->hour);

  printf("Minutes: ");
  scanf("%i", &time->min);

  printf("Seconds: ");
  scanf("%i", &time->sec);
}

void printTime(Time *time, char *sep) {
  printf("%02i%s", time->hour, sep);
  printf("%02i%s", time->min, sep);
  printf("%02i\n", time->sec);
}
