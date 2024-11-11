#ifndef MY_TIMER_H
#define MY_TIMER_H

typedef struct Time {
  int sec;
  int min;
  int hour;
} Time;

void toInt(char *, int *);

void askTime(Time *);

void printTime(Time *, char *);

#endif
