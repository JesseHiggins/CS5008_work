// Your Name Here
// Date Here
// CS5008 Lab03
//
// Implement your cycle count tool here.

#include <stdio.h>
#include <string.h>



int main(int argc, char** argv) {

    const char *instruc[11] = {"ADD", "SUB", "MUL", "IMU", "DIV", "IDI", "MOV", "LEA", "PUSH", "POP", "RET"};
    char cycles[11] = {1, 1, 3, 3, 24, 24, 1, 3, 1, 1, 1};
    char count[11] = {0};

    FILE* file = fopen(argv[1], "r");

    char line[256];

    if (file != NULL) {
        
        while (fgets(line, sizeof(line), file)) {

            char destination[256];

            strncpy(destination, line, 4);
            destination[4] = '\0';

            for (int i = 0; i<11; i++) {
                if (strcmp(destination, instruc[i]) == 0) {
                    count[i] = count[i] + cycles[i];
                }

            }

        }

        fclose(file);

    } else {
        fprintf(stderr, "File error.\n");
    }

    for (int i = 0; i<11; i++) {
        printf("%s: %d\n", instruc[i], count[i]);
    }

    return 0;
}