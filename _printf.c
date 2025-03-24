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
void _s(va_list args)
{

	char *str = va_arg(args, char*);

	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		putchar (*str);
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

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
			}
			else if (*format == 'c')
			{
				int ch = va_arg(args, int);

				putchar(ch);
			}
			else if (*format == 's')
			{
				_s(args);
			}
			else
			{
				putchar('%');
				putchar(*format);
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (0);
}

