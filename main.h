#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct type - Struct type
 * @specifier: the data type specifier for _printf
 * @print_type: function print associated with the specifier
 * for each data type
*/

typedef struct type
{
	char *specifier;
	int (*print_type)(va_list printfall);
} Datatype;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list printfall);
int print_string(va_list printfall);
int print_percent(va_list printfall);
int print_decimal(va_list printfall);

#endif
