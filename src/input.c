#include "input.h"

int inputval(int checkinput, int choice) {
        if(checkinput != 1) {
                while(getchar() != '\n');
		system("clear");
                return -1;
        }
        return choice;
}
