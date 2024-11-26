#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

int print_decimal(va_list printfall)
{
       	int temp;

	temp = va_arg(printfall, int);
	if (temp < 0)
		_putchar ('-');
	_putchar(temp);
	return (1);
}
