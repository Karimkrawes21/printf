#include "main.h"

/**
 * get_size - Calculates the size for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current index in the format string.
 * Return: Size.
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    if (format[curr_i] != 'h' && format[curr_i] != 'l')
        return size;

    if (format[curr_i] == 'h' && format[curr_i + 1] == 'h')
    {
        size = S_CHAR;
        curr_i++;
    }
    else if (format[curr_i] == 'h')
    {
        size = S_SHORT;
    }
    else if (format[curr_i] == 'l' && format[curr_i + 1] == 'l')
    {
        size = S_LLONG;
        curr_i++;
    }
    else if (format[curr_i] == 'l')
    {
        size = S_LONG;
    }

    *i = curr_i;

    return size;
}

