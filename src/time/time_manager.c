#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "time_manager.h"
#include "../tasks/tasks.h"

// get date in format YYYY-MM-DD
void getCurrentDate(char *buffer) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buffer, 20, "%Y-%m-%d", tm_info);
}

// Update data `player.txt`
void updateLastLogin(Player *player) {
    getCurrentDate(player->last_login);
    updatePlayer(player);  // Зберігаємо оновлений `player.txt`
}

// Check if new day
void checkDailyReset(Player *player) {
    char currentDate[20];
    getCurrentDate(currentDate);

    if (strcmp(player->last_login, currentDate) != 0) {  
        printf("\033[1;33m[System] New day detected. Resetting daily tasks...\033[0m\n");
        resetDailyTasks();  // Reset daily
        updateLastLogin(player);  
    }
}
