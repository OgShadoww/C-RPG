#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include"ui_manager.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printSlow(const char *text, int delay) {
    while(*text) {
        putchar(*text++);
        fflush(stdout);
        usleep(delay * 1000);
    }

    printf("\n");
}

void printHeader(const char *title) {
    printf("\n" CYAN "┌───────────────────────────────────┐\n" RESET);
    printf(CYAN "│        %s        │\n" RESET, title);
    printf(CYAN "└───────────────────────────────────┘\n\n" RESET);
}

void printSeparator() {
    printf(CYAN "───────────────────────────────────────\n" RESET);
}

void printPlayerStats(Player *player) {
    clearScreen();

    printHeader("PLAYER PROFILE");

    printf(GREEN " Name:         " RESET "%s\n", player->name);
    printf(GREEN " Last Login:   " RESET "%s\n", player->last_login);
    printSeparator();

    printHeader("LEVEL & XP");
    printf(" Level: %d  |  XP: %d / %d\n", player->level, player->xp, player->xp_needed);
    printSeparator();

    printHeader("ATTRIBUTES");
    printf(YELLOW " Intelligence:  " RESET "%d\n", player->intelligence);
    printf(YELLOW " Strength:      " RESET "%d\n", player->strength);
    printf(YELLOW " Endurance:     " RESET "%d\n", player->endurance);
    printf(YELLOW " Creativity:    " RESET "%d\n", player->creativity);
    printf(YELLOW " Discipline:    " RESET "%d\n", player->discipline);
    printSeparator();

    printHeader("SKILLS");
    if (player->num_skills == 0) {
        printSlow(RED " No skills acquired yet.\n" RESET, 10);
    } else {
        for (int i = 0; i < player->num_skills; i++) {
            printf(" [%s] - Level %d (%s)\n", player->skills[i].name, player->skills[i].level, player->skills[i].type);
        }
    }
    printSeparator();

    printHeader("PROGRESS");
    printf(" Tasks Completed: %d\n", player->completed_tasks);
    printf(" Bosses Defeated: %d\n", player->defeated_bosses);
    printSeparator();

    printSlow(YELLOW " Press ENTER to continue...\n" RESET, 15);
    getchar();
}

// void printPlayerStats(Player *player) {
//     printf("\n");
//     printHeader("PLAYER PROFILE");
    
//     printf(" Name:          %s\n", player->name);
//     printf(" Last Login:    %s\n", player->last_login);
//     printf("\n");

//     printHeader("LEVEL & XP");
//     printf(" Level: %d  |  XP: %d / %d\n", player->level, player->xp, player->xp_needed);
//     printf("\n");

//     printHeader("ATTRIBUTES");
//     printf(" Intelligence:   %d\n", player->intelligence);
//     printf(" Strength:       %d\n", player->strength);
//     printf(" Endurance:      %d\n", player->endurance);
//     printf(" Creativity:     %d\n", player->creativity);
//     printf(" Discipline:     %d\n", player->discipline);
//     printf("\n");

//     printHeader("SKILLS");
//     if (player->num_skills == 0) {
//         printf(" No skills acquired yet.\n");
//     } else {
//         for (int i = 0; i < player->num_skills; i++) {
//             printf(" [%s] - Level %d (%s)\n", player->skills[i].name, player->skills[i].level, player->skills[i].type);
//         }
//     }
//     printf("\n");

//     printHeader("PROGRESS");
//     printf(" Tasks Completed: %d\n", player->completed_tasks);
//     printf(" Bosses Defeated: %d\n", player->defeated_bosses);
//     printf("\n");
// }

void printXPInfo(Player *player) {
    printf("Current XP: %d/%d\n", player->xp, player->xp_needed);
}


void printTaskCompletion(const char *taskName, int xp) {
    printf("\n");
    printSlow("───────────────────────────────────\n", 15);
    printf(" Task Completed: %s! +%d XP!\n", taskName, xp);
    printSlow("───────────────────────────────────\n", 15);
}

void printLevelUp(Player *player) {
    printf("\n");
    printSlow("───────────────────────────────────\n", 20);
    printSlow("   LEVEL UP!  You reached Level ", 20);
    printf("%d!\n", player->level);
    printSlow("───────────────────────────────────\n", 20);
}

// void printWelcomeMessage() {
//     clearScreen();

//     printf(YELLOW "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" RESET);
//     printSlow("In a world where knowledge is power...\n", 80);
//     printSlow("You embark on a journey to master skills, push your limits, and rise above all.\n", 80);
//     printSlow("This is not just a game. This is YOUR story.", 80);
//     printf(YELLOW "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" RESET);

//     usleep(800000);
//     printf(CYAN "\nChoose your path...\n\n" RESET);
//     printSlow(GREEN "  [1] The Coder   - Master algorithms and logic\n", 40);
//     printSlow(YELLOW "  [2] The Hacker  - Crack the secrets of the system\n", 40);
//     printSlow(RED "  [3] The Warrior - Train your discipline and strategy\n", 40);
//     printSlow(MAGENTA "  [4] The Architect - Build systems that will last forever\n", 40);
//     printf("\n");

//     printSlow(WHITE "Type your path number to continue...\n", 80);
// }


void printWelcomeScreen() {
    clearScreen();
    
    printSlow("\n\n", 15);
    printHeader("C-RPG");
    printSlow("\nYou wake up in a strange, unknown place...\n", 20);
    printSlow("A mysterious system has been integrated into your life.\n", 20);
    printSlow("Improve yourself, complete challenges, and uncover the truth.\n\n", 20);

    printf("1. Start Journey()\n");
    printf("2. Load Game()\n");
    printf("3. Help()\n");
    printf("4. Exit()\n");

    printSlow("\nChoose an option: ", 15);
}