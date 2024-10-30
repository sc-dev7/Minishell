/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** sc
*/

#include "my.h"

void print_tab(char **tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}

int nbtab(char **tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        i++;
    }
    return i;
}
