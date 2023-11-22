#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int swap = 0;
    for(int j = 0; j < size; j++)
        for(int i = 0; i < size - j - 1; i++) {
                if(mx_strcmp(arr[i], arr[i + 1]) > mx_strcmp(arr[i + 1], arr[i])) {    
                        char *tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        swap++;
                }
        }
    return swap;
}

