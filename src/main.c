#include <stdio.h>
#include <string.h>
#include "system/command_manager.h"
#include "player/player.h"
#include"ui/ui_manager.h"
#include"time/time_manager.h"

int main() {
    char command[100];
    Player player;

    startGame(&player);

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        executeCommand(command, &player);
    }

    return 0;
}
