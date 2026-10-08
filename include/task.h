#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void addtask(void);
void lstask(void);
void toggletask(void);
void deltask(void);

struct Task {
	int id;
	char title[150];
	bool completed;
};

struct taskdata	{
	struct Task *task;
	int capacity;
	int taskcount;
};

extern struct taskdata taskdata;

#endif 
