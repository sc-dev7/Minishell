/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** sc
*/

#include "my.h"

int firstchar(char **tab)
{
    int i = 0, j = 0, c = 0;
    if (tab[1][0] >= 'a' && tab[1][0] <= 'z') {
        c++;
    }
    if (tab[1][0] >= 'A' && tab[1][0] <= 'Z') {
        c++;
    }
    if (c == 0) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    return 1;
}
