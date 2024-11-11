#include "my-timer.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
  Date date;

  setDate(argc - 1, argv, &date);

  int total_seconds = (date.hour * 3600) + (date.min * 60) + date.sec;
  printDate(&date, ":");
  loop(total_seconds, &date);
  return 0;
}
