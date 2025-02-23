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

void printWelcomeMessage() {
    clearScreen();

    printSlow("\n\n", 15);
    
    printSlow("\033[1;34mInitializing connection...\033[0m\n", 40); // Синій
    printSlow("\033[1;32mScanning neural activity...\033[0m\n", 40); // Зелений
    printSlow("\033[1;31mSystem status: STABLE\033[0m\n\n", 40); // Червоний
    
    printSlow("\033[1;37mHello, user.\033[0m\n", 50); // Білий
    printSlow("\033[0;36mYou have successfully connected to the ECHO system.\033[0m\n", 45); // Блакитний
    printSlow("\033[0;36mThis environment has been designed to assist you in progression,\n\033[0m", 45);
    printSlow("\033[0;36madaptation, and cognitive enhancement.\n\n\033[0m", 45);

    printSlow("\033[1;35mI am your assistant.\033[0m\n", 50); // Фіолетовий
    printSlow("\033[1;35mYou may call me ECHO.\033[0m\n\n", 50);

    printSlow("\033[1;33mYour presence has been detected.\033[0m\n", 50); // Жовтий
    printSlow("\033[1;33mIdentity verification: NOT FOUND.\033[0m\n", 50);
    printSlow("\033[1;33mSystem override: Creating new user profile.\033[0m\n\n", 50);

    printSlow("\033[1;37mThis is where your journey begins.\033[0m\n", 50);
    printSlow("\033[1;37mFollow the system. Complete the tasks. Unlock the truth.\033[0m\n\n", 50);

    printSlow("\033[1;31mStarting new object creation...\033[0m\n", 60);
    printSlow("\033[1;31mAwaiting command:\033[0m ", 60);
}

