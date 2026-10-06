// Your Name Here
// Date Here
// CS5008 Lab03
//
// Implement your cycle count tool here.

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

    //Declare and initialize arrays and integer counts.
    const char *instruc[11] = {"add\0", "sub\0", "mul\0", "imu\0", "div\0", "idi\0", "mov\0", "lea\0", "pus\0", "pop\0", "ret\0"};
    char cycles[11] = {1, 1, 3, 3, 24, 24, 1, 3, 1, 1, 1};
    char count[11] = {0};
    int instrucsum = 0;
    int cyclesum = 0;

    //Use command line arg to open file.
    FILE* file = fopen(argv[1], "r");

    //Buffer arrays for reading from file output and parsing using sscanf.
    char line[256];
    char target[4];
        
    //While fgets is reading, continue to read through whole file until eof.
    while (fgets(line, sizeof(line), file)) {

        //If sscanf is successful.
        if (sscanf(line, "%3s", target) == 1) {

            //For each element in the instruction array.
            for (int i = 0; i<10; i++) {

                //Compare the two strings and if they are equal return zero and add to sums.
                if (strcmp(target, instruc[i]) == 0) {
                    count[i]++;
                    instrucsum++;
                    cyclesum += cycles[i];
                }

            }

        }

    }

    //Close file
    fclose(file);

    //Print out each count and sums.
    for (int i = 0; i<11; i++) {
        printf("%s: %d\n", instruc[i], count[i]);
    }
    printf("Total Instructions = %d\n", instrucsum);
    printf("Total Cycles = %d\n", cyclesum);

    return 0;
}