#include "../inc/pathfinder.h"

t_island *mx_create_graph(char **islands_name, int islands_num, char **lines_array) {

    long long distance = 0;
    int island_index = 0;

    t_island *graph = (t_island *)malloc(sizeof(t_island) * islands_num);
    if (graph == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int line = 1; lines_array[line] != NULL; line++) {
        char** island1_island2_weight = mx_make_one_line_array(lines_array, line);

        // island from    
        graph[island_index].island1 = mx_strdup(island1_island2_weight[0]);
        graph[island_index].index_from = mx_cmp_island_name(graph[island_index].island1, islands_name, islands_num);

        //island to
        graph[island_index].island2 = mx_strdup(island1_island2_weight[1]);
        graph[island_index].index_to = mx_cmp_island_name(graph[island_index].island2, islands_name, islands_num);


        // bridge weight
        graph[island_index].weight =  mx_atoi(island1_island2_weight[2]);
        distance += graph[island_index].weight ;
        
        island_index++;
    }

    if (distance > MAX_INT) {
        mx_printerr("error: sum of bridges lengths is too big");
        exit(EXIT_FAILURE);
    }

    return graph;
}
