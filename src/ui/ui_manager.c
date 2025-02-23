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

void printPlayerStats(Player *player, int firstTime) {
    clearScreen();
    if (firstTime) {
        printSlow("\n\033[1;34m[SYSTEM] Retrieving user profile...\033[0m\n", 40);
        printSlow("\033[1;32m[SYSTEM] Compiling behavioral data...\033[0m\n", 40);
        printSlow("\033[1;31m[SYSTEM] WARNING: Incomplete dataset.\033[0m\n\n", 50);
        printSlow("\033[1;33m[SYSTEM] Analysis complete. Initializing system...\033[0m\n\n", 50);
        printSlow("\033[1;35m[ECHO] Your profile has been successfully activated.\033[0m\n", 50);
        printSlow("\033[1;35m[ECHO] Monitoring progression...\033[0m\n\n", 50);
        usleep(300000);
    }

    clearScreen();

    printf("\n\033[1;36m Name: %s\033[0m\n", player->name);
    printf("\033[1;36m Last Login: %s\033[0m\n", player->last_login);
    usleep(200000);

    printf("\n\033[1;34m┌────────── LEVEL & XP ────────────┐\033[0m\n");
    printf("\033[1;34m Level: %d  |  XP: %d / %d\033[0m\n", player->level, player->xp, player->xp_needed);
    usleep(200000);

    printf("\n\033[1;32m┌────────── ATTRIBUTES ────────────┐\033[0m\n");
    printf("\033[1;32m Intelligence:   %d\033[0m\n", player->intelligence);
    printf("\033[1;32m Strength:       %d\033[0m\n", player->strength);
    printf("\033[1;32m Endurance:      %d\033[0m\n", player->endurance);
    printf("\033[1;32m Creativity:     %d\033[0m\n", player->creativity);
    printf("\033[1;32m Discipline:     %d\033[0m\n", player->discipline);
    usleep(200000);

    printf("\n\033[1;35m┌──────────── SKILLS ──────────────┐\033[0m\n");
    if (player->num_skills == 0) {
        printf("\033[1;35m [ECHO] No registered skills detected.\033[0m\n");
    } else {
        for (int i = 0; i < player->num_skills; i++) {
            printf("\033[1;35m [%s] - Level %d (%s)\033[0m\n", player->skills[i].name, player->skills[i].level, player->skills[i].type);
        }
    }
    usleep(200000);

    printf("\n\033[1;31m┌─────────── PROGRESS ─────────────┐\033[0m\n");
    printf("\033[1;31m Tasks Completed: %d\033[0m\n", player->completed_tasks);
    printf("\033[1;31m Bosses Defeated: %d\033[0m\n", player->defeated_bosses);
    usleep(200000);
}

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

void printWelcomeMessage(Player *player, int firstTime) {
    clearScreen();
    printSlow("\n\n", 15);

    if (firstTime) {
        printSlow("\033[1;34mInitializing connection...\033[0m\n", 40);
        printSlow("\033[1;32mScanning neural activity...\033[0m\n", 40);
        printSlow("\033[1;31mSystem status: STABLE\033[0m\n\n", 40);

        printSlow("\033[1;37mHello, user.\033[0m\n", 50);
        printSlow("\033[0;36mYou have successfully connected to the ECHO system.\033[0m\n", 45);
        printSlow("\033[0;36mThis environment has been designed to assist you in progression,\n\033[0m", 45);
        printSlow("\033[0;36madaptation, and cognitive enhancement.\n\n\033[0m", 45);

        printSlow("\033[1;35mI am your assistant.\033[0m\n", 50);
        printSlow("\033[1;35mYou may call me ECHO.\033[0m\n\n", 50);

        printSlow("\033[1;33mYour presence has been detected.\033[0m\n", 50);
        printSlow("\033[1;33mIdentity verification: NOT FOUND.\033[0m\n", 50);
        printSlow("\033[1;33mSystem override: Creating new user profile.\033[0m\n\n", 50);

        printSlow("\033[1;37mThis is where your journey begins.\033[0m\n", 50);
        printSlow("\033[1;37mFollow the system. Complete the tasks. Unlock the truth.\033[0m\n\n", 50);

        printSlow("\033[1;31mStarting new object creation...\033[0m\n", 60);
    } else {
        printSlow("\033[1;34mReestablishing connection...\033[0m\n", 40);
        printSlow("\033[1;32mScanning user profile...\033[0m\n", 40);
        printSlow("\033[1;37mWelcome back, \033[0m", 40);
        printf("\033[1;37m%s.\033[0m", player->name); // No newline here
        printSlow("\n\033[1;35mYour progression is being monitored.\033[0m\n", 40);
        printSlow("\033[1;37mDisplaying your profile...\033[0m\n\n", 40);
        
        printSlow("\n\033[1;33mCurrent objectives:\033[0m\n", 50);
        printCommandList();
    }
}

void printCommandList() {
    clearScreen();

    printSlow("\n\033[1;35m[ECHO] Available system commands:\033[0m\n", 40);

    usleep(200000);
    printf("\033[1;36m  - profile()   → View your character profile\033[0m\n");
    printf("\033[1;36m  - tasks()     → View your active tasks\033[0m\n");
    printf("\033[1;36m  - upgrade()   → Upgrade your attributes\033[0m\n");
    printf("\033[1;36m  - menu()      → List all available commands\033[0m\n");
    printf("\033[1;36m  - exit()      → Disconnect from the system\033[0m\n");
    
    usleep(200000);
    printSlow("\033[1;37mAwaiting command...\033[0m\n", 40);
}