#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../player/player.h"
#include "../ui/ui_manager.h"
#include "tasks.h"

#define MAX_TASKS 20

void resetDailyTasks() {
    FILE *tasksFile = fopen("/Users/orestgalenza/Desktop/TermRPG/data/tasks.txt", "w");

    if (!tasksFile) {
        perror("Error resetting tasks");
        return;
    }

    fprintf(tasksFile, "task1_id New daily task 10\n");
    fprintf(tasksFile, "task2_id Another task 15\n");

    fclose(tasksFile);
}
