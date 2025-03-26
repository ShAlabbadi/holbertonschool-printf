#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include <limits.h>
/**
 * print_number - Prints an integer.
 * @args: The argument list containing the integer.
 *
 * Return: Number of characters printed.
 */
void print_number(int n)
{
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		print_number(n / 10);
	}
	putchar(n % 10 + '0');
}
/**
* print_char - Prints a single character.
* @args: The argument list containing the character.
*
* Return: Number of characters printed.
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
* print_string - Prints a string.
* @args: The argument list containing the string.
*
* Return: Number of characters printed.
*/

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
	{
		str = "(null)";
	}
	while (*str)
	{
		count += write(1, str++, 1);
	}
	return (count);
}

int print_percent(void)
{
	return (write(1, "%", 1));
}
/**
* _printf - Produces output according to a format.
* @format: A character string containing directives.
*
* Return: Number of characters printed (excluding null byte),
* or -1 if an error occurs.
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
	{
		return (-1);
	}
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
			{
				return (-1);
			}
			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_string(args);
			else if (*format == '%')
				count += print_percent();
			else if (*format == 'i' || *format == 'd')
			{
				int n = va_arg(args, int);
				print_number(n);
				count++;
			}
			else
			{
				count += write(1, "%", 1);
				count += write(1, format, 1);
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}

