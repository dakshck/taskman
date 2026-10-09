#include "task.h"
#include "input.h"
#include "filelog.h"

struct taskdata taskdata = {0};

int main(void) {
	int choice = 0;
	if(filevalidate() != 0) {
		printf("Failed to initialise log memory.\n");
	}
	while(choice != 5) {
		printf("\n=== TASKMAN ===\n");
		printf("\n1. Add task\n");
		printf("2. List tasks\n");
		printf("3. Toggle task\n");
		printf("4. Delete task\n");
		printf("5. Exit\n\n> ");
		inputval(scanf("%d", &choice), choice);
			switch (choice) {
				case 1:
					addtask();
					printf("---------------------------\n");
				break;
				case 2:
					lstask();
					printf("---------------------------\n");
				break;
				case 3:
					toggletask();
					printf("---------------------------\n");
				break;
				case 4:
					deltask();
					printf("---------------------------\n");
				break;
				default: 
					if(choice != 5) {
						printf("Undefined behaviour\n");
					}

			}	

	}
	closefile(ptr);
	printf("EXIT\n");
	free(taskdata.task);
	taskdata.task = NULL;
	return 0;

}


