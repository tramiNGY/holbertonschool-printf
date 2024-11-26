#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

void print_decimal(va_list printfall)
{
       	int temp;

	temp = va_arg(printfall, int);
	if (temp < 0)
		_putchar ('-');
	_putchar(temp);
}
