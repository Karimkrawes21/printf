#include <stdio.h>
#include <stdarg.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int chars_printed = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; // Move past the '%'
            switch (*format)
            {
            case 'c':
                _putchar(va_arg(args, int));
                chars_printed++;
                break;
            case 's':
            {
                const char *str = va_arg(args, const char *);
                while (*str != '\0')
                {
                    _putchar(*str);
                    chars_printed++;
                    str++;
                }
                break;
            }
            case '%':
                _putchar('%');
                chars_printed++;
                break;
            default:
                _putchar('%');
                _putchar(*format);
                chars_printed += 2;
                break;
            }
        }
        else
        {
            _putchar(*format);
            chars_printed++;
        }
        format++;
    }

    va_end(args);

    return chars_printed;
}

int main(void)
{
    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    len += _printf("Character: [%c]\n", 'H');
    len += _printf("String: [%s]\n", "I am a string !");
    len += _printf("Percent: [%%]\n");

    _printf("Total characters printed: %d\n", len);
    return 0;
}

