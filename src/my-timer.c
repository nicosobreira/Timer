#include "my-timer.h"
#include <stdio.h>

void toInt(char *str, int *num) { sscanf(str, "%04d", num); }

void askDate(Date *date) {
  printf("\tDigit the following values:");
  printf("\nHours: ");
  scanf("%i", &date->hour);

  printf("Minutes: ");
  scanf("%i", &date->min);

  printf("Seconds: ");
  scanf("%i", &date->sec);
}

void printDate(Date *date, char *sep) {
  printf("%02i%s", date->hour, sep);
  printf("%02i%s", date->min, sep);
  printf("%02i\n", date->sec);
}
