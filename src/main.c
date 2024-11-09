#include <stdio.h>

#define LEN(ARR) ((sizeof(ARR) / sizeof(ARR[0])))

int toInt(char *str) {
  int num;
  sscanf(str, "%04d", &num);
  return num;
}

int main(int argc, char *argv[]) {
  unsigned int time[3] = {0, 0, 0}; // Stores hours, minutes and seconds
  unsigned int total_seconds = 0;
  switch (argc - 1) {
  case 0:
    printf("\tDigit the following values:");

    printf("\nHours: ");
    scanf("%i", &time[0]);

    printf("Minutes: ");
    scanf("%i", &time[1]);

    printf("Seconds: ");
    scanf("%i", &time[2]);
    break;
    ;
  case 1:
    time[2] = toInt(argv[1]);
    break;
    ;
  case 2:
    time[1] = toInt(argv[1]) * 60;
    time[2] = toInt(argv[2]);
    break;
    ;
  case 3:
    time[0] = toInt(argv[1]) * 3600;
    time[1] = toInt(argv[2]) * 60;
    time[2] = toInt(argv[3]);
    break;
    ;
  default:
    printf("Digit nothing or three number at maximum\n");
    return -1;
  }
  for (int i = 0; i < LEN(time); i++) {
    total_seconds += time[i];
  }
  printf("%o\n", total_seconds);
  return 0;
}
