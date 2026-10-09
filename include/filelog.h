#ifndef FILELOG_H
#define FILELOG_H

#include <stdio.h>
#include <string.h>
#include "task.h"

int filevalidate(void);
void truncatelog(void);
void closefile(FILE *ptr);

extern FILE *ptr;

#endif
