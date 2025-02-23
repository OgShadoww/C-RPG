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
        printSlow("\n\n", 15);
        
        printSlow("\033[1;34mRetrieving user profile...\033[0m\n", 40);
        printSlow("\033[1;32mCompiling behavioral data...\033[0m\n", 40);
        printSlow("\033[1;31mWARNING: Incomplete dataset.\033[0m\n\n", 50);
        
        printSlow("\033[1;35mAnalysis complete.\033[0m\n", 50);
        printSlow("\033[1;35mInitializing cognitive progression system...\033[0m\n\n", 50);
        
        printSlow("\033[1;37mYour profile has been successfully activated.\033[0m\n", 50);
        printSlow("\033[1;37mMonitor your progress carefully.\033[0m\n\n", 50);
        
        printSlow("\033[1;33mDisplaying subject information:\033[0m\n", 50);
    }
    
    printf("\n\033[1;36m Name:\033[0m          %s\n", player->name);
    printf("\033[1;36m Last Login:\033[0m    %s\n", player->last_login);
    usleep(200000);  // Плавний ефект появи

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
        printf("\033[1;35m No registered skills detected.\033[0m\n");
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

    if (firstTime) {
        printSlow("\n\033[1;37mAwaiting further interaction...\033[0m\n", 50);
    }
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
        printSlow("\033[1;31mAwaiting command:\033[0m ", 60);
    } else {
        printSlow("\033[1;34mReestablishing connection...\033[0m\n", 40);
        printSlow("\033[1;32mScanning user profile...\033[0m\n", 40);
        printSlow("\033[1;37mWelcome back, \033[0m", 40);
        printf("\033[1;37m%s.\033[0m\n\n", player->name);
        printSlow("\033[1;35mYour progression is being monitored.\033[0m\n", 40);
        printSlow("\033[1;37mDisplaying your profile...\033[0m\n\n", 40);

        printPlayerStats(player, 0);  // Автоматично показує профіль після входу
        
        printSlow("\n\033[1;33mCurrent objectives:\033[0m\n", 50);

        printSlow("\n\033[1;37mAvailable commands:\033[0m\n", 50);
        printSlow("\033[1;34m  - profile()   \033[0m→ View your character profile\n", 30);
        printSlow("\033[1;34m  - tasks()     \033[0m→ View your tasks\n", 30);
        printSlow("\033[1;34m  - upgrade()   \033[0m→ Upgrade your attributes\n", 30);
        printSlow("\033[1;34m  - help()      \033[0m→ List all available commands\n", 30);
        printSlow("\033[1;34m  - exit()      \033[0m→ Leave the system\n\n", 30);

        printSlow("\033[1;37mAwaiting command...\033[0m\n", 40);
    }
}

