/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Displays tnumbers in a string
*/

#include <stdlib.h>

int my_getnbr(char *str)
{
    int i = 0;
    int n = 0;

    if (str == NULL)
        return (84);
    if (str[0] == '-' && str[1] != '\0')
        i++;
    for (;str[i] != '\0'; i++) {
        n = n * 10;
        n = n + str[i] - '0';
    }
    if (str[0] == '-')
        return (-1 * n);
    else
        return (n);
}