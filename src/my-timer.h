#ifndef MY_TIMER_H
#define MY_TIMER_H

typedef struct Date {
  int sec;
  int min;
  int hour;
} Date;

void loop(int, Date *);

#endif
