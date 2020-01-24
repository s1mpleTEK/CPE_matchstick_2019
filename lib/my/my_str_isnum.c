/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** Returns 1 if the given string contains only digits.
*/

#include "lib.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int my_str_isnum_neg(char const *str)
{
    if (str[1] == '\0')
        return (84);
    for (int i = 1; str[i] != '\0'; i++)
        if (!is_digit(str[i]))
            return (84);
    return (1);
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!is_digit(str[i]))
            return (84);
    return (1);
}
