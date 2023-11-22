#include "../inc/pathfinder.h"


char **mx_make_one_line_array(char **lines_array, int line) {
    char** one_line = (char**)malloc(sizeof(char*) * 3);
    
    int delim_index = mx_get_char_index(lines_array[line], '-');
    one_line[0] = mx_strndup(lines_array[line], delim_index);

    char* crop_line = mx_strchr(lines_array[line], '-');
    crop_line++;
    delim_index = mx_get_char_index(crop_line, ',');
    one_line[1] = mx_strndup(crop_line, delim_index);

    char** weight = mx_strsplit(lines_array[line], ',');
    one_line[2] = weight[1];


    return one_line;
}
