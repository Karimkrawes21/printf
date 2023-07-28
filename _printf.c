#include <stdio.h>
#include <stdarg.h>
#include "main.h"

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

int handle_print(const char *format, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

int get_flags(const char *format, int *i) {
    // Implementation of get_flags function (not provided in the code)
    // This function should parse and return the flags from the format specifier.
}

int get_width(const char *format, int *i, va_list list) {
    // Implementation of get_width function (not provided in the code)
    // This function should parse and return the width from the format specifier.
}

int get_precision(const char *format, int *i, va_list list) {
    // Implementation of get_precision function (not provided in the code)
    // This function should parse and return the precision from the format specifier.
}

int get_size(const char *format, int *i) {
    // Implementation of get_size function (not provided in the code)
    // This function should parse and return the size from the format specifier.
}

int _printf(const char *format, ...) {
    int i, printed = 0, printed_chars = 0, buff_ind = 0;
    int flags, width, precision, size;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return -1;

    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE) {
                print_buffer(buffer, &buff_ind);
                printed_chars += buff_ind;
            }
            printed_chars++;
        } else {
            print_buffer(buffer, &buff_ind);
            flags = get_flags(format, &i);
            width = get_width(format, &i, list);
            precision = get_precision(format, &i, list);
            size = get_size(format, &i);
            i++;
            printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
            if (printed == -1)
                return -1;
            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);
    printed_chars += buff_ind;

    va_end(list);

    return printed_chars;
}

void print_buffer(char buffer[], int *buff_ind) {
    if (*buff_ind > 0) {
        fwrite(buffer, 1, *buff_ind, stdout);
    }
    *buff_ind = 0;
}

