#ifndef TASKS_H
#define TASKS_H

#define MAX_TASKS 20

typedef struct {
    char id[50];
    char desctiption[100];
    int xp;
    char dificult;
    int completed;
    char type[50];
} Task;

void resetDailyTasks();
void loadTasks(Task tasks[MAX_TASKS]);

#endif