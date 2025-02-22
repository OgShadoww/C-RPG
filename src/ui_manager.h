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

// functions
void printWelcomeMessage();
void printSlow(const char *text, int delay);
void clearScreen();
void printSeparator();
void printHeader(const char *title);
void printPlayerStats(Player *player);
void printXPInfo(Player *player);
void printTaskCompletion(const char *taskName, int xp);
void printLevelUp(Player *player);

#endif
