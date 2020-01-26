/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ai_turn
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>

static int *ai_turn_odd_win(int *map, int nb_line, int max_match)
{
    int line_with_more_match = 0;
    int nb_match_in_line = 0;
    int nb_match_delete = 0;

    for (int i = 0; i <= nb_line - 1; i++)
        if (nb_match_in_line <= map[i]) {
            line_with_more_match = i;
            nb_match_in_line = map[i];
        }
    for (int i = 0; i <= nb_match_in_line - 1 &&
        nb_match_delete < max_match; i++)
        nb_match_delete = (2 * i) + 1;
    for (;nb_match_delete > max_match ||
        nb_match_delete > map[line_with_more_match];)
        nb_match_delete = nb_match_delete - 1;
    if (nb_match_delete == 0)
        nb_match_delete = nb_match_delete + 1;
    map[line_with_more_match] = map[line_with_more_match] - nb_match_delete;
    my_printf("AI removed %d match(es)", nb_match_delete);
    my_printf(" from line %d\n", line_with_more_match + 1);
    return (map);
}

static int *ai_turn_even_win(int *map, int nb_line, int max_match)
{
    int line_with_more_match = 0;
    int nb_match_in_line = 0;
    int nb_match_delete = 0;

    for (int i = 0; i <= nb_line - 1; i++)
        if (nb_match_in_line < map[i]) {
            line_with_more_match = i;
            nb_match_in_line = map[i];
        }
    for (int i = 0; i <= nb_match_in_line - 1 &&
        nb_match_delete < max_match; i++)
        nb_match_delete = (2 * i) + 2;
    for (;nb_match_delete > max_match ||
        nb_match_delete > map[line_with_more_match];)
        nb_match_delete = nb_match_delete - 2;
    if (nb_match_delete == 0)
        nb_match_delete = nb_match_delete + 1;
    map[line_with_more_match] = map[line_with_more_match] - nb_match_delete;
    my_printf("AI removed %d match(es)", nb_match_delete);
    my_printf(" from line %d\n", line_with_more_match + 1);
    return (map);
}

int ai_turn(int *map, int nb_line, int max_match, int turn)
{
    int nb_match_remain = 0;
    int nb_line_empty = 0;

    for (int i = 0; i < nb_line; i++)
        nb_match_remain = nb_match_remain + map[i];
    if ((max_match % 2) == 1)
        ai_turn_odd_win(map, nb_line, max_match);
    else
        ai_turn_even_win(map, nb_line, max_match);
    print_map(map, nb_line);
    for (int i = 0; i < nb_line; i++)
        if (map[i] == 0) 
            nb_line_empty = nb_line_empty + 1;
    if (nb_line_empty == nb_line) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (game_loop(map, nb_line, max_match, HUMAN_W));
    }
    nb_line_empty = 0;
    turn = HUMAN_T;
    return (game_loop(map, nb_line, max_match, turn));
}