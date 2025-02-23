#ifndef TASKS_H
#define TASKS_H

typedef struct {
    char id[50];
    char desctiption[100];
    int xp;
    char dificult;
    int completed;

} Task;

void resetDailyTasks();

#endif