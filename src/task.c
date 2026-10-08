#include "task.h"
#include "input.h"

void addtask(void) {
        struct Task *buff;
        if(taskdata.capacity == 0) {
                buff = calloc(1, sizeof(struct Task));
                        if(buff == NULL) {
                                printf("ERROR: Failed to allocate memory\n");
                                return;
                        }
                        else {
                                taskdata.task = buff;
                                buff = NULL;
                                taskdata.capacity++;
                        }
        }
        else if(taskdata.capacity == taskdata.taskcount) {
                buff = realloc(taskdata.task, sizeof(struct Task) * (taskdata.capacity * 2));
                        if (buff == NULL) {
                                printf("ERROR: Failed to reallocate memory\n");
                                return;
                        }
                        else{
                                taskdata.task = buff;
                                buff = NULL;
                                taskdata.capacity *= 2;
                        }
        }

        printf("Enter Task %d: ", taskdata.taskcount + 1);
        getchar();
        fgets(taskdata.task[taskdata.taskcount].title, sizeof(taskdata.task[taskdata.taskcount].title), stdin);
        taskdata.task[taskdata.taskcount].title[strcspn(taskdata.task[taskdata.taskcount].title, "\n")] = '\0';
                if(taskdata.task[taskdata.taskcount].title[0] != '\0') {
                        taskdata.task[taskdata.taskcount].id = taskdata.taskcount + 1;
                        taskdata.task[taskdata.taskcount].completed = false;
                        taskdata.taskcount++;
                        system("clear");
                        printf("Task Added, id: %d\n", taskdata.task[taskdata.taskcount - 1].id);
                }
                else{
                        system("clear");
                        printf("No input from user; the task has been discarded\n");
                }
}

void lstask(void) {
        for(int i = 0; i < taskdata.taskcount; i++) {
                printf("Task %d: [%c] %s\n", taskdata.task[i].id, taskdata.task[i].completed ? 'x' : ' ', taskdata.task[i].title);
        }
}

void deltask(void) {
        lstask();
        int choice = 0;
        printf("Enter the Task id to del: ");
        inputval(scanf("%d", &choice), choice);
        if(choice <= taskdata.taskcount && choice >= 1) {
                for(int i = choice - 1; i < (taskdata.taskcount - 1); i++) {
                        taskdata.task[i] = taskdata.task[i + 1];
                }

                taskdata.taskcount--;

                for(int j = 0; j < taskdata.taskcount; j++) {
                        taskdata.task[j].id = j + 1;
                }

                system("clear");
                printf("Task deleted!\n");

        }
        else {
                printf("Err: Invalid id\n");
        }

}

void toggletask(void) {
        int choice = 0;
        lstask();
        printf("Enter the task id to toggle completed: ");
        inputval(scanf("%d", &choice), choice);
        if(choice > taskdata.taskcount || choice <= 0) {
                printf("Undefined Behaviour, task id doesnt exist!\n");
                return;
        }
        else if(taskdata.task[choice - 1].completed == true) {
                taskdata.task[choice - 1].completed = false;
                system("clear");
                printf("Task %d was toggled as INCOMPLETED\n", choice);
        }
        else {
                taskdata.task[choice - 1].completed = true;
                system("clear");
                printf("Task %d was toggled as COMPLETED\n", choice);
        }

}




