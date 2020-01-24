/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}