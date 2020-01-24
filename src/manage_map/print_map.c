/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** print_map
*/

#include "lib.h"
#include "my.h"

static void make_line(int tmp, int i, int *map)
{
    int total_space = (tmp - ((i * 2) + 1));
    int add_space_right = (((i * 2) + 1) - map[i]);

    my_printf("*");
    for (int j = 0; j < (total_space / 2); j++)
        my_printf(" ");
    for (int j = 0; j < map[i]; j++)
        my_printf("|");
    for (int j = 0; j < ((total_space / 2) + add_space_right); j++)
        my_printf(" ");
    my_printf("*");
}

static void limit_up_down(int tmp)
{
    for (int i = 0; i < (tmp + 2); i++)
        my_printf("*");
    my_printf("\n");
}

void print_map(int *map, int nb_line)
{
    int tmp = ((nb_line * 2) - 1);
    limit_up_down(tmp);
    for (int i = 0; i < nb_line; i++) {
        make_line(tmp, i, map);
        my_printf("\n");
    }
    limit_up_down(tmp);
}