#include "main.h"

/**
* _strchr - locates a character in a string
* @s: pointer to the string
* @c: character to locate
* Return: pointer to the first occurrence
* of the character c in the string s, or NULL
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			return (s);
		}
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * converter - converts an integer into another form based on a base
 * Prototype: char *converter(long int n, int base, int lower);
 * @n: integer to convert
 * @base: base of the conversion (2, 8, 10, 16, for example)
 * @l: an integer. When posititve, letters are lowercase, otherwise uppercase
 * Return: converted integer as a string
 */
char *converter(unsigned long int n, int base, int l)
{
	char *s, *digits;
	unsigned long int i, j;

	if (n == 0)
		return (_strdup("0"));

	if (l > 0)
		digits = _strdup("0123456789abcdef");
	else
		digits = _strdup("0123456789ABCDEF");

	i = 0;
	j = _abs(n);
	for (; j > 1 || i < 63; j /= base, i++)
		;
	s = malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);

	i = 0;
	j = _abs(n);
	while (j != 0)
	{
		s[i++] = digits[j % base];
		j /= base;
	}
	s[i] = '\0';
	rev_str(s);
	free(digits);
	return (s);
}

/**
 * get_printer - Gets the function prints based on a specifier
 * Prototype: int (*get_printer(char spec))(va_list ap);
 * @spec: specifier
 * Return: the function pointer of the specifier if found, otherwise NULl
 */
int (*get_printer(char spec))(va_list, flag_t*)
{
	spec_handler_t specs[] = {
		{'c', _putchr},
		{'s', _putstr},
		{'x', _puthex},
		{'X', _putheX},
		{'o', _putoct},
		{'u', _putuint},
		{'i', _putint},
		{'d', _putint},
		{'b', _putbin},
		{'S', _putnpt},
		{'%', _putprt},
		{'p', _putadd},
		{'\0', NULL}
	};
	int i;

	i = 0;
	while (i < 12)
	{
		if ((specs[i].spec) == spec)
			return (specs[i].func);
		i++;
	}

	return (specs[i].func);
}

/**
 * is_spec - Checks if the arg is a valid specifier
 * Prototype: int is_spec(const char spec);
 * @spec: single character, format specifier to check
 * Return: 1 if the specified specifier is a valid specifier, else 0.
 */
int is_spec(const char spec)
{
	return (_strchr("csdixXuobS%p", spec) != NULL);
}

/**
 * is_flag - Checks if the arg is a valid flag
 * Prototype: int is_flag(const char flag);
 * @spec: single character, format specifier to check
 * Return: 1 if the specified specifier is a valid flag, else 0.
 */
int is_flag(const char flag)
{
	return (_strchr(" +#", flag) != NULL);
}
