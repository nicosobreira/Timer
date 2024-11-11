#ifndef MY_TIMER_H
#define MY_TIMER_H

typedef struct Date {
  int sec;
  int min;
  int hour;
} Date;

void newScreen(void);

void closeScreen(void);

void loop(int, Date *);

void askDate(Date *);

int setDate(int, char *[], Date *);

void printDate(Date *, char *);

void toInt(char *, int *);

#endif
