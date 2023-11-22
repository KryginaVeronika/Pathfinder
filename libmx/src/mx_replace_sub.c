#include "../inc/libmx.h"


static void replacing(char*res, const char*str, const char*sub, const char*replace) {
    int index_start = mx_get_substr_index(str, sub);
    int index_end = index_start + mx_strlen(sub);
    if(index_start == -1) {
        return;
    }
    res = mx_strncpy(res, str, index_start);
    res = mx_strcat(res, replace);
    res = mx_strcat(res, (str+index_end));
    

}

char* mx_replace_substr(const char*str, const char*sub, const char*replace) {

    if (str == NULL || sub == NULL || replace == NULL)
    {
        return NULL;
    }
    

    int count = mx_count_substr(str, sub);
    char* res = mx_strnew(mx_strlen(str) - mx_strlen(sub)*count + mx_strlen(replace)*count);

    if (count == 0)
    {
        res = mx_strncpy(res, str, mx_strlen(str));
        return res;
    }

    replacing(res, str, sub, replace);
    for (int i = 0; i < count-1; i++)
    {
        char* temp = mx_strnew(mx_strlen(str) - mx_strlen(sub)*count + mx_strlen(replace)*count);
        replacing(temp, res, sub, replace);
        res = mx_strncpy(res, temp, mx_strlen(res));
        free(temp);
    }

    

    return res;
}

