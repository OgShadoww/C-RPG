#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include "player.h"

void addXP(Player *player, int xp);
void levelUp(Player *player, int difXP);
void upgradeAttribute(Player *player);

#endif