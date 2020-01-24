/*
** EPITECH PROJECT, 2019
** base_flag_bin
** File description:
** %b
*/

#include <stdarg.h>
#include "lib.h"

int base_flag_bin(int i, char *str, va_list flag_base_bin)
{
    if (str[i] == '%' && str[i + 1] == 'b') {
        i = i + 2;
        my_put_nbr(va_arg(flag_base_bin, int), BASE_BIN);
    }
    return (i);
}