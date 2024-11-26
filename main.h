#ifndef MAIN_H
#define MAIN_H

typedef struct type
{
	char *specifier;
	void (*print_type)(va_list printfall);
} Datatype;

int _putchar(char c);
int _printf(const char *format, ...);
void print_char(va_list printfall);
void print_string(va_list printfall);
void print_percent(va_list printfall);

#endif
