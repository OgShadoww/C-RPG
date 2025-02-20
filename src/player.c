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

int loadPlayer() {
    FILE *player = fopen("data/player.txt", "r");

    if (!player) {
        printf("Error: Cannot open file\n");
        return 0;
    }

    char f[100];
    while(fgets(f, sizeof(f), player)) {
        printf("%s", f);
    }

    fclose(player);
    return 1;
}

int main() {
    loadPlayer();
    
    return 0;
}