#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer and resets the index.
 * @buffer: The buffer to print.
 * @buff_ind: Pointer to the buffer index.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	write(1, buffer, *buff_ind);
	*buff_ind = 0;
}

/**
 * _printf - Our custom printf function.
 * @format: The format string.
 * Return: The number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	char buffer[BUFF_SIZE];
	va_list args;
	int i, printed_chars = 0, buff_ind = 0;
	int flags, width, precision, size;

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed_chars += handle_print(format, &i, args, buffer, flags,
			width, precision, size);
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(args);
	return (printed_chars);
}

/**
 * print_char - Prints a character and updates the buffer index.
 * @types: Argument list.
 * @buffer: The buffer to store the character.
 * @buff_ind: Pointer to the buffer index.
 * Return: The number of characters printed.
 */
int print_char(va_list types, char buffer[], int *buff_ind)
{
	char c = va_arg(types, int);

	buffer[(*buff_ind)++] = c;
	if (*buff_ind == BUFF_SIZE)
		print_buffer(buffer, buff_ind);

	return (1);
}

/* Other functions (get_flags, get_width, get_precision, get_size, handle) */

