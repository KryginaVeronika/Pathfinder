#include "../inc/libmx.h"

void*mx_memcpy(void*restrict dst, const void*restrict src, size_t n) {

    if(src == NULL || dst == NULL)
        return NULL;    

    unsigned char *from = (unsigned char*)src;
    unsigned char *to = (unsigned char*)dst;

    while(n--) {
        *(to++) = *(from++);
    }
    return dst;
}

