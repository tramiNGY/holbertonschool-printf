#include "main.h"
#include <stdarg.h>
#include <limits.h>
/**
 * print_decimalint - prints decimal integer (base 10) from printfall
 * @printfall: ba_list containing all the variadic arguments
 * to be printed
 * Remark1: temp copies current int argument value
 * before va_arg points to next argument
 * Return: return number of digits printed
 * DESCRIPTION TO BE UPDATED AFTER FUNCTION CORRECTION
 */
int print_decimalint(va_list printfall)
{
	int temp, div, len;
	unsigned int min;

	div = 1, len = 0;
	temp = va_arg(printfall, int);
	if (temp == INT_MIN)
	{
		len += _putchar('-');
		min = (unsigned int)(-(temp + 1)) + 1;
	}
	else if (temp < 0)
	{
		_putchar('-');
		min = -temp;
		len++;
	}
	else
	{
		min = temp;
	}
	while (min / div > 9)
	{
		div *= 10;
	}
	while (div != 0)
	{
		if (min / div < 10)
			_putchar((min / div) + '0');
		else
			_putchar(((min / div) % 10) + '0');
		div /= 10;
		len ++;
	}
	return (len);
}
