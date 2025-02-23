#ifndef UI_MANAGER_H
#define UI_MANAGER_H

// ANSI colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include"player.h"
#include"tasks.h"

// functions
void printWelcomeMessage(Player *player, int firstTime);
void printSlow(const char *text, int delay);
void clearScreen();
void printPlayerStats(Player *player, int firstTime);
void printXPInfo(Player *player);
void printLevelUp(Player *player);

#endif
