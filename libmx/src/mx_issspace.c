#include "../inc/libmx.h"

bool mx_isspace(int c) {
    return (c > 8 && c < 14) || (c == 32);
}

