#include "../inc/libmx.h"

char*mx_strndup(const char *s1, size_t n) {
    if(s1 == NULL)
        return NULL; 
    size_t len = mx_strlen(s1);
    if (n < len)
        len = n;
    char *dup = mx_strnew(len);
    if(dup != NULL) {
        dup = mx_strncpy(dup, s1, len);
        return dup;
    }
    return NULL;
}

