/*
** EPITECH PROJECT, 2019
** MY8PUT8NBR
** File description:
** description
*/

#include <unistd.h>
#include "lib.h"

void my_put_nbr(int nb, char *base)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb >= my_strlen(base)) {
        my_put_nbr(nb / my_strlen(base), base);
    }
    write(1, &base[nb % my_strlen(base)], 1);
}

void my_put_nbr_l(long int nb, char *base)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb >= my_strlen(base)) {
        my_put_nbr_l(nb / my_strlen(base), base);
    }
    write(1, &base[nb % my_strlen(base)], 1);
}

void my_put_nbr_u(unsigned nb, char *base)
{
    if (nb >= my_strlen(base)) {
        my_put_nbr_u(nb / my_strlen(base), base);
    }
    write(1, &base[nb % my_strlen(base)], 1);
}

void my_put_nbr_l_u(long unsigned nb, char *base)
{
    if (nb >= my_strlen(base)) {
        my_put_nbr_l_u(nb / my_strlen(base), base);
    }
    write(1, &base[nb % my_strlen(base)], 1);
}

void my_put_nbr_llui(long long unsigned int nb, char *base)
{
    if (nb >= my_strlen(base)) {
        my_put_nbr_l_u(nb / my_strlen(base), base);
    }
    write(1, &base[nb % my_strlen(base)], 1);
}