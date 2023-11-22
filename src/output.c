#include "../inc/pathfinder.h"

int find_last_island(int* paths, int island_num) {
    for(int x = 0; x < island_num; x++) {
        if(x + 1 == island_num || paths[x + 1] == -1) {
            return x;
        }
    }
    return 0;
}

void print_paths(char* island_names[], int**paths, int**graph, int island_num) {
  
    for(int i = 0; i < island_num*island_num && paths[i][0] != -1; i++) {

        int end_index = find_last_island(paths[i], island_num);

        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(island_names[paths[i][0]]);
        mx_printstr(" -> ");
        mx_printstr(island_names[paths[i][end_index]]);
        mx_printstr("\n");
        mx_printstr("Route: ");
       

        for(int j = 0; j < end_index; j++) {
            mx_printstr(island_names[paths[i][j]]);
            mx_printstr(" -> ");
        }
        mx_printstr(island_names[paths[i][end_index]]);
        mx_printstr("\n");
        mx_printstr("Distance: ");
        if(end_index != 1) {
            for(int j = 0; j < end_index; j++) {
                if(j == end_index - 1) {
                    mx_printstr(mx_itoa(graph[paths[i][j]][paths[i][j+1]]));
                    mx_printstr(" = ");
                } else {
                    mx_printstr(mx_itoa(graph[paths[i][j]][paths[i][j+1]]));
                    mx_printstr(" + ");
                }
            }
        }
        // add 2 column to paths and write distance in last col
        mx_printstr(mx_itoa(paths[i][island_num + 1]));
        mx_printstr("\n========================================\n");
    }
}
