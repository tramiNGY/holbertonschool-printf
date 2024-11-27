#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - main function which prints each char in format
 * and each variadic argument of type char "c", string "s"
 * percent "%", decimal integer "d" or "i" and returns
 * total number of char printed (count)
 * any other type as specifier is considered non-valid types
 * and are simply printed as normal char in the standard output
 * @format: character string composed of zero or more directives
 * is the string to be printed in standard output
 * Remark1: Datatype struct defined in header and contains
 * char *specifier which is 1st letter of each type followed by
 * function pointer (*print_type) pointing to function
 * which prints arguments of associated type and returns
 * number of char printed to count value
 * Remark2: printfall is va_list containting
 * all the variadic arguments to print
 * Remark3: taking printfall as parameter of
 * datatype[j].print_type permits to not call va_arg macro
 * at that moment with unknown/variable type as 2nd parameter
 * Remark4: if datatype[j].specifier reaches NULL, it means
 * it has not found any valid specifier but has found a
 * non-valid one, so they are printed and counts increases
 * by 2 char (% and letter of non_valid specifier (ex: %u))
 * Return: returns int count which is the total number of
 * char printed by _printf in the standard output
*/


int _printf(const char *format, ...)
{
	Datatype datatype[] = {
		{"c", print_char}, {"s", print_string}, {"%", print_percent},
		{"d", print_decimal}, {"i", print_decimal}, {NULL, NULL}
};
	va_list printfall;
	int i, j, count;

	count = 0, i = 0;
	va_start(printfall, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{	va_end(printfall);
		return (count);
	}
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		} else
		{	i++, j = 0;
			while (datatype[j].specifier != NULL)
			{
				if (format[i] == *datatype[j].specifier)
				{
					count += datatype[j].print_type(printfall);
					break;
				} j++;
			}
			if (datatype[j].specifier == NULL)
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
				va_arg(printfall, int *);
			}
		} i++;
	} va_end(printfall);
	return (count);
}
