/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** memset
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

// void mem_move(void* dest,void* src, size_t size)
// {
//     char *tmp_d = dest;
//     char *tmp_s = src;
//     char *tmp[size];

//     for (int i = 0; i < size; i++)
//         tmp[i] = tmp_s[i];
//     for (int i = 0; i < size; i++)
//         tmp_d[i] = tmp[i];
//     delete
// }

void* mem_cpy(void* dest, void* src, size_t size)
{
    char *tmp_d = dest;
    char *tmp_s = src;

    for (int i = 0; i < size; i++)
        tmp_d[i] = tmp_s[i];
}

void* mem_set(void* s, int c, size_t size)
{
    char *tmp = s;

    for (int i = 0; i < size; i++)
        tmp[i] = c;
}