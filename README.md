
![printf image image (1)](https://www.commentcoder.com/static/bd7bd17f9fccb49b563e643f73bc87b3/b17f8/c-printf.jpg)

# **Printf simplified**

## Description
This project aims to partially replicate the function printf of stdio.h library in C programming (see man printf (3)). It includes notions like variadic functions, structures, function pointers.

The main function takes inputed format and displays string and arguments of implemented valid types before returning the total number of characters printed to standard output except NULL byte used to end output to strings.

The code only handles 5 format specifiers: char (%c), string (%s), percentage (%%), decimal integer (%d or %i).
Other specifiers not implemented here will be printed as regular characters and their associated arguments will be ignored.

## Prototype
int _printf(const char *format, ...)
- format is a character string
- Writes to the standard output
- Returns count: total number of char printed

## Files
[_printf.c](https://github.com/tramiNGY/holbertonschool-printf/blob/main/_printf.c)
Main function taking input string to be printed and returning number of characters printed to standard output. Also points to sub-functions of allowed specifiers printing functions.

[_putchar.c](https://github.com/tramiNGY/holbertonschool-printf/blob/main/_putchar.c)
Replica of putchar function used to print one character to the standard output.

[print_functions.c](https://github.com/tramiNGY/holbertonschool-printf/blob/main/print_functions.c)
Contains the sub-functions of allowed specifiers char (%d), string (%s) and percentage (%%) which prints each character in the standard output and returns number of characters printed to main function _printf.

[print_decimalint.c](https://github.com/tramiNGY/holbertonschool-printf/blob/main/print_decimalint.c)
Contains the sub-function of allowed specifier decimal integer (%d and %i: both are equivalent for printf function) which prints each digit of the int number and returns number of characters printed (+1 for minus sign if int negative) to main function _printf.

[main.h](https://github.com/tramiNGY/holbertonschool-printf/blob/main/main.h)
Header containing all the prototypes and structure definition for allowed specifiers and print functions associated.

## Format specifiers
| Type | Specifier |
| :---------------: |:---------------:|
|char | %c |
|string | %s |
| percentage | %% |
| decimal integer | %d and %i |

## Other requirements
- Betty style: Holbertonschool code layout rules
- Not allowed to use global variables
- No more than 5 functions per File
- Main.c is not present in repo but in the README
- Authorized functions and macros: write, va_start, va_end, va_copy, va_arg (malloc and free but not used).
- If not specified, any test case should do the same as printf.

## Flowchart
![printf flowchart image (1)](https://cdn.discordapp.com/attachments/1308098368370638849/1311666482207264778/Flowchart_printf.png?ex=6749b01a&is=67485e9a&hm=08c90f6e1593cbe45d6c7e10471d2992df0bd8f4343507dbb16154ff6b5d72d6&)


## Compilation
The command used to compile in GNU under Ubuntu 20.04 LTS is:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
```
## Test code
### Main test
```
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    _printf("%%%%%\n");
    printf("%%%%%\n");
    _printf("%%%\n");
    printf("%%%\n");
    _printf("Character and unsigned int %c %u\n", 'A', ui);
    printf("Character and unsigned int %c %u\n", 'A', ui);
    _printf("Unsigned int and character %u %c\n", ui, 'B');
    printf("Unsigned int and character %u %c\n", ui, 'B');
    _printf("Character NULL byte %c\n", '\0');
    printf("Character NULL byte %c\n", '\0');
    _printf("Percentage alone %\n");
    printf("Percentage alone %\n");
    _printf("Percentage! %!\n");
    printf("¨Percentage! %!\n");
    _printf("Unknown specifier K %K\n");
    printf("Unknown specifier K %K\n");
    len = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    len2 = printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    printf(NULL);
    _printf(NULL);
    _printf("Negative:[%d]\n", -1024);
    printf("Negative:[%d]\n", -1024);
    _printf("Negative:[%d]\n", -4000);
    printf("Negative:[%d]\n", -4000);
    _printf("Negative:[%d]\n", -2147483647);
    printf("Negative:[%d]\n", -2147483647);
    _printf("Negative:[%d]\n", 2147483648);
    printf("Negative:[%d]\n", 2147483648);
    _printf("Negative:[%d]\n", -2147483649);
    printf("Negative:[%d]\n", -2147483649);
    return (0);
}
```
### Test Output
```
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[%u]
Unsigned:[2147484671]
Unsigned octal:[%o]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[%x, %X]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[%p]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
%%%
%%%
%%
%%
Character and unsigned int A %u
Character and unsigned int A 2147484671
Unsigned int and character %u B
Unsigned int and character 2147484671 B
Character NULL byte
Character NULL byte
Percentage alone %
Percentage alone %
Percentage! %!
Percentage! %!
Unknown specifier K %K
Unknown specifier K %K
Complete the sentence: You (null) nothing, Jon Snow.
Complete the sentence: You (null) nothing, Jon Snow.
Negative:[-1024]
Negative:[-1024]
Negative:[-4000]
Negative:[-4000]
Negative:[-2147483647]
Negative:[-2147483647]
Negative:[-2147483648]
Negative:[-2147483648]
Negative:[2147483647]
Negative:[2147483647]
```

## Bugs
In this simplified project the function:
- Does not reproduce the buffer handling of the C library printf function
- Does not handle the flag characters
- Does not handle field width
- Does not handle precision
- Does not handle the length modifiers

## Authors

[Tra Mi NGUYEN](https://github.com/tramiNGY)

[Tom DIBELLONIO](https://github.com/totomus83)![badge github image (1)](https://badgen.net/badge/icon/github?icon=github&label)
