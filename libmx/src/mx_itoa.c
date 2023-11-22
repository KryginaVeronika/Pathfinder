#include "../inc/libmx.h"

char *mx_itoa (int num) {
    int len = 0;
    long int temp = num;

    if (num == 0) 
        return "0";
    while (num) {
        num /= 10;
        len++;
    }
    char *res = mx_strnew(len);
    int min = 0;
    if (temp < 0) {
        len++;
        temp *= -1;
        res[0] = '-';
        min = 1;
    }
    for (int i = len  - 1; i >= min; temp /= 10) {
        res[i--] = (temp % 10) + 48;
    }

    return res;
}

