#include "../inc/libmx.h"

int mx_strcmp(const char*s1, const char*s2) {
    for (int i = 0; i > -1; i++) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        if (s1[i] == s2[i])
            continue;
        else
            return s1[i] - s2[i];
    }
    return 0;
}

