/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** sc
*/

#include "my.h"

int col(char *str, int i)
{
    int j = 0;
    while (str[i] != ' ' && str[i] != '\n'
    && str[i] != '\t' && str[i] != '\0') {
        j++;
        i++;
    }
    return j;
}

int space(char *str, int i)
{
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }
    return i;
}

char **str_to_array(char *str)
{
    char **tab = malloc(sizeof(char *) * 1024);
    int i = 0, y = 0, x = 0, j = 0;
    while (str[i] != '\0') {
        i = space(str, i);
        int colmax = col(str, i);
        tab[y] = malloc(sizeof(char) * (colmax + 1));
        int c = 0;
        while (c != colmax) {
            tab[y][x] = str[i];
            i++; c++; x++;
        }
        tab[y][x] = '\0';
        x = 0;
        y++;
    }
    tab[y] = NULL;
    return tab;
}
