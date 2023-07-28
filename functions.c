// functions.c
#include "main.h"

/************************* PRINT CHAR *************************/

int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
    // Implement this function if necessary
    // You can use it to handle the output for print_char
    UNUSED(c);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return 0;
}

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char c = va_arg(types, int);
    return handle_write_char(c, buffer, flags, width, precision, size);
}

/************************* PRINT A STRING *************************/

int handle_write_string(char *str, char buffer[], int flags, int width, int precision, int size)
{
    // Implement this function if necessary
    // You can use it to handle the output for print_string
    UNUSED(str);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return 0;
}

int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char *str = va_arg(types, char *);
    if (str == NULL)
        str = "(null)";

    return handle_write_string(str, buffer, flags, width, precision, size);
}

/************************* PRINT PERCENT SIGN *************************/

int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    UNUSED(types);
    buffer[0] = '%';
    return handle_write_char('%', buffer, flags, width, precision, size);
}

/************************* PRINT INT *************************/

int handle_write_int(long int n, char buffer[], int flags, int width, int precision, int size)
{
    // Implement this function if necessary
    // You can use it to handle the output for print_int
    UNUSED(n);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return 0;
}

int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    long int n = va_arg(types, long int);
    n = convert_size_number(n, size);

    return handle_write_int(n, buffer, flags, width, precision, size);
}

/************************* PRINT BINARY *************************/

int handle_write_binary(unsigned int n, char buffer[], int flags, int width, int precision, int size)
{
    // Implement this function if necessary
    // You can use it to handle the output for print_binary
    UNUSED(n);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return 0;
}

int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    unsigned int n = va_arg(types, unsigned int);
    return handle_write_binary(n, buffer, flags, width, precision, size);
}

