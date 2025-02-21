#include <stdio.h>
#include <string.h>
#include "command_manager.h"
#include "player.h"
#include"ui_manager.h"

// void printWelcomeMessage() {
//     printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
//     printf("🎮 Welcome to TermRPG!\n");
//     printf("📜 Available commands:\n");
//     printf("   - start()   → Load and display player data\n");
//     printf("   - update()  → Update player stats\n");
//     printf("   - exit()    → Quit the game\n");
//     printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
// }

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
