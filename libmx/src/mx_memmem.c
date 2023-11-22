#include "../inc/libmx.h"

void* mx_memmem(const void*big, size_t big_len, const void*little, size_t little_len) {
    if (little_len == 0)
        return (void*)big;

    if (big == NULL || little == NULL)
        return NULL;

    if(big_len < little_len || little_len < 0 || big_len <= 0)
        return NULL;

    unsigned char* str = (unsigned char*)big;
    unsigned char* sub = (unsigned char*)little;
    
    for (unsigned long i = 0; i < big_len - little_len; i++) {
        if(mx_memcmp(str + i, sub, little_len) == 0) {
            return (void *)(str + i);
        }
    }
    return NULL;
}

