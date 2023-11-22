#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    
    if(src == NULL)
        return NULL;

    unsigned char *d = dst;
    const unsigned char *s = src;

    if (d == s || len == 0) {
        return dst;
    }

    if (d < s) {
        while (len--) {
            *d++ = *s++;
        }
    }
    
    else {
        d += len;
        s += len;
        while (len--) {
            *(--d) = *(--s);
        }
    }

    return dst;
}

