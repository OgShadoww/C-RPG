#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_manager.h"
#include "../ui/ui_manager.h"
#include "../player/player.h"
#include"../tasks/tasks.h"
#include"../time/time_manager.h"

void startGame(Player *player) {
    FILE *data = fopen("/Users/orestgalenza/Desktop/TermRPG/data/player.txt", "r");
    int firstTime = (data == NULL); 
    if (data) fclose(data); 

    if (!firstTime) {
        int loadFail = loadPlayer(player);
        if (loadFail) {
            printSlow("[SYSTEM] Please delete the save file and restart.\n", 40);
            exit(1); 
        }
    }

    printWelcomeMessage(player, firstTime);

    if (firstTime) {
        createPlayer(player);
    }

    checkDailyReset(player);
    printPlayerStats(player, firstTime);
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