#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command_manager.h"
#include "../ui/ui_manager.h"
#include "../player/player.h"
#include"../tasks/tasks.h"
#include"../time/time_manager.h"

void startGame(Player *player, Task tasks[]) {
    FILE *dataP = fopen("/Users/orestgalenza/Desktop/TermRPG/data/player.txt", "r");
    FILE *dataT = fopen("/Users/orestgalenza/Desktop/TermRPG/data/tasks.txt", "r");
    int firstTime = (dataP == NULL); 
    if (dataP) fclose(dataP); 

    if (!firstTime) {
        int loadFail = loadPlayer(player);
        loadTasks(tasks);
    }

    printWelcomeMessage(player, firstTime);

    if (firstTime) {
        createPlayer(player);
    }
    
    checkDailyReset(player);
}

void profile(Player *player) {
    printPlayer(player, 0);
}

void menu() {
    printCommandList();
}

void tasks() {

}

void exitGame(Player *player) {
    printSlow("Exiting the game...", 50);
    exit(0);  // Завершує всю програму
}

Command commands[] = {
    {"exit()", exitGame},
    {"profile()", profile},
    {"menu()", menu},
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