#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <time.h>
#include "../player/player.h"

// get current date YYYY-MM-DD and write into `buffer`
void getCurrentDate(char *buffer);

// Update data of player in `player.txt`
void updateLastLogin(Player *player);

// Check if new day
void checkDailyReset(Player *player);

#endif // TIME_MANAGER_H