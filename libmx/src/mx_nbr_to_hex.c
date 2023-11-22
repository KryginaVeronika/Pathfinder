#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        char *num = mx_strnew(1);
        *num = '0';
        return num;
    }
    char hex[20];
    int counter = 0;
    for(int i = 0; nbr > 0; i++) {
        nbr % 16 <= 9 ? (hex[i] = ((nbr % 16) + 48)) : (hex[i] = ((nbr % 16) + 87));
        counter++;
        nbr /= 16;
    }
    char *num = mx_strnew(counter);
    for(int i = 0; counter != 0; i++) {
        num[i] = hex[counter - 1];
        counter--;
    }

    return num;
} 
