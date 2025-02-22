#ifndef PLAYER_H
#define PLAYER_H

// NAME LEVEL XP XP_NEEDED INT STR END CRE DISC NUM_SKILLS SKILL_1 SKILL_1_LVL SKILL_2 SKILL_2_LVL ... TASKS BOSSES LAST_LOGIN

typedef struct {
    char name[50];
    int level;
    int xp;
    int xp_needed;
    int upgrade_point;

    int intelligence;
    int strength;
    int endurance;
    int creativity;
    int discipline;

    int num_skills;

    struct {
        char name[50];
        int level;
        char type[50];
    } skills[10];

    int completed_tasks; 
    int defeated_bosses;  

    char last_login[20];
    char path[30];
} Player;

void createPlayer(Player *player);
int loadPlayer(Player *player);
void printPlayer(Player *player);
void updatePlayer(Player *player);
void addXP(Player *player, int xp);
void levelUp(Player *player, int difXP);
void upgradeAttribute(Player *player);

#endif
