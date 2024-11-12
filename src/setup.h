#include "my-timer.h"

#ifndef SETUP_H
#define SETUP_H

#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))

void setInputScreen(void);

void closeScreen(void);

int askDate(const char *, int);

int setDate(int, char *[], Date *);

void printDate(Date *, char *);

void toInt(char *, int *);

#endif
