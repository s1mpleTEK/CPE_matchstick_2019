/*
** EPITECH PROJECT, 2019
** base_flag_hex
** File description:
** %lx %lX %#lx %#lX
*/

#include <stdarg.h>
#include "lib.h"

int base_flag_long_hex(int i, char *str, va_list flag_base_l_hex)
{
    if (str[i] == '%' && str[i + 1] == 'l' && str[i + 2] == 'x') {
        i = i + 3;
        my_put_nbr_l(va_arg(flag_base_l_hex, long int), BASE_HEX_L);
    } else if (str[i] == '%' && str[i + 1] == 'l' && str[i + 2] == 'X') {
        i = i + 3;
        my_put_nbr_l(va_arg(flag_base_l_hex, long int), BASE_HEX_U);
    }
    if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'l') {
        if (str[i + 3] == 'x') {
            i = i + 4;
            my_putstr("0x");
            my_put_nbr_l(va_arg(flag_base_l_hex, long int), BASE_HEX_L);
        } else if (str[i + 3] == 'X') {
            i = i + 4;
            my_putstr("0X");
            my_put_nbr_l(va_arg(flag_base_l_hex, long int), BASE_HEX_U);
        }
    }
    return (i);
}