#include "../inc/libmx.h"

char *mx_del_extra_whitespaces(const char *str) {
    if(str == NULL)
        return NULL;
    
    char *tmp = mx_strtrim(str);
    char *delete = mx_strnew(mx_strlen(tmp));
    int j = 0;
    for(int i = 0; i < mx_strlen(tmp); i++) {
        if (mx_isspace(tmp[i]) && mx_isspace(tmp[i - 1]))
            continue;
        if (tmp[i] != ' ' && mx_isspace(tmp[i]) && !mx_isspace(tmp[i - 1])) {
            delete[j] = ' ';
            j++;
            continue;
        }
        delete[j] = tmp[i];
        j++;
    }
    char *str_res = mx_strnew(mx_strlen(delete));
    for(int i = 0; i < mx_strlen(delete); i++) {
        str_res[i] = delete[i];
    }
    mx_strdel(&tmp);
    mx_strdel(&delete);
    return str_res;
}

