#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

typedef struct type
{
	char *specifier;
	int (*print_type)(va_list printfall);
} Datatype;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list printfall);
int print_string(va_list printfall);
int print_percent();
int print_decimal(va_list printfall);

#endif
