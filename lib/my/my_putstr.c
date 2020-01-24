/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Displays the characters of a string one-by-one.
*/

#include <unistd.h>
#include "lib.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        my_putchar(str[i]);
    }
}

void my_putstr_upper_s(char *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] >= 127 || str[i] < 32) {
            my_putstr("\\");
            int alpha = str[i];
            my_put_nbr(alpha, BASE_OCT);
        } else {
            my_putchar(str[i]);
        }
    }
}
