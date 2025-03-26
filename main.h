#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int _printf(const char *format, ...);
void print_number(int n);
#endif
