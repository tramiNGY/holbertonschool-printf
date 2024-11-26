#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	Datatype datatype[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_decimal},
		{"i", print_decimal},
		{NULL, NULL}
	};

	va_list printfall;
	int i, j, count;

	count = 0;

	va_start(printfall, format);

	if (format == NULL)
	{
		va_end(printfall);
		return(count);
	}

	i = 0;
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}

		else
		{
			i++;
			j = 0;
			while (datatype[j].specifier != NULL)
			{
				if (format[i] == *datatype[j].specifier)
				{
					count += datatype[j].print_type(printfall);
					break;
				}
				j++;
			}
			if (datatype[j].specifier == NULL)
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
				va_arg(printfall, int *);
			}
		}
		i++;
	}

	va_end(printfall);
	return (count);	
}
