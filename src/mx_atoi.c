#include "../inc/pathfinder.h"

bool mx_isspace(int c) {
    if (c > 8 && c < 14) 
        return true;
    if (c == 32)
        return true;
    return false;
}

int mx_atoi(const char *str) {
    int num = 0;
    int x = 1;
    int i = 0;
    
    while (mx_isspace(str[i]))
        i++;
    if (str[i] == '-') {
        x = -1;
        i++;
    }
    for( ; !mx_isspace(str[i]) && str[i] != '\0'; i++) {
        if (!mx_isdigit(str[i]) && !mx_isspace(str[i])) {
            if (num != 0)
                break;
            return 0;
        }
        num = (num * 10 + str[i]) - 48;
    }
    return x * num;
}

