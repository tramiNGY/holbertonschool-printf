#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

int print_char(va_list printfall)
{
	char temp;

	temp = va_arg(printfall, int);
	_putchar(temp);

	return (1);
}

int print_string(va_list printfall)
{
	int i;
	char *temp;
	
	temp = va_arg(printfall, char*);
	i = 0;
	while (temp[i] != '\0')
	{
		_putchar(temp[i]);
		i++;
	}
	return (i);
}

int print_percent()
{
	_putchar('%');
	return (1);
}
