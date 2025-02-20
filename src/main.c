#include <stdio.h>
#include <string.h>
#include "player.h"

int main() {
    char command[100];
    Player player;

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Видаляємо `\n`

        if (strcmp(command, "exit()") == 0 || strcmp(command, "Exit()") == 0) {
            printf("Exiting...\n");
            break;
        } 
        else if (strcmp(command, "start()") == 0 || strcmp(command, "Start()") == 0) {
            if (loadPlayer(&player) == 0) {
                printf("Error loading player data.\n");
            } else {
                printPlayer(&player);
            }
        } 
        else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}
