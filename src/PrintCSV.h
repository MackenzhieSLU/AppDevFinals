#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// arbitrary and can be changed to accomodate longer lines.
#define MAX_LINE_LENGTH 1024 

void printCSV(const char *filename, int numberOfFields) {

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
   

   
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ","); 
        int col = 0;

      
        while (token) {
            int value = atoi(token); 
            printf("%d ", value);    
            token = strtok(NULL, ","); 

        }

        printf("\n"); 
    }
     fclose(file);
}

   
