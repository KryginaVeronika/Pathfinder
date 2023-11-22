#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    if (c < 128) {
        mx_printchar((char)c);
    } else if (c < 2048) {
        mx_printchar((char)(0xC0 | ((c >> 6) & 0x1F)));
        mx_printchar((char)(0x80 | (c & 0x3F)));
    } else if (c < 65536) {
        mx_printchar((char)(0xE0 | ((c >> 12) & 0x0F)));
        mx_printchar((char)(0x80 | ((c >> 6) & 0x3F)));
        mx_printchar((char)(0x80 | (c & 0x3F)));
    } else if (c < 1114112) {
        mx_printchar((char)(0xF0 | ((c >> 18) & 0x07)));
        mx_printchar((char)(0x80 | ((c >> 12) & 0x3F)));
        mx_printchar((char)(0x80 | ((c >> 6) & 0x3F)));
        mx_printchar((char)(0x80 | (c & 0x3F)));
    }
}
