#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <stdbool.h>
#define MAX_INT 2147483647
#define MAX 0

#include <limits.h>



typedef struct s_island{
    char* island1;
    char* island2;
    int index_from;
    int index_to;
    int weight;
} t_island;

char **mx_make_one_line_array(char **lines_array, int line);
int mx_cmp_island_name(char* name, char** name_array, int size);
char **mx_set_island_index(char **lines_array, int islands_num);
int **dijkstra(int **graph, int src, int island_num, int**path_array);
t_island *mx_create_graph(char **islands_name, int islands_num, char **lines_array);
bool mx_isdigit(int c);
void mx_printerr(const char*s);
void mx_error_cases(const char* file);
int mx_atoi(const char *str);
int** mx_create_matrix(t_island* islands, int islands_num,char** lines_array);
void print_paths(char* island_names[], int**paths, int**graph, int island_num);




#endif
