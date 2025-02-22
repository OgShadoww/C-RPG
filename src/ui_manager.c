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

void printWelcomeMessage() {
    clearScreen();

    printf(YELLOW "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" RESET);
    printSlow("Welcome to C-RPG – a system designed for continuous growth.", 40);
    printSlow("Here, progress isn't just about levels – it's about real skills, habits, and achievements.", 40);
    printSlow("Every challenge you complete is a step forward in your personal journey.", 40);
    printf(YELLOW "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" RESET);

    usleep(500000);
    printf(CYAN "\nChoose your core focus:\n\n" RESET);
    printSlow(GREEN "  [1] The Developer   - Strengthen your problem-solving skills\n", 30);
    printSlow(YELLOW "  [2] The Strategist  - Improve planning and execution\n", 30);
    printSlow(RED "  [3] The Challenger  - Take on real-world challenges\n", 30);
    printSlow(MAGENTA "  [4] The Architect   - Design and build impactful projects\n", 30);
    printf("\n");

    printSlow(WHITE "Type the number corresponding to your path to continue...\n", 40);
}
