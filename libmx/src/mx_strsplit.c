#include "../inc/libmx.h"


char **mx_strsplit(char const *s, char c) {
    if (s == NULL)
        return NULL;

    char **arr = (char **) malloc(sizeof(char *) * (mx_count_words(s, c) + 1));
    int size = 0;
    int num = 0;
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != c && size == 0)
            num = i;

        if (s[i] != c && s[i] != 0)
            size++;

        if (size > 0 && (s[i + 1] == c || s[i + 1] == 0)) {
            arr[j] = mx_strnew(size);
            arr[j] = mx_strncpy(arr[j], &(s[num]), size);
            size = 0;
            j++;
        }
    }

    arr[j] = NULL;

    return arr;
}
