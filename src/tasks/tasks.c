#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../player/player.h"
#include "../ui/ui_manager.h"
#include "tasks.h"

void loadTasks(Task tasks[MAX_TASKS]) {
    FILE *dataT = fopen("/Users/orestgalenza/Desktop/TermRPG/data/tasks.txt", "r");

    if (dataT == NULL) {
        perror("Error opening tasks file");
        return; 
    }
    

    
}

void resetDailyTasks() {
    FILE *tasksFile = fopen("/Users/orestgalenza/Desktop/TermRPG/data/tasks.txt", "w");

    if (!tasksFile) {
        perror("Error resetting tasks");
        return;
    }

    

    fclose(tasksFile);
}
