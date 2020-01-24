/*
** EPITECH PROJECT, 2020
** CPE_matchstick_bootstrap_2019
** File description:
** main
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>

static int no_number_in(char **av, int i)
{
    for (int j = 0; av[i][j] != '\0'; j++)
        if (av[i][j] < '0' || av[i][j] > '9')
            return (ERROR);
    return (0);
}

static int error(int ac, char *av[])
{
    if (ac != 3)
        return (ERROR);
    if (my_getnbr(av[1]) <= 0 || my_getnbr(av[1]) > 99)
        return (ERROR);
    if (my_getnbr(av[2]) <= 0)
        return (ERROR);
    for (int i = 1; i <= 2; i++)
        if (no_number_in(av, i) == ERROR)
            return (ERROR);
    return (0);
}

int main(int ac, char *av[])
{
    if (error(ac, av) == ERROR)
        return (ERROR);

    int turn = HUMAN_T;
    int nb_line = my_getnbr(av[1]);
    int max_match = my_getnbr(av[2]);
    int *map = malloc(sizeof(int) * nb_line);

    if (!map)
        return (ERROR);
    turn = game_loop(full_map(map, nb_line), nb_line, max_match, turn);
    free(map);
    return (turn);
}
