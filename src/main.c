#include "task.h"
#include "input.h"
#include "filelog.h"

struct taskdata taskdata = {0};

int main(void) {
	struct Task *buff;
	int choice = 0;
	int buff_str = 0;
	buff_str = filevalidate();
	buff = calloc(buff_str + 2, sizeof(struct Task));
		if(buff == NULL) {
			printf("Initial allocation failed\n");
		} else {
			taskdata.task = buff;
			taskdata.capacity = buff_str;
		}
	taskfetch();
	while(choice != 6) {
		printf("\n=== TASKMAN ===\n");
		printf("\n1. Add task\n");
		printf("2. List tasks\n");
		printf("3. Toggle task\n");
		printf("4. Delete task\n");
		printf("5. Clear log data\n");
		printf("6. Exit\n\n> ");
		inputval(scanf("%d", &choice), choice);
			switch (choice) {
				case 1:
					addtask();
					writelog();
					printf("---------------------------\n");
				break;
				case 2:
					lstask();
					printf("---------------------------\n");
				break;
				case 3:
					toggletask();
					writelog();
					printf("---------------------------\n");
				break;
				case 4:
					deltask();
					writelog();
					printf("---------------------------\n");
				break;
				case 5: 
					printf("ERROR\n");
					printf("---------------------------\n");
				break;
				default: 
					if(choice != 6) {
						printf("Undefined behaviour\n");
					}

			}	

	}
	printf("EXIT\n");
	free(taskdata.task);
	taskdata.task = NULL;
	return 0;

}


