#include "filelog.h"

int filevalidate(void) {
	FILE *ptr = fopen("tasklog.txt", "r+");	
	if(ptr == NULL) {
		printf("Previous Log not found.\nStarting fresh...\n");
		ptr = fopen("tasklog.txt", "w");
		if(ptr == NULL) {
			perror("Cannot start fresh");
			return -1;
		}
		return 0;
	}
	else{
		char length[150];
		int log_taskcount = 0;
		int i = 0;

		while(fgets(length, sizeof(length), ptr) != NULL) {
			log_taskcount++;
		}
	return log_taskcount;
	}

}

/*
 * Counts tasks from tasklog.c
 * Return number of tasks to calloc in main.c to allocate memory for tasks
 * Again, fetches tasks from tasklog.c and updates the Task and taskda struct
 * Task and Taskdata structs are written in task.h
*/

void taskfetch(void) { 
	FILE *ptr = fopen("tasklog.txt", "r+");
	if(ptr == NULL) {
		perror("Cannot fetch previous data");
		return;
	}
	char length[150];
	int log_taskcount = 0;
	while(fgets(length, sizeof(length), ptr) != NULL) {
		char *tempint = strtok(length, "|");
		char *temparr = strtok(NULL, "|");
		char *tempbool = strtok(NULL, "|");

		taskdata.task[log_taskcount].id = atoi(tempint);
		strcpy(taskdata.task[log_taskcount].title, temparr);
		taskdata.task[log_taskcount].completed = atoi(tempbool);
		log_taskcount++;
	}
		
	taskdata.taskcount = log_taskcount;
	printf("Loaded %d tasks from memory.\n", log_taskcount);
	fclose(ptr);

	return;

}

/*
 * Truncates file to rewrite it
 * Fetches struct and writes taskdata with format to be parsed in tasklog.txt
*/

int writelog(void) {
	FILE *ptr = fopen("tasklog.txt", "w");
	if(ptr == NULL) {
		perror("Error rewriting log file");
		return -1;
	}
	for(int i = 0; i < taskdata.taskcount; i++) {
		fprintf(ptr, "%d|%s|%d\n", 
				taskdata.task[i].id,
				taskdata.task[i].title,
				taskdata.task[i].completed);
	}
	fclose(ptr);
	return 0;
}


	
