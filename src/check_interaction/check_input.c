/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** check_input
*/

#include "lib.h"
#include "my.h"

int check_match(int match, int max_match, int line, int *map)
{
    if((map[line - 1] == '\0') || (match <= 0)) {
        my_printf("Error: you have to remove at least one match\n");
        return (ERROR);
    }
    if (match > max_match) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
                max_match);
        return (ERROR);
    }
    if (match > map[line - 1]) {
        my_printf("Error: not enough matches on this line\n");
        return (ERROR);
    }
    return (0);
}

int check_line(int line, int nb_line)
{
    if ((line > nb_line) || (line <= 0)) {
        my_printf("Error: this line is out of range\n");
        return (ERROR);
    }
    return (0);
}

int check_match_input(char *match)
{
    int i = 0;
    for (; match[i] != '\0'; i++);
    if (i == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (ERROR);
    }
    for (int i = 0; match[i] != '\0'; i++) {
        if ((match[i] < '0') || (match[i] > '9')) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (ERROR);
        }
    }
    return (0);
}

int check_line_input(char *line)
{
    int i = 0;
    for (; line[i] != '\0'; i++);
    if (i == 0) {
        my_printf("Error: this line is out of range\n");
        return (ERROR);
    }
    for (int i = 0; line[i] != '\0'; i++) {
        if ((line[i] < '0') || (line[i] > '9')) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (ERROR);
        }
    }
    return (0);
}