#include<stdio.h>
#include <string.h>

int main() {
    char command[100];

    while(1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit()") == 0 && strcmp(command, "Exit()")) {
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}