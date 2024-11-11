#ifndef MY_TIMER_H
#define MY_TIMER_H

typedef struct Date {
  int sec;
  int min;
  int hour;
} Date;

void toInt(char *, int *);

void askDate(Date *);

int setDate(int, char *[], Date *);

void printDate(Date *, char *);

#endif
