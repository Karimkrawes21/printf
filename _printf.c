#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of printf function with limited specifiers.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move to the next character after '%'

            // Handle each conversion specifier
            switch (*format)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;

                case 's':
                {
                    const char *str = va_arg(args, const char *);
                    while (*str)
                    {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }

                case '%':
                    putchar('%');
                    count++;
                    break;

                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}

int main(void)
{
    int len = _printf("Let's try a custom _printf function.\n");
    _printf("Number of characters printed: %d\n", len);
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, world!");
    _printf("Percentage sign: %%\n");

    return 0;
}
