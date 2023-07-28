#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * write_handle_char - Prints a character
 * @c: The character to be printed.
 * @buffer: Buffer array used for printing.
 * @flags: Active flags for formatting.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int write_handle_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char padding_char = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padding_char = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padding_char;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a number
 * @is_negative: Indicates if the number is negative.
 * @ind: Index of the number in the buffer.
 * @buffer: Buffer array used for printing.
 * @flags: Active flags for formatting.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padding_char = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';
	if (is_negative)
		extra_char = '-';
	else if (flags & F_PLUS)
		extra_char = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padding_char, extra_char));
}

/**
 * write_num - Write a number using a buffer
 * @ind: Index at which the number starts on the buffer.
 * @buffer: Buffer array used for printing.
 * @flags: Flags for formatting.
 * @width: Width specifier.
 * @prec: Precision specifier.
 * @length: Length of the number.
 * @padding_char: Padding character.
 * @extra_char: Extra character.
 *
 * Return: Number of printed characters.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padding_char, char extra_char)
{
	int i, padding_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no character is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padding_char = ' '; /* Width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padding_char = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_char != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padding_char;
		buffer[i] = '\0';
		if (flags & F_MINUS && padding_char == ' ')/* Assign extra char to the left of buffer */
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padding_char == ' ')/* Extra char to the left of buffer */
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padding_char == '0')/* Extra char to the left of padding */
		{
			if (extra_char)
				buffer[--padding_start] = extra_char;
			return (write(1, &buffer[padding_start], i - padding_start) +
				write(1, &buffer[ind], length - (1 - padding_start)));
		}
	}
	if (extra_char)
		buffer[--ind] = extra_char;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the number is negative.
 * @ind: Index at which the number starts in the buffer.
 * @buffer: Array of characters.
 * @flags: Flags specifiers.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of written characters.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padding_char = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no character is printed */

	if (precision > 0 && precision < length)
		padding_char = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padding_char;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Assign extra char to the left of buffer [buffer > padding] */
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Assign extra char to the left of padding [padding > buffer] */
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address

