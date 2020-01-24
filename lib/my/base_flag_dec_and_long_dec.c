/*
** EPITECH PROJECT, 2019
** base_flag_dec_and_long_dec
** File description:
** %d %i %ld %li
*/

#include <stdarg.h>
#include "lib.h"

int base_flag_dec_and_long_dec(int i, char *str, va_list flag_base_dec)
{
    if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i')) {
        i = i + 2;
        my_put_nbr(va_arg(flag_base_dec, int), BASE_DEC);
    }
    if (str[i] == '%' &&  str[i + 1] == 'u') {
        i = i + 2;
        my_put_nbr_u(va_arg(flag_base_dec, unsigned), BASE_DEC);
    }
    if (str[i] == '%' && str[i + 1] == 'l') {
        if (str[i + 2] == 'd' || str[i + 2] == 'i') {
            i = i + 3;
            my_put_nbr_l(va_arg(flag_base_dec, long int), BASE_DEC);
        }
    }
    if (str[i] == '%' && str[i + 1] == 'l' && str[i + 2] == 'u') {
        i = i + 3;
        my_put_nbr_l_u(va_arg(flag_base_dec, long unsigned), BASE_DEC);
    }
    return (i);
}