#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_manager.h"
#include "../ui/ui_manager.h"
#include "../player/player.h"
#include"../tasks/tasks.h"
#include"../time/time_manager.h"

void startGame(Player *player) {
    int firstTime = loadPlayer(player); 

    printWelcomeMessage(player, !firstTime);

    if (firstTime) {
        printf("\nEnter `start()` to begin your journey.\n");
        return;  
    }

    checkDailyReset(player);
    printPlayerStats(player, firstTime);
    printf("\nEnter your command:\n");
}

void exitGame(Player *player) {
    printSlow("Exiting the game...", 50);
    exit(0);  // Завершує всю програму
}

Command commands[] = {
    {"start()", startGame},
    {"exit()", exitGame}
};

void executeCommand(const char *input, Player *player) {
    for(int i = 0; commands[i].name != NULL; i++) {
        if (strcmp(input, commands[i].name) == 0) {
            commands[i].execute(player);
            return;
        }
    }
    
    printf(RED "Unknown command: %s\n" RESET, input);
}