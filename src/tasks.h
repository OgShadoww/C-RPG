#ifndef TASKS_H
#define TASKS_H

typedef struct {
    char id[50];
    char content[100];
    int xp;
    char dificult;
    int completed;

} Task;

void loadTasks();
void displayTasks();
int completeTask(const char *taskID);
void saveTask();

#endif