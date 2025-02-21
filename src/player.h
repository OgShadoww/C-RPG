#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char name[50];
    int level;
    int xp;
    int xp_needed;
    int strength;
    int intelligence;
    int stamina;
    char last_login[20];
} Player;

int loadPlayer(Player *player);
void printPlayer(Player *player);
void updatePlayer(Player *player);

#endif
