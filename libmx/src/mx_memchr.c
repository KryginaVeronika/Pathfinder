#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    if( s == NULL) 
        return NULL;
    unsigned char* str = (unsigned char*)s;
    for (int i = 0; i < (int)n; i++) {
        if((int)str[i] == c)
            return (void*)(str + i);
    }
    return NULL;
}

