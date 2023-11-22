#include "../inc/libmx.h"

void*mx_realloc(void *ptr, size_t size) {
  
    if (ptr == NULL)
        return malloc(size);

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    unsigned char *dst = malloc(size);
    mx_memmove(dst, ptr, size);
    free(ptr);

    return dst;

}

