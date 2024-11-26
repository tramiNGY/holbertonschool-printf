#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	Datatype datatype[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};

	va_list printfall;
	int i, j;

	va_start(printfall, format);

	if (format == NULL)
	{
		va_end(printfall);
		return(-1);
	}

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			_putchar(format[i]);
		
		else
		{
			i++;
			j = 0;
			while (datatype[j].specifier != NULL)
			{
				if (format[i] == *datatype[j].specifier)
				{
					datatype[j].print_type(printfall);
					break;
				}
				j++;
			}
			if (datatype[j].specifier == NULL)
			{
				_putchar('%');
				_putchar(format[i]);
				va_arg(printfall, void *);
			}
		}
		i++;
	}

	va_end(printfall);
	return (0);	
}
