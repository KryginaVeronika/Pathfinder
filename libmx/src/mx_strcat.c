#include "../inc/libmx.h"

char *mx_strcat(char*s1, const char*s2) {
    int len_s1 = mx_strlen(s1);
    int len_s2 = mx_strlen(s2);
    int j = 0;
    
    for (int i = len_s1; i < len_s1 + len_s2 + 1; i++) {
        s1[i] = s2[j];
        j++;
    }
    return s1;
}

