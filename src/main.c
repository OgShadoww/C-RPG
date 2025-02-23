#include <stdio.h>
#include <string.h>
#include "command_manager.h"
#include "player.h"
#include"ui_manager.h"

int main() {
    char command[100];
    Player player;

    printWelcomeMessage();

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        executeCommand(command, &player);
    }

    return 0;
}
