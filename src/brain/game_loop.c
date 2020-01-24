/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** game_loop
*/

#include "lib.h"
#include "my.h"

int game_loop(int *map, int nb_line, int max_match, int arg_turn)
{
    static int turn = 0;
    turn = arg_turn;
    if (turn == HUMAN_T) {
        my_printf("\n");
        my_printf("Your turn:\n");
        return (human_turn(map, nb_line, max_match, turn));
    }
    if (turn == AI_T) {
        my_printf("\n");
        my_printf("AI's turn...\n");
        return (ai_turn(map, nb_line, max_match, turn));
    }
    return (turn);
}