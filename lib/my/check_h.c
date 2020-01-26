/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** check_h
*/

#include "lib.h"

int check_h(char* str)
{
    char* check_str = "-h";
    int check = 0;

    for (int i = 0; i < 2; i++) {
        if (str[i] != check_str[i])
            check = 1;
    }
    return (check);
}