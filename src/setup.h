#include "my-timer.h"

#ifndef SETUP_H
#define SETUP_H

void newScreen(void);

void closeScreen(void);

int askDate(const char *);

int setDate(int, char *[], Date *);

void printDate(Date *, char *);

void toInt(char *, int *);

#endif
