/*
** EPITECH PROJECT, 2019
** base_flag_upper_s
** File description:
** %S
*/

#include <stdarg.h>
#include "lib.h"

int base_flag_upper_s(int i, char *str, va_list flag_base_upper_s)
{
    if (str[i] == '%' && str[i + 1] == 'S') {
        i = i + 2;
        my_putstr_upper_s(va_arg(flag_base_upper_s, char *));
    }
    return (i);
}