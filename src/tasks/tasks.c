#include <stdio.h>
#include "tasks.h"

void resetDailyTasks() {
    FILE *tasksFile = fopen("data/tasks.txt", "w");

    if (!tasksFile) {
        perror("Error resetting tasks");
        return;
    }

    fprintf(tasksFile, "task1_id New daily task 10\n");
    fprintf(tasksFile, "task2_id Another task 15\n");

    fclose(tasksFile);
}
