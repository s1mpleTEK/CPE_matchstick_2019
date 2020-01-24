/*
** EPITECH PROJECT, 2019
** base_flag_hex
** File description:
** %x %X %#x %#X
*/

#include <stdarg.h>
#include "lib.h"

int base_flag_hex(int i, char *str, va_list flag_base_hex)
{
    if (str[i] == '%' && str[i + 1] == 'x') {
        i = i + 2;
        my_put_nbr(va_arg(flag_base_hex,int), BASE_HEX_L);
    } else if (str[i] == '%' && str[i + 1] == 'X') {
        i = i + 2;
        my_put_nbr(va_arg(flag_base_hex, int), BASE_HEX_U);
    }
    if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'x') {
        i = i + 3;
        my_putstr("0x");
        my_put_nbr(va_arg(flag_base_hex,int), BASE_HEX_L);
    } else if (str[i] == '%' && str[i + 1] == '#' && str[i + 2] == 'X') {
        i = i + 3;
        my_putstr("0X");
        my_put_nbr(va_arg(flag_base_hex, int), BASE_HEX_U);
    }
    return (i);
}