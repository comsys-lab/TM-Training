#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_topology.h"

#define MAX_LINE_LENGTH 100

void main() {
    struct TOPOLOGY topology[100];  // Array to store the struct values
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen("/home/jy/hm_overhead/input_files/topology_files/alexnet.csv", "r");  // Replace "data.csv" with your file name

    if (file == NULL) {
        printf("Failed to open the CSV file.\n");
    }

    int line_count = 0;  // Counter for the lines read

    // Skip the first line as it contains headers
    fgets(line, MAX_LINE_LENGTH, file);

    // Read the lines and assign values to the struct array
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Tokenize the line based on ","
        char* token = strtok(line, ",");
        int token_count = 0;  // Counter for the tokens read

        while (token != NULL && token_count < 8) {
            switch (token_count) {
                case 0:
                    strcpy(topology[line_count].layer, token);
                    break;
                case 1:
                    topology[line_count].ifmap_row = atoi(token);
                    break;
                case 2:
                    topology[line_count].ifmap_col = atoi(token);
                    break;
                case 3:
                    topology[line_count].filter_row = atoi(token);
                    break;
                case 4:
                    topology[line_count].filter_col = atoi(token);
                    break;
                case 5:
                    topology[line_count].channel = atoi(token);
                    break;
                case 6:
                    topology[line_count].num_filter = atoi(token);
                    break;
                case 7:
                    topology[line_count].stride = atoi(token);
                    break;
            }
            token = strtok(NULL, ",");
            token_count++;
        }

        line_count++;

        if (line_count >= 100) {
            printf("Maximum limit of struct array reached.\n");
            break;
        }
    }

    fclose(file);

    /*
    for (int i = 0; i < line_count; i++) {
        printf("Layer: %s\n", topology[i].layer);
        printf("IFMAP Height: %d\n", topology[i].ifmap_row);
        printf("IFMAP Width: %d\n", topology[i].ifmap_col);
        printf("Filter Height: %d\n", topology[i].filter_row);
        printf("Filter Width: %d\n", topology[i].filter_col);
        printf("Channels: %d\n", topology[i].channel);
        printf("Num Filter: %d\n", topology[i].num_filter);
        printf("Strides: %d\n", topology[i].stride);
        printf("\n");
    }*/
}
