#include "main.h"
#include <stdarg.h>

/**
 * print_decimal - prints decimal integer (base 10) from printfall
 * @printfall: ba_list containing all the variadic arguments
 * to be printed
 * Remark1: temp copies current int argument value
 * before va_arg points to next argument
 * Return: return number of digits printed
 * DESCRIPTION TO BE UPDATED AFTER FUNCTION CORRECTION
 */

int print_decimalint(va_list printfall)
{
	int temp, temptemp,templen, div, len, r;

	temp = va_arg(printfall, int);
	if (temp < 0)
	{
		_putchar('-');
		temp *= -1;
	}
	temptemp = temp;
	len = 0;
	while (temptemp != 0)
	{
		temptemp /= 10;
		len++;
	}
	templen = len;
	div = 1;
	while (templen != 1)
	{
		div *= 10;
		templen--;
	}
	while(div != 0)
	{
		r = temp / div;
		div /= 10;
		if (r < 10)
			_putchar((r) + '0');
		else
			_putchar((r % 10) + '0');
	}
	return (len);
}
