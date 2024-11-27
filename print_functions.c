#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_char - prints char argument from printfall
 * @printfall: va_list containing all the variadic arguments
 * to be printed
 * Remark1: printfall va_list already defined and initialized
 * in main function _printf
 * Remark2: temp copies current char argument value
 * before pointing to next argument
 * Remark3: when passed to va_arg, char type becomes int type
 * Return: returns 1 because 1 char is printed so
 * total number of char printed by _printf increases by 1 (count += 1)
*/

int print_char(va_list printfall)
{
	char temp;

	temp = va_arg(printfall, int);
	_putchar(temp);

	return (1);
}

/**
 * print_string - prints char * (string) argument from printfall
 * @printfall: va_list containing all the variadic arguments
 * to be printed
 * Remark1: temp copies current string argument value
 * before va_arg points to next argument
 * Return: returns i because each time 1 char in string is printed
 * i += 1, at end of string, i is total number of char in string
 * so add i to count
*/

int print_string(va_list printfall)
{
	int i;
	char *temp;

	temp = va_arg(printfall, char*);
	i = 0;

	if (temp == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (i + 6);
	}

	while (temp[i] != '\0')
	{
		_putchar(temp[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - prints char '%'
 * @printfall: no argument associated with specifier %%
 * so printfall parameter is ignored with line (void) printfall
 * Return: returns (1) because '%' is 1 char printed
 * so count increases by 1
*/

int print_percent(va_list printfall)
{
	(void) printfall;
	_putchar('%');
	return (1);
}
