#include<stdio.h>

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

int loadPlayer(Player *player) {
    FILE *data = fopen("../data/player.txt", "r");
    if (!data) {
        printf("Error: Cannot open file\n");
        return 0;
    }
    fscanf(data, "%s %d %d %d %d %d %d %s", player->name, &player->level, &player->xp, &player->xp_needed, &player->strength, &player->intelligence, &player->stamina, player->last_login);

    fclose(data);
    return 1;
}

