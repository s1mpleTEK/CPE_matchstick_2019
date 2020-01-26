/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** human_turn
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

static int ai_win_condition(int nb_line, int *map)
{
    int nb_line_empty = 0;

    for (int i = 0; i < nb_line; i++)
        if (map[i] == 0) 
            nb_line_empty = nb_line_empty + 1;
    if (nb_line_empty == nb_line) {
        my_printf("You lost, too bad...\n");
        return (WIN_CONDITION);
    }
    nb_line_empty = 0;
    return (0);
}

static int human_input_match(int match)
{
    int status = 0;
    size_t n = 0;
    char *match_input = NULL;

    my_printf("Matches: ");
    status = getline(&match_input, &n, stdin);
    if (status == ERROR_GETLINE) {
        free(match_input);
        return (ERROR_GETLINE);
    }
    match_input[status - 1] = '\0';
    if (check_match_input(match_input) == ERROR) {
        free(match_input);
        return (ERROR);
    }
    match = my_getnbr(match_input);
    free(match_input);
    match_input = NULL;
    return (match);
}

static int human_input_line(int line)
{
    int status = 0;
    size_t n = 0;
    char *line_input = NULL;

    my_printf("Line: ");
    status = getline(&line_input, &n, stdin);
    if (status == ERROR_GETLINE) {
        free(line_input);
        return (ERROR_GETLINE);
    }
    line_input[status - 1] = '\0';
    if (check_line_input(line_input) == ERROR) {
        free(line_input);
        return (ERROR);
    }
    line = my_getnbr(line_input);
    free(line_input);
    line_input = NULL;
    return (line);
}

static int *new_map(int line, int match, int nb_line, int *map)
{
    map[line - 1] = map[line - 1] - match;
    my_printf("Player removed %d match(es) from line %d\n", match, line);
    print_map(map, nb_line);
    return (map);
}

int human_turn(int *map, int nb_line, int max_match, int turn)
{
    int line = 0;
    int match = 0;

    line = human_input_line(line);
    if (line == ERROR_GETLINE)
        return (game_loop(map, nb_line, max_match, CLOSE));
    else if (line == ERROR)
        return (human_turn(map, nb_line, max_match, turn));
    if (check_line(line, nb_line) == ERROR)
        return (human_turn(map, nb_line, max_match, turn));
    match = human_input_match(match);
    if (match == ERROR_GETLINE)
        return (game_loop(map, nb_line, max_match, CLOSE));
    else if (match == ERROR)
        return (human_turn(map, nb_line, max_match, turn));
    if (check_match(match, max_match, line, map) == ERROR)
        return (human_turn(map, nb_line, max_match, turn));
    new_map(line, match, nb_line, map);
    if (ai_win_condition(nb_line, map) == WIN_CONDITION)
        return (game_loop(map, nb_line, max_match, AI_W));
    return (game_loop(map, nb_line, max_match, AI_T));
}