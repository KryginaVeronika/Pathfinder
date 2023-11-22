#include "../inc/libmx.h"

int partition(char **arr, int left, int right, int *swaps) {
    char *pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i < j) {
        while (mx_strlen(arr[i]) < mx_strlen(pivot))
            i++;
        while (mx_strlen(arr[j]) > mx_strlen(pivot))
            j--;

        if (i <= j) {
            if (mx_strlen(arr[i]) != mx_strlen(arr[j])) {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                *swaps = *swaps + 1;
            }
            i++;
            j--;
        }
    }
    return i;
}

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL | right < 0) {
        return -1;
    }

    int swaps = 0;
    if (left < right) {
        int index = partition(arr, left, right, &swaps);

        swaps += mx_quicksort(arr, left, index - 1);
        swaps += mx_quicksort(arr, index, right); 
    }

    return swaps;
}

