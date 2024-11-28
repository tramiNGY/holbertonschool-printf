#include "main.h"
#include <stdarg.h>
#include <limits.h>

/**
 * print_decimalint - prints decimal integer (base 10) from printfall
 * @printfall: ba_list containing all the variadic arguments
 * to be printed
 * Remark1: temp copies current int argument value
 * before va_arg points to next argument
 * Remark2: value of temp transfered to n to handle all scenarios
 * Return: return number of digits printed
 * if number is negative add +1 to count for the '-' character
 */

int print_decimalint(va_list printfall)
{
	int temp, div, len;
	unsigned int number;

	div = 1, len = 0;
	temp = va_arg(printfall, int);
	if (temp == INT_MIN)
	{
		len += _putchar('-');
		number = (unsigned int)(-(temp + 1)) + 1;
	}
	else if (temp < 0)
	{
		_putchar('-');
		number = -temp;
		len++;
	}
	else
	{
		number = temp;
	}
	while (number / div > 9)
	{
		div *= 10;
	}
	while (div != 0)
	{
		if (number / div < 10)
			_putchar((number / div) + '0');
		else
			_putchar(((number / div) % 10) + '0');
		div /= 10;
		len++;
	}
	return (len);
}
