/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** main_bonus
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
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) > 99)
        return (ERROR);
    if (my_getnbr(av[2]) <= 0)
        return (ERROR);
    for (int i = 1; i <= 2; i++)
        if (no_number_in(av, i) == ERROR)
            return (ERROR);
    return (0);
}

static void print_usage(void)
{
    my_printf("USAGE\n");
    my_printf("    ./matchstick_bonus y n\n\n");
    my_printf("DESCRIPTION\n");
    my_printf("    y  corresponds to the number of floors the game will");
    my_printf(" have\n");
    my_printf("    n  corresponds to the maximum number of matches that");
    my_printf(" can be removed on a line\n");
}

static int usage(int ac, char *av[])
{
    if (ac == 1) {
        print_usage();
        return (USAGE);
    }
    if (ac == 2 && check_h(av[1]) == 0) {
        print_usage();
        return (USAGE);
    }
    return (0);
}

int main(int ac, char *av[])
{
    if (usage(ac, av) == USAGE)
        return (0);
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
