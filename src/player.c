#include<stdio.h>
#include "player.h"
#include"ui_manager.h"

void createPlayer(Player *player) {
    FILE *file = fopen(player->path, "w");

    if (!file) {
        perror("Error creating file");
        return;
    }

    fprintf(file, "%s %d %d %d %d %d %d %d %d %d %d %d %d %s\n", 
        player->name, 0, 0, 10, 0, 1, 1, 1, 1, 1, 0, 0, 0, "2025-02-21");

    fclose(file);
}

int loadPlayer(Player *player) {
    FILE *data = fopen(player->path, "r");
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

void printPlayer(Player *player) {
    printf("\n");
    printSlow("┌───────────────────────────────────┐\n", 15);
    printSlow("│          PLAYER PROFILE           │\n", 15);
    printSlow("└───────────────────────────────────┘\n", 15);
    
    printf(" Name:          %s\n", player->name);
    printf(" Last Login:    %s\n", player->last_login);
    printf("\n");

    printSlow("┌────────── LEVEL & XP ────────────┐\n", 10);
    printf(" Level: %d  |  XP: %d / %d\n", player->level, player->xp, player->xp_needed);
    printf("\n");

    printSlow("┌────────── ATTRIBUTES ────────────┐\n", 10);
    printf(" Intelligence:   %d\n", player->intelligence);
    printf(" Strength:       %d\n", player->strength);
    printf(" Endurance:      %d\n", player->endurance);
    printf(" Creativity:     %d\n", player->creativity);
    printf(" Discipline:     %d\n", player->discipline);
    printf("\n");

    printSlow("┌──────────── SKILLS ──────────────┐\n", 10);
    if (player->num_skills == 0) {
        printSlow(" No skills acquired yet.\n", 10);
    } else {
        for (int i = 0; i < player->num_skills; i++) {
            printf(" [%s] - Level %d (%s)\n", player->skills[i].name, player->skills[i].level, player->skills[i].type);
        }
    }
    printf("\n");

    printSlow("┌─────────── PROGRESS ─────────────┐\n", 10);
    printf(" Tasks Completed: %d\n", player->completed_tasks);
    printf(" Bosses Defeated: %d\n", player->defeated_bosses);
    printf("\n");
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
