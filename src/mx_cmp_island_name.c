#include "../inc/pathfinder.h"

int mx_cmp_island_name(char* name, char** name_array, int size) {
   int  index = -1;
    
    for(int i = 0; i < size && name_array[i] != NULL; i++) {
        if (mx_strcmp(name, name_array[i]) == 0) {
            index = i;        
            break;
        }
    }
    return index;
}
