#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char*hex) {
    int len = mx_strlen(hex);
    int digit;
    unsigned long result = 0;
    for(int i = 0; i < len; i++) {
        if (hex[i] > 47 && hex[i] < 58)
            digit = hex[i] - 48;
        else if (hex[i] > 64 && hex[i] < 71)
            digit = hex[i] - 55;
        else if (hex[i] > 96 && hex[i] < 103)
            digit = hex[i] - 87;
        else 
            digit = 0;
            
        result += digit * mx_pow(16, len - i - 1);
    }
    return result;
}

