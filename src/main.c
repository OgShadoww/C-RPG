#include <stdio.h>
#include <string.h>
#include "player.h"

void printWelcomeMessage() {
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("🎮 Welcome to TermRPG!\n");
    printf("📜 Available commands:\n");
    printf("   - start()   → Load and display player data\n");
    printf("   - update()  → Update player stats\n");
    printf("   - exit()    → Quit the game\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
}

int main() {
    char command[100];
    Player player = {
        .name = "",
        .level = 0,
        .xp = 0,
        .xp_needed = 0,
        .strength = 0,
        .intelligence = 0,
        .stamina = 0,
        .last_login = ""
    };

    printWelcomeMessage();

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Видаляємо `\n`

        if (strcmp(command, "exit()") == 0) {
            printf("Exiting...\n");
            break;
        } 
        else if (strcmp(command, "start()") == 0) {
            if (loadPlayer(&player) == 1) {
                printPlayer(&player);
            } else {
                printf("Error loading player data.\n");
            }
        } 
        else {
            printf("Unknown command: %s\n", command);
        }

    }

    return 0;
}
