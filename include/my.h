/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#define HUMAN_T -42
#define AI_T -666
#define HUMAN_W 1
#define AI_W 2
#define CLOSE 0
#define ERROR 84
#define WIN_CONDITION 42
#define ERROR_GETLINE -1
#define USAGE 50

int *full_map(int *map, int nb_line);
void print_map(int *map, int nb_line);
int game_loop(int *map, int nb_line, int max_match, int turn);
int human_turn(int *map, int nb_line, int max_match, int turn);
int ai_turn(int *map, int nb_line, int max_match, int turn);
int check_match(int match, int max_match, int line, int *map);
int check_line(int line, int nb_line);
int check_match_input(char *match);
int check_line_input(char *line);

#endif /* !MY_H_ */