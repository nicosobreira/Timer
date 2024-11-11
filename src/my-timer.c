#include "my-timer.h"
#include <stdio.h>

void toInt(char *str, int *num) { sscanf(str, "%04d", num); }

void askTime(Time *time) {
  printf("\tDigit the following values:");
  printf("\nHours: ");
  scanf("%i", &time->sec);

  printf("Minutes: ");
  scanf("%i", &time->min);

  printf("Seconds: ");
  scanf("%i", &time->hour);
}

void printTime(Time *time, char *sep) {
  printf("%i%s", time->hour, sep);
  printf("%i%s", time->min, sep);
  printf("%i\n", time->sec);
}
