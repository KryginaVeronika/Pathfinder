#include "../inc/pathfinder.h"


int **mx_create_matrix(t_island* islands, int islands_num,char** lines_array) {
    int **matrix = (int **)malloc(islands_num * sizeof(int *));

    for (int i = 0; i < islands_num; i++) {
        matrix[i] = (int *)malloc(islands_num * sizeof(int));
        for (int j = 0; j < islands_num; j++) {
            matrix[i][j] = MAX;
        }
    }

    for(int i = 0; lines_array[i+ 1] != NULL; i++) {
        if(matrix[islands[i].index_from][islands[i].index_to] == MAX) {
             matrix[islands[i].index_from][islands[i].index_to] = islands[i].weight;
             matrix[islands[i].index_to][islands[i].index_from] = islands[i].weight;
        } else {
            // for (int i = 0; i < islands_num; i++) {
            //     free(matrix[i]);
            // }
            // free(matrix);
            mx_printerr("error: duplicate bridges\n");
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}
