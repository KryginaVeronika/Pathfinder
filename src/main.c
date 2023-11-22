#include "../inc/pathfinder.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }
    mx_error_cases(argv[1]);
    char *file_str = mx_file_to_str(argv[1]);
    char** lines_array = mx_strsplit(file_str ,'\n');
    int islands_num = mx_atoi(lines_array[0]);

    char**islands_name = mx_set_island_index(lines_array, islands_num);

    t_island* graph = mx_create_graph(islands_name, islands_num, lines_array);
    int **matrix = mx_create_matrix(graph, islands_num, lines_array);

    // max path???????
    int max_paths = mx_pow(islands_num, 2);
    int **path_array = (int**)malloc(sizeof(int*) * max_paths);


    for(int i = 0; i < max_paths; i++) {
        path_array[i] = (int*)malloc(sizeof(int) * (islands_num + 3));

        for(int j = 0; j < islands_num + 2; j++) {
            path_array[i][j] = -1;
        }
    }

    int path_index = 0;

    for (int i = 0; i < islands_num; i++) {
        int** paths = dijkstra(matrix,  i, islands_num, path_array);

        int path_index_found = 0;

        for(int k = path_index; k < max_paths && path_index_found == 0; k++) {
            if(path_array[i][0] == -1) { 
                path_index = i;
                path_index_found = 1;
            }
        }
        path_index_found = 0;

        if(path_index!=max_paths) {
            for(int k = 0; k < max_paths && paths[k][0] != -1; k++, path_index++) {
                for(int j = 0; j < islands_num + 2; j++) {
                    path_array[path_index][j] = paths[k][j];
                }
            }
        }
        // for (int k = 0; k < max_paths; k++) {
        //     free(paths[i]);
        // }
       //free(paths);  
    }

    print_paths(islands_name, path_array, matrix, islands_num);

    // // clear

    mx_strdel(&file_str);

    // // Free lines_array
    mx_del_strarr(&lines_array);

    // // // Free islands_name

    mx_strdel(islands_name);

    //Вивільнення graph
    for (int i = 0; i < islands_num; i++) {
        free(graph[i].island1);
        free(graph[i].island2);
    }
    free(graph);
    
    return 0;
}
