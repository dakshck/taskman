#include "taskman.h"
#include "task.h"
#include "input.h"
#include "filelog.h"

struct taskdata taskdata = {0};

int main(void) {
	if(taskman() == 1) {
		printf("error\n");
	}
	return 0;
}

