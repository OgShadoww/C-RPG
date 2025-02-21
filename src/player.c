#include<stdio.h>
#include "player.h"

int loadPlayer(Player *player) {
    FILE *data = fopen("/Users/orestgalenza/Desktop/TermRPG/data/player.txt", "r");
    if (!data) {
        perror("Error opening file");
        return 0;
    }

    fscanf(data, "%s %d %d %d %d %d %d %s", player->name, &player->level, &player->xp, &player->xp_needed, &player->strength, &player->intelligence, &player->stamina, player->last_login);

    fclose(data);
    return 1;
}

void printPlayer(Player *player) {
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("🎮 Player: %s\n", player->name);
    printf("📅 Last Login: %s\n", player->last_login);
    printf("\n");
    printf("\n");
    printf("✨ Level: %d | XP: %d/%d\n", player->level, player->xp, player->xp_needed);
    printf("💪 Strength: %d | 🧠 Intelligence: %d | 🏃‍♂️ Stamina: %d\n", player->strength, player->intelligence, player->stamina);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    return;
}

void updatePlayer(Player *player) {
    FILE *file = fopen("/Users/orestgalenza/Desktop/TermRPG/data/player.txt", "W");

}