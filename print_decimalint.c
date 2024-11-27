#include "main.h"
#include <stdlib.h>
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

int print_decimal(va_list printfall)
{
	int temp;

	temp = va_arg(printfall, int);
	if (temp < 0)
		_putchar ('-');
	_putchar(temp);
	return (1);
}
