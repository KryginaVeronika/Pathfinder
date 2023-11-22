#include "../inc/libmx.h"

char *mx_strjoin(char const*s1, char const*s2) {
    if(s1 == NULL && s2 == NULL)
        return NULL;
    int len1 = 0;
    int len2 = 0;
    if(s1 != NULL)
        len1 += mx_strlen(s1);
    else {
        char* res = mx_strdup(s2);
        return res;
    }
    if (s2 != NULL)
        len2 += mx_strlen(s2);
    else {
        char* res = mx_strdup(s1);
        return res;
    }
    char *str = mx_strnew(len1+len2+1);
    if (str == NULL) {
        return NULL;
    }
    if (s1 != NULL) {
        str = mx_strncpy(str, s1, len1);
    }
    
    if (s2 != NULL) {
        str = mx_strcat(str, s2);
    }
    return str;
}

