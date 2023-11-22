#include "../inc/pathfinder.h"

char **mx_set_island_index(char **lines_array, int islands_num) {
    char **islands_name = (char**)malloc(sizeof(char *) * (islands_num));
    int max_island_index = -1;
    int island_index = 0;

    for(int i = 0; i < islands_num; i++) {
        islands_name[i] = NULL;
    }

    for (int line = 1; lines_array[line] != NULL; line++) {
        char **island1_island2_weight = mx_make_one_line_array(lines_array, line) ;

        // island from

        island_index = mx_cmp_island_name(island1_island2_weight[0], islands_name, islands_num);
        if(island_index == -1) {
            island_index = ++max_island_index;
            
            if(max_island_index >= islands_num) {
                mx_printerr("error: invalid number of islands\n");
                exit(EXIT_FAILURE);
            }
            islands_name[island_index]= mx_strdup(island1_island2_weight[0]);
        } 

        //island to
        island_index = mx_cmp_island_name(island1_island2_weight[1], islands_name, islands_num + 1);
        if(island_index == -1) {
            island_index = ++max_island_index;

            if(max_island_index >= islands_num) {
                mx_printerr("error: invalid number of islands\n");
                exit(EXIT_FAILURE);
            }
            islands_name[island_index]= mx_strdup(island1_island2_weight[1]);
        }
         mx_strdel(island1_island2_weight);
    }
    if(max_island_index != islands_num - 1) {
        mx_printerr("error: invalid number of islands\n");
     //   mx_del_strarr(&islands_name);
        exit(EXIT_FAILURE);
    }

    return islands_name;
}
