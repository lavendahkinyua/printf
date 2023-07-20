#include "main.h"

/**
 * _puthexX - prints the hexadecimal form of an integer
 * Prototype: int _puthexX(va_list ap);
 * @ap: argument pointer for retrieving integer to print
 * @lower: if 1 prints lowercase, if 0 uppercase representation
 * Return: the number of characters printed
 */
int _puthexX(va_list ap, int lower, flag_t *flags)
{
	unsigned int i = va_arg(ap, unsigned int);
	char *s;
	int len = 0;

	if (lower > 0)
	{
		s = converter(i, 16, 0);
		if (flags->hash && _strcmp(s, "0"))
			len += _puts("0X");
	}
	else
	{
		s = converter(i, 16, 1);
		if (flags->hash && _strcmp(s, "0"))
			len += _puts("0x");
	}

	len += _puts(s);
	free(s);
	return (len);
}

/**
 * _puthex - prints the hexadecimal form of an integer
 * Prototype: int _puthex(va_list ap);
 * @ap: argument pointer for retrieving integer to print
 * Return: the number of characters printed
 */
int _puthex(va_list ap, flag_t *flags)
{
	return (_puthexX(ap, 0, flags));
}

/**
 * _putheX - prints the hexadecimal form of an integer
 * Prototype: int _putheX(va_list ap);
 * @ap: argument pointer for retrieving integer to print
 * Return: the number of characters printed
 */
int _putheX(va_list ap, flag_t *flags)
{
	return (_puthexX(ap, 1, flags));
}
