#include "level_manager.h"
#include "ui_manager.h"
#include <stdio.h>

void addXP(Player *player, int xp) {
    player->xp += xp;

    if (player->xp >= player->xp_needed) {
        int difXP = player->xp - player->xp_needed;
        levelUp(player, difXP);
    }

    updatePlayer(player);
}

void levelUp(Player *player, int difXP) {
    player->level++;
    player->xp = difXP;
    player->xp_needed = (int)(player->xp_needed * 1.2);
    player->upgrade_point++;

    printLevelUp(player);
    updatePlayer(player);
}


void upgradeAttribute(Player *player) {
    if (player->upgrade_point <= 0) {
        printSlow("You have no upgrade points available.\n", 20);
        return;
    }

    printSlow("Choose an attribute to upgrade:\n", 25);
    printf("1. Intelligence\n");
    printf("2. Strength\n");
    printf("3. Endurance\n");
    printf("4. Creativity\n");
    printf("5. Discipline\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1: player->intelligence++; break;
        case 2: player->strength++; break;
        case 3: player->endurance++; break;
        case 4: player->creativity++; break;
        case 5: player->discipline++; break;
    }

    player->upgrade_point--;
    updatePlayer(player);
}