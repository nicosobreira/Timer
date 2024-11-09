#include <stdio.h>

#define LEN(ARR) (sizeof(ARR) / sizeof(ARR[0]))

int toInt(char *str) {
  int num;
  sscanf(str, "%04d", &num);
  return num;
}

int main(int argc, char *argv[]) {
  int i;
  unsigned int time[3]; // Stores hours, minutes and seconds
  unsigned int total_seconds = 0;
  switch (argc) {
  case 2:
    time[2] = toInt(argv[1]);
    break;
    ;
  case 3:
    time[1] = toInt(argv[1]);
    time[2] = toInt(argv[2]) * 60;
    break;
    ;
  case 4:
    time[0] = toInt(argv[1]);
    time[1] = toInt(argv[2]) * 60;
    time[2] = toInt(argv[3]) * 3600;
    break;
    ;
  default:
    printf("Digit at minumum one number, at maximum three\n");
    return -1;
  }
  for (i = 0; i < LEN(time); i++) {
    total_seconds += time[i];
  }
  printf("%o\n", total_seconds);
  return 0;
}
