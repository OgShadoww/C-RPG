#include <stdio.h>
#include <string.h>
#include "command_manager.h"
#include "player.h"
#include"ui_manager.h"


int main() {
    char command[100];
    Player player;
    int firstTime = !loadPlayer(&player);  // Якщо `loadPlayer` поверне 0, значить, персонаж ще не створений.

    printWelcomeMessage(&player, firstTime);

    if (firstTime) {
        printf("\nEnter `start()` to begin your journey.\n");
    } else {
        printf("\nEnter your command:\n");
    }

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        executeCommand(command, &player);
    }

    return 0;
}
