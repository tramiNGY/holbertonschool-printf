#include "main.h"
#include <stdarg.h>
#include <stdio.h>
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
	int temp, temptemp, div = 1, len = 0, r;

	temp = va_arg(printfall, int);
	if (temp == 0)
	{
		_putchar('0');
		return (1);
	}
	if (temp < 0)
	{
		_putchar('-');
		temp *= -1;
		len += 1;
	}
	temptemp = temp;
	while (temptemp != 0)
	{
		temptemp /= 10, div *= 10;
		len++;
	}
	div /= 10;
	while (div != 0)
	{
		r = temp / div, div /= 10;
		if (r < 10)
			_putchar((r) + '0');
		else
			_putchar((r % 10) + '0');
	}
	return (len);
}
