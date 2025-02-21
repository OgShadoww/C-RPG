#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include"ui_manager.h"

void printSlow(const char *text, int delay) {
    while(*text) {
        putchar(*text++);
        fflush(stdout);
        usleep(delay * 1000);
    }

    printf("\n");
}