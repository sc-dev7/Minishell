/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** sc
*/

#include "my.h"

int limax(char *str)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] == ';' && str[i + 1] == '\n') {
            j++;
            return j;
        }
        if (str[i] == ';') {
            j++;
        }
        i++;
    }
        j++;
    return j;
}

int colomax(char *str, int i)
{
    int j = 0;
    while (str[i] != ';' && str[i] != '\n' && str[i] != '\0') {
        i++;
        j++;
    }
    return j;
}

char **array_separator(char *str)
{
    int lmax = limax(str);
    char **tab = malloc(sizeof(char *) * (lmax + 1));
    int i = 0, y = 0, x = 0, j = 0;
    while (y != lmax) {
        int c = colomax(str, i);
        tab[y] = malloc(sizeof(char) * (c + 1));
        int z = 0;
        while (z != c) {
            tab[y][x] = str[i];
            i++; x++; z++;
        }
        i++;
        tab[y][x] = '\0';
        x = 0;
        y++;
    }
    tab[y] = NULL;
    return tab;
}
