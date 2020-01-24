/*
** EPITECH PROJECT, 2019
** base_flag_pointer
** File description:
** %p
*/

#include <stdarg.h>
#include "lib.h"

int base_flag_pointer(int i, char *str, va_list flag_pointer)
{
    if (str[i] == '%' && str[i + 1] == 'p') {
        i = i + 2;
        my_putstr("0x");
        my_put_nbr_llui(va_arg(flag_pointer, LLUI), BASE_HEX_L);
    }
    return (i);
}