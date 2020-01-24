/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** full_map
*/

#include "lib.h"
#include "my.h"

int *full_map(int *map, int nb_line)
{
    map[0] = 1;
    for (int i = 1; i < nb_line; i++)
        map[i] = map[i - 1] + 2;
    print_map(map, nb_line);
    return (map);
}