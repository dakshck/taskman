#include "filelog.h"

FILE *ptr;

int filevalidate(void) {
	ptr = fopen("tasklog.txt", "a+");	
	if(ptr == NULL) {
		perror("ERROR: ");
		printf("Previous Log not found. Starting fresh...\n");
		ptr = fopen("tasklog.txt", "w");
		if(ptr == NULL) {
			perror("Cannot start fresh, ");
			return -1;
		}
	}
	else{
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
	}
	return 0;
}

void truncatelog(void) {
	char confirm_erase;
	printf("Are you sure you want to erase all logs? (Enter y to confirm.)\n: ");
	scanf("%c", &confirm_erase);
	if(confirm_erase == 'y' || confirm_erase == 'Y') {
		ptr = fopen("tasklog.txt", "w+");
		if(ptr == NULL) {
			perror("Error erasing logs: ");
			return;
		}
	}
	printf("Logs cleared succesfully\n");
}

void closefile(FILE *ptr) {
	fclose(ptr);
}

	
