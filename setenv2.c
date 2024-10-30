/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** sc
*/

#include "my.h"

int my_strcmp(char *str, char *str2)
{
    int i = 0;
    while (str[i] != '\0' && str2[i] != '\0') {
        if (str[i] != str2[i]) {
            return 1;
        }
        i++;
    }
    if (str[i] != str2[i]) {
        return 1;
    }
    return 0;
}

int my_strcmp2(char *str, char *str2)
{
    int i = 0;
    while (str[i] != '=' && str2[i] != '\0') {
        if (str[i] != str2[i]) {
            return 1;
        }
        i++;
    }
    if (str[i] != str2[i]) {
        return 1;
    }
    return 0;
}

int nbrow(char **env)
{
    int i = 0;
    for (; env[i] != NULL; i++);
    return i;
}

int alphanum2(char **tab, int i, int j)
{
    int c = 0;
    if (tab[i][j] >= 'a' && tab[i][j] <= 'z')
        c++;
    if (tab[i][j] >= 'A' && tab[i][j] <= 'Z')
        c++;
    if (tab[i][j] >= '0' && tab[i][j] <= '9')
        c++;
    if (tab[i][j] == '_')
        c++;
    if (c == 0)
        return 1;
    return 0;
}

int alphanum(char **tab)
{
    int i = 1;
    int j = 0;
    int c = 0;
    while (tab[i] != NULL) {
        while (tab[i][j] != '\0') {
            (alphanum2(tab, i, j) == 1) ? c++ : 0;
            j++;
        }
        j = 0;
        if (c > 0) {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
            return 1;
        }
        i++;
    }
    return 0;
}
