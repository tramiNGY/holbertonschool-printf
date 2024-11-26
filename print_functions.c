#include "main.h"
#include "stdlib.h"

void print_char(va_list, printfall)
{
	char temp;

	temp = va_arg(printfall, char);
	_putchar(temp);
}

void print_string(va_list, printfall)
{
	int i;
	char *temp;
	
	*temp = va_arg(printfall, char*);
	i = 0;
	while (temp[i] != '\0')
	{
		_putchar(temp[i]);
		i++;
	}
}

void print_percent(va_list, printfall)
{
	char temp;

	temp = va_argv(printfall, char);
	_putchar('%');
}
