#include "../inc/libmx.h"

int mx_memcmp(const void*s1, const void*s2, size_t n) {
    unsigned char* first = (unsigned char*)s1;
    unsigned char* second = (unsigned char*)s2;

    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    else if (s1 == NULL) {
        return 0 - second[0];
    }
    else if (s2 == NULL) {
        return first[0];
    }

    for(int i = 0; i < (int)n; i++) {
        if(first[i] != second[i])
            return first[i] - second[i];
    }
    return 0;
}

