#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _s - Function to print a string.
 * @args: List of arguments from _printf.
 *
 * Description: Extracts a string argument from the variable argument list
 * and prints it. If the string is NULL, it prints "(null)" instead.
 */
void _s(va_list args, int *count)
{

	char *str = va_arg(args, char*);

	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		putchar (*str);
		(*count)++;
		str++;
	}
}

/**
 * _printf - Custom printf function.
 * @format: Format string containing text and format specifiers.
 *
 * Description: A simplified version of printf that supports
 * the following format specifiers: %c (character), %s (string),
 * and %% (percent sign).
 * Return: Return the value
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
			format++;
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				int ch = va_arg(args, int);

				putchar(ch);
				count++;
			}
			else if (*format == 's')
			{
				_s(args, &count);
			}
			else
			{
				format++;
				count++;
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
	return (count);
}

