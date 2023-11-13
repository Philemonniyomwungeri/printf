#include "main.h"

/**
 * print_char - Prints a character.
 * @list: A va_list representing the arguments.
 * @buffer: A buffer to store the output.
 *
 * Return: The number of printed characters.
 */
int print_char(va_list list, char buffer[])
{
    char c = va_arg(list, int);
    buffer[0] = c;
    return 1;
}

/**
 * handle_print - Handles the printing process based on the format specifier.
 * @fmt: The format specifier.
 * @list: A va_list representing the arguments.
 * @buffer: A buffer to store the output.
 *
 * Return: The number of printed characters.
 */
int print_char(va_list list, char buffer[])
{
    char c = va_arg(list, int);
    buffer[0] = c;
    return 1;
}


