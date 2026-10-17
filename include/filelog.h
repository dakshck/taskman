#ifndef FILELOG_H
#define FILELOG_H

#include <stdio.h>
#include <string.h>
#include "task.h"

int filevalidate(void);
void taskfetch(void);
int writelog(void);

extern FILE *ptr;

#endif
