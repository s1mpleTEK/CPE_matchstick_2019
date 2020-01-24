/*
** EPITECH PROJECT, 2019
** basic_flag
** File description:
** %s %c %%
*/

#include <stddef.h>
#include <stdarg.h>
#include "lib.h"

int basic_flag(int i, char *str, va_list flag_basic)
{
    if (str[i] == '%' && str[i + 1] == 's') {
        i = i + 2;
        my_putstr(va_arg(flag_basic, char *));
    }
    if (str[i] == '%' && str[i + 1] == '%') {
        i = i + 1;
    }
    if (str[i] == '%' &&  str[i + 1] == 'c') {
        i = i + 2;
        my_putchar(va_arg(flag_basic, int));
    }
    return (i);
}