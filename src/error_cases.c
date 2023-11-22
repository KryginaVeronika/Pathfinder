#include "../inc/pathfinder.h"

int mx_is_file_empty(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(EXIT_FAILURE);
    }

    char buffer;
    ssize_t bytes_read = read(fd, &buffer, 1);

    close(fd);

    if(bytes_read == 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void mx_invalid_line(int line_num) {
    mx_printerr("error: line ");
    line_num++;
    char* num = mx_itoa(line_num);
    mx_printerr(num);
    mx_printerr(" is not valid\n");
    exit(EXIT_FAILURE);
}

bool mx_isletter(int c) {
    return ((c > 64 && c < 91) || (c > 94 && c < 123));
}
bool mx_isdash(int c) {
    return c == 45;
}

bool mx_iscomma(int c) {
    return c == 44;
}


void mx_error_cases(const char* file) {
    if(mx_is_file_empty(file)) {
        exit(EXIT_FAILURE);
    }

    char *file_str = mx_file_to_str(file);
    int num = 0;

    char** lines_array = mx_strsplit(file_str,'\n');

    long islands_num = 0;

    for(int i = 0; i < mx_strlen(lines_array[0]); i++) {
        if(mx_isdigit(lines_array[0][i])) {
            num = atoi(&lines_array[0][i]);
            if (num <= 0) {
                mx_invalid_line(1);
            }
            islands_num += num;
            
        } else {
            mx_invalid_line(1);
        }
    } 

    if(islands_num >= MAX_INT) {
        mx_printerr("error: invalid number of islands\n");
        exit(EXIT_FAILURE);
    }

    for (int row = 1; lines_array[row] != NULL; row++) {
        for(int j = 0; j < mx_strlen(lines_array[row]); j++) {

            if(!mx_isletter(lines_array[row][j])) {
                mx_invalid_line(row);
            }
            while(mx_isletter(lines_array[row][j])) {
                j++;
            }
            if(lines_array[row][j] == '\0') {
                mx_invalid_line(row);
            }
            //check dash 
            if (!mx_isletter(lines_array[row][j]) && mx_isdash(lines_array[row][j])) {
                j++;

                //check second word
                while(mx_isletter(lines_array[row][j])) {
                    j++;
                }
                if(lines_array[row][j] == '\0') {
                    mx_invalid_line(row);
                }
                //check comma
                if (mx_iscomma(lines_array[row][j])) {
                    j++;
                } else {
                    mx_invalid_line(row);
                }

                for (;mx_isdigit(lines_array[row][j]); j++) {

                    num = mx_atoi(&lines_array[row][j]);
                    if(num < 0) {
                        if(num == 0 && !mx_isdigit(lines_array[row][j - 1])) {
                        mx_invalid_line(row);
                        }
                    }
                    if(num > MAX_INT) {
                        mx_invalid_line(row);
                    }
                } 

                if (lines_array[row][j] != '\0') {
                    mx_invalid_line(row);
                }
            } else {
                mx_invalid_line(row);
            }
                    
        }
    }
     mx_strdel(&file_str);
     mx_del_strarr(&lines_array);
}


