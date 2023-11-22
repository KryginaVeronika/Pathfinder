#include "../inc/libmx.h"

int mx_count_substr(const char*str, const char*sub) {
    if (str == NULL || sub == NULL)
        return -1;

    if (*sub == '\0')
        return 0;

    int substr = 0;
    char *tmp = NULL;
    tmp = mx_strstr(str, sub);
    while(tmp != NULL) {
        tmp = mx_strstr(tmp + 1, sub);
        substr++;
    }
    return substr;
}

