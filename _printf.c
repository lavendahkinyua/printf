#include "main.h"
#include <stdarg.h>

/**
 * _printf - writes out to stdout by producing an output according to a format
 * Prototype: int _printf(const char *format, ...)
 * @format: a string that contains eventual directive to print variables value
 * Return: number of characters printed if no error, else -1 is returned
 */
int _printf(const char *format, ...)
{
	int i, noc, x;
	va_list ap;
	flag_t flags = {0, 0, 0};

	if (!_strcmp(format, "%") || _strcmp(format, "% ") == 32)
		return (-1);

	va_start(ap, format);
	noc = 0;
	for (i = 0; i < _strlen(format); i++)
	{
		if (format[i] == '%')
		{
			i++;
			while (is_flag(format[i]))
			{
				set_flag(format[i], &flags, &x);
				i++;
			}
			if (is_spec(format[i]) && get_printer(format[i]))
			{
				noc += get_printer(format[i])(ap, &flags);
				unset_flag(&flags);
			}
			else
			{
				if (format[i])
				{
					i--;
					noc += _putchar(format[i]);
				}
			}
		}
		else
			noc += _putchar(format[i]);
	}
	va_end(ap);
	return (noc);
}
