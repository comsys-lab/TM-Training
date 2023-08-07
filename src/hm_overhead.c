#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "/home/jy/hm_dnn/src/Data/setup_config.h"
#include "/home/jy/hm_dnn/src/Data/setup_topology.h"

int main(int argc, char *argv[]) {
    char *topo_path = NULL;
    char *config_path = NULL;

    if (argc < 4) {
        printf("Invalid number of arguments.\n");
        printf("Usage: ./h -t template.cfg -c alexnet.csv\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-t") == 0 && i + 1 < argc) {
            topo_path = argv[i + 1];
        } else if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            config_path = argv[i + 1];
        }
    }

    if (topo_path == NULL || config_path == NULL) {
        printf("Missing -t or -c flag or corresponding argument.\n");
        return 1;
    }

    // Concatenate file paths with the appropriate directory
    char topo_file[200] = "/home/jy/hm_dnn/input_files/topology_files/";
    strcat(topo_file, topo_path);

    char config_file[200] = "/home/jy/hm_dnn/input_files/config_files/";
    strcat(config_file, config_path);

    /*
    printf("Topology File Path: %s\n", topo_file);
    printf("Config File Path: %s\n", config_file);
    */

    return 0;
}