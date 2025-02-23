#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../player/player.h"
#include "../ui/ui_manager.h"
#include "tasks.h"

#define MAX_TASKS 20

Task tasks[MAX_TASKS]; // Масив для завантаження завдань
int taskCount = 0;

void loadTasks() {
    FILE *file = fopen("data/tasks.txt", "r");
    if (!file) {
        perror("[SYSTEM] Error loading tasks");
        return;
    }

    taskCount = 0;
    while (taskCount < MAX_TASKS && fscanf(file, "%s %[^\n] %d", tasks[taskCount].id, tasks[taskCount].desctiption, &tasks[taskCount].xp) == 3) {
        taskCount++;
    }

    fclose(file);
}


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
