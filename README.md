.Dd Mar 28, 2025
.Dt _PRINTF 3
.Os
.Sh NAME
.Nm _printf
.Nd Custom implementation of the printf function in C.
.Sh SYNOPSIS
.In main.h
.Ft int
.Fn _printf "const char *format" "..."
.Sh DESCRIPTION
The
.Nm
function is a custom implementation of the standard
.Xr printf 3
function. It formats and prints output to the standard output
based on the format string provided and the corresponding arguments.

The function uses variadic arguments through the macros
.Xr va_start 3 ,
.Xr va_arg 3 ,
and
.Xr va_end 3 .

Supported format specifiers include:
.Bl -tag -width Ds
.It %c
Prints a single character.
.It %s
Prints a string.
.It %d
Prints a signed decimal integer.
.It %i
Prints a signed decimal integer.
.It %%
Prints a percent sign.
.El
.Sh RETURN VALUES
Returns the number of characters printed (excluding the null byte).
Returns
.Fa -1
if an error occurs.
.Sh EXAMPLES
.Bd -literal
#include "main.h"

int main(void)
{
    _printf("Character: [%c]\\n", 'A');
    _printf("String: [%s]\\n", "Hello, world!");
    _printf("Integer: [%d]\\n", 123);
    _printf("Percent: [%%]\\n");
    return (0);
}
.Ed
.Sh FILES
.Bl -tag -width main.h -compact
.It Pa main.h
Header file with function prototypes.
.It Pa _printf.c
Main function implementation.
.It Pa get_specifier.c
Handles format specifier selection.
.It Pa handlers.c
Handles character, string, and integer formatting.
.It Pa utils.c
Contains helper utility functions.
.El
.Sh AUTHORS
Abdulaziz Talal Almutairi  
Shurooq Alabbadi
.Sh SEE ALSO
.Xr printf 3 ,
.Xr write 2 ,
.Xr va_start 3 ,
.Xr va_arg 3 ,
.Xr va_end 3

