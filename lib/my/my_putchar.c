/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** Implementation of my_putchar.
*/

#include <unistd.h>
#include "lib.h"

void     my_putchar(char c)
{
    write(1, &c, 1);
}
