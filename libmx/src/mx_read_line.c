#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (lineptr == NULL || fd < 0 || buf_size == 0) {
        return -2; 
    }

    ssize_t read_bytes = 0;
    size_t total_bytes = 0;
    char *buffer = (char *)malloc(buf_size);
    if (buffer == NULL) {
        return -2; 
    }

    while (1) {
        char c;
        read_bytes = read(fd, &c, 1);

        if (read_bytes < 0) {
            free(buffer);
            return -2; 
        } else if (read_bytes == 0) {
            break; 
        }

        if (c == delim) {
            break;
        }

        if (total_bytes < buf_size - 1) {
            buffer[total_bytes] = c;
            total_bytes++;
        } else {
            size_t new_size = buf_size * 2;
            char *new_buffer = (char *)mx_realloc(buffer, new_size);

            if (new_buffer == NULL) {
                free(buffer);
                return -2;
            }

            buffer = new_buffer;
            buf_size = new_size;
            buffer[total_bytes] = c;
            total_bytes++;
        }
    }

    buffer[total_bytes] = '\0';
    *lineptr = buffer;

    if (read_bytes == 0 && total_bytes == 0) {
        free(buffer);
        return -1; 
    }

    return total_bytes;
}
