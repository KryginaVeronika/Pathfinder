#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,int c, size_t n) {
    unsigned char* from = (unsigned char*)src;
    unsigned char* to = (unsigned char*)dst;

    
    if (src == NULL) {
        return NULL;
    }


    while (n--) {
        *(to++) = *(from++);
        if((int)*(to-1) == c )
            return to;
    }
    return NULL;
}

