#include "../inc/libmx.h"

void mx_printint(int n) {
    if(n == 0) {
        mx_printchar('0');
        return;
    }
    char arr[12];
    int i;
    long int new_n = n;
    if (n < 0) {
        new_n *= -1;
        mx_printchar('-');
    }

    for(i = 0; new_n != 0; i++) {
        arr[i] = new_n % 10;
        new_n /= 10;
    }

    for (int j = i - 1; j >= 0; j--) {
        mx_printchar(48 + arr[j]);
    }
}

