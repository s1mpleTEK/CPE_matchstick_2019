/*
** EPITECH PROJECT, 2019
** base_flag_oct_and_long_oct
** File description:
** %o %lo %#o %#lo
*/

#include <stdarg.h>
#include "lib.h"

int base_flag_oct_and_long_oct(int i, char *str, va_list flag_base_oct)
{
    if (str[i] == '%' && str[i + 1] == 'o') {
        i = i + 2;
        my_put_nbr(va_arg(flag_base_oct, int), BASE_OCT);
    }
    if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'o') {
        i = i + 3;
        my_putstr("0");
        my_put_nbr(va_arg(flag_base_oct, int), BASE_OCT);
    }
    if (str[i] == '%' && str[i + 1] == 'l' && str[i + 2] == 'o') {
        i = i + 3;
        my_put_nbr_l(va_arg(flag_base_oct,long int), BASE_OCT);
    }
    if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'l') {
        if (str[i + 3] == 'o') {
            i = i + 4;
            my_putstr("0");
            my_put_nbr_l(va_arg(flag_base_oct, long int), BASE_OCT);
        }
    }
    return (i);
}