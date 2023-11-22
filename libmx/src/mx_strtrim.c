#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {

    if(str == NULL)
        return NULL;

    int len = mx_strlen(str);
    int start = 0;
    int end = 0;

    for(int i = 0; i < len; i++) {
        if(!mx_isspace(str[i])) {
            start = i;
            break;
        }
    }
    for(int i = len - 1; i >= 0; i--) {
        if(!mx_isspace(str[i])) {
            end = i;
            break;
        }
    }

    if(end == 0) {
        char *dst = mx_strnew(0);
        return dst;
    }
    
    char *dst = mx_strnew(end - start + 1);
    dst = mx_strncpy(dst, &str[start], end - start + 1);
    return dst;
}

