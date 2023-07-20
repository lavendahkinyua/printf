#include "main.h"
#include <stdarg.h>

/**
 * _putint - prints out an integer
 * Prototype: int _putint(va_list n);
 * @ap: argument pointer
 * Return: number of characters printed
 */
int _putint(va_list ap, flag_t *flags)
{
	int i = va_arg(ap, int);
	char *s;
	int len = 0;

	if (i >= 0)
	{
		if (flags->space && !flags->plus)
			len += _putchar(' ');
		else if (flags->plus && flags->space)
			len += _putchar('+');
		else if (flags->plus && !flags->space)
			len += _putchar('+');
	}
	if (i < 0)
	{
		len += _putchar('-');
		i *= -1;
	}
	s = converter(i, 10, 1);
	len += _puts(s);
	free(s);
	return (len);
}

/**
 * _putbin - prints out the binary representation of an integer
 * Prototype: int _putbin(lva_list n);
 * @ap: argument pointer
 * Return: the number of integer printed
 */
int _putbin(va_list ap, flag_t *flags)
{
	unsigned int i = va_arg(ap, unsigned int);
	char *s;
	int len;

	(void) flags;
	s = converter(i, 2, 0);
	len = _puts(s);
	free(s);
	return (len);
}

/**
 * _putuint - prints the unsigned decimal form of an integer
 * Prototype: int _putuint(va_list ap);
 * @ap: argument pointer
 * Return: the number of characters printed
 */
int _putuint(va_list ap, flag_t *flags)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *s = converter(n, 10, 0);
	int len = 0;

	if (flags->plus == '+')
		len += _putchar('+');
	len += _puts(s);
	free(s);
	return (len);
}


/**
 * _putoct - prints the hexadecimal form of an integer
 * Prototype: int _putheX(va_list ap);
 * @ap: argument pointer for retrieving integer to print
 * Return: the number of characters printed
 */
int _putoct(va_list ap, flag_t *flags)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *s;
	int len = 0;

	s = converter(n, 8, 0);
	if (s[0] != '0' && flags->hash)
		len += _putchar('0');
	len += _puts(s);
	free(s);
	return (len);
}
