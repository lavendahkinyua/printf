#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * @x: integer
 * Return: an integer representating the absolute value of the integer
 */
unsigned long int _abs(long int x)
{
	x = (x >= 0) ? x : -x;

	return (x);
}

unsigned long int _abs_big(long int x)
{
	return ((unsigned int)(x));
}
