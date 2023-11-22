#include "../inc/libmx.h"

char *mx_strstr(const char*s1, const char*s2) {
    char *dst = NULL;
    if(s1 == NULL)
        return NULL;
    if(s2 == NULL || *s2 == '\0')
        return (char*)s1;
    for (int j = 0; j < mx_strlen(s1); j++) {
        for(int i = 0; i < mx_strlen(s2); i++) {
            dst = mx_strchr(s1, s2[i]);
            if (dst != NULL)
                break;
        }
        if(dst == NULL)
            return (char*)dst;
        if(mx_strncmp(dst, s2, mx_strlen(s2)) == 0) {
            return (char*)dst;
        }
        continue;
    }
    dst = NULL;
    return (char*) dst;
}

