/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** Print something
*/

#include <stddef.h>
#include <stdarg.h>
#include "lib.h"

void my_printf(char *str, ...)
{
    va_list arguments_;
    va_start(arguments_,str);
    int i = 0;

    for (i = 0; str[i] != '\0'; i = i + 1) {
        i = basic_flag(i, str, arguments_);
        i = base_flag_bin(i, str, arguments_);
        i = base_flag_oct_and_long_oct(i, str, arguments_);
        i = base_flag_dec_and_long_dec(i, str, arguments_);
        i = base_flag_hex(i, str, arguments_);
        i = base_flag_long_hex(i, str, arguments_);
        i = base_flag_pointer(i, str, arguments_);
        i = base_flag_upper_s(i, str, arguments_);
        my_putchar(str[i]);
    }
    va_end(arguments_);
}