#include "taskman.h"

int taskman(void) {
	system("clear");
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

	printf("\n");

	while(choice != 5) {
		printf(
    			"      _____ _   ___ _  ____  __   _   _  _\n"
    			"     |_   _/_\\ / __| |/ /  \\/  | /_\\ | \\| |\n"
    			"       | |/ _ \\\\__ \\ ' <| |\\/| |/ _ \\| .` |\n"
    			"       |_/_/ \\_\\___/_|\\_\\_|  |_/_/ \\_\\_|\\_|\n"
			"\n ┌───────────────── YOUR TASKS ─────────────────┐\n");

		if(taskdata.taskcount != 0) {
			lstask();
		} else {printf(" │ No tasks added                               │ \n");}
		
		printf(" ├──────────────────────────────────────────────┤\n");

		printf(" │  1. Add task     2. Toggle task    3. Delete │\n");
		printf(" │  4. Manual Ops   5. Exit                     │\n │                                              │ \n");
		printf(" └──────────────────────────────────────────────┘\n");
		printf("    : ");
		int result = scanf("%d", &choice);
		choice = inputval(result, choice);

		switch (choice) {
			case 1:
				addtask();
				writelog();
				printf("---------------------------\n");		
			break;

			case 2:
				toggletask();
				writelog();
				printf("---------------------------\n");
			break;
			case 3:
				deltask();
				writelog();
				printf("---------------------------\n");
			break;
			case 4: 
				system("clear");
				int opschoice = 0;
				while(opschoice != 5) {
				printf(
    					"┌──────────────────────────────────────────┐\n"
    					"│        MANUAL OPS  (Future update)       │\n"
    					"├──────────────────────────────────────────┤\n"
    					"│  1. View log information                 │\n"
    					"│  2. Refresh log                          │\n"
    					"│  3. Format                               │\n"
    					"│  4. Reload tasks from log                │\n"
    					"│  5. Return to main menu                  │\n"
    					"└──────────────────────────────────────────┘\n"
    					"   : "
					);
				int result = scanf("%d", &opschoice);
				opschoice = inputval(result, opschoice);
				if(opschoice == 5) {system("clear");} 
				}
			break;
			default: 
			if(choice != 5) {
					printf("Undefined behaviour\n");
			}




		}	




	}	
	printf("EXIT\n");
	free(taskdata.task);
	taskdata.task = NULL;
	return 0;
}


