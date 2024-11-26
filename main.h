#ifndef MAIN_H
#define MAIN_H

typedef struct type
{
	char *specifier;
	void (*print_type)(va_list printfall);
} Datatype;

int _putchar(char c);
int _printf(const char *format, ...);
void print_char(va_list, printfall);
void print_str(va_list, printfall);
void print_prct (va_list, printfall);

#endif
