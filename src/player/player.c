#include<stdio.h>
#include <string.h>
#include "player.h"
#include"../ui/ui_manager.h"

void createPlayer(Player *player) {
    clearScreen();
    
    printSlow("\n\033[1;34m[System] New user detected...\033[0m\n", 40);
    printSlow("\033[1;32m[System] Initializing profile...\033[0m\n\n", 40);
    
    // Введення імені гравця
    printf("\033[1;36mEnter your name: \033[0m");
    fgets(player->name, sizeof(player->name), stdin);
    player->name[strcspn(player->name, "\n")] = 0;  // Видаляємо `\n` у кінці рядка

    // Перевірка на пусте ім'я
    if (strlen(player->name) == 0) {
        strcpy(player->name, "Unknown");
    }

    // Початкові характеристики
    player->level = 1;
    player->xp = 0;
    player->xp_needed = 10;
    player->intelligence = 1;
    player->strength = 1;
    player->endurance = 1;
    player->creativity = 1;
    player->discipline = 1;
    player->completed_tasks = 0;
    player->defeated_bosses = 0;
    strcpy(player->last_login, "0000-00-00");

    // Збереження профілю
    updatePlayer(player);
    
    printSlow("\n\033[1;32m[System] Profile successfully created!\033[0m\n\n", 40);
}

int loadPlayer(Player *player) {
    FILE *data = fopen("/Users/orestgalenza/Desktop/TermRPG/data/player.txt", "r");
    if (!data) {
        perror("Error opening file");
        return 0;
    }

    if (fscanf(data, "%s %d %d %d %d", 
               player->name, &player->level, &player->xp, &player->xp_needed, &player->upgrade_point) != 5) {
        printf("⚠ Error reading player core stats.\n");
        fclose(data);
        return 0;
    }

    if (fscanf(data, "%d %d %d %d %d", 
               &player->intelligence, &player->strength, &player->endurance, 
               &player->creativity, &player->discipline) != 5) {
        printf("⚠ Error reading attributes.\n");
        fclose(data);
        return 0;
    }

    if (fscanf(data, "%d", &player->num_skills) != 1) {
        printf("⚠ Error reading skill count.\n");
        player->num_skills = 0;
    } else {
        for (int i = 0; i < player->num_skills; i++) {
            if (fscanf(data, "%49s %d %49s", player->skills[i].name, 
                       &player->skills[i].level, player->skills[i].type) != 3) {
                printf("⚠ Error reading skill data.\n");
                player->num_skills = i;
                break;
            }
        }
    }

    if (fscanf(data, "%d %d %s", &player->completed_tasks, 
               &player->defeated_bosses, player->last_login) != 3) {
        printf("⚠ Error reading progress data.\n");
        fclose(data);
        return 0;
    }

    fclose(data);
    return 1;
}


void printPlayer(Player *player, int firstTime) {
    printPlayerStats(player, firstTime);
}

void updatePlayer(Player *player) {
    FILE *file = fopen("/Users/orestgalenza/Desktop/TermRPG/data/player.txt", "w");

    if (!file) {
        perror("Error updating file");
        return;
    }

    fprintf(file, "%s %d %d %d %d %d ", player->name, player->level, player->xp, player->xp_needed, player->upgrade_point, player->num_skills);
    for(int i = 0; i < player->num_skills; i++) {
        fprintf(file, "%s %d %s ", player->skills[i].name, player->skills[i].level, player->skills[i].type);
    }    
    fprintf(file, "%d %d %s ", player->completed_tasks, player->defeated_bosses, player->last_login);

    fclose(file);
}   
