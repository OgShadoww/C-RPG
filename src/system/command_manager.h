#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include "../player/player.h"

typedef struct {
    char *name;                // Назва команди
    void (*execute)(Player *); // Вказівник на функцію, яка її виконує
} Command;

extern Command commands[];

void executeCommand(const char *input, Player *player);
void startGame(Player *player);
void exitGame(Player *player);

#endif
