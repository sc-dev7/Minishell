/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** sc
*/

#include "my.h"

char *recup_path(char **env)
{
    char *path;
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
        && env[i][3] == 'H' && env[i][4] == '=') {
            path = env[i];
        }
    }
    return path;
}

int nbl(char *str)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            j++;
        }
    }
    j += 1;
    return j;
}

int nbc(char *str, int i)
{
    int j = 0;
    for (; str[i] != ':' && str[i] != '\0'; i++) {
        j++;
    }
    j += 1;
    return j;
}

char **path_array(char *str)
{
    int row = nbl(str);
    char **tab = malloc(sizeof(char *) * (row + 1));
    int i = 5, x = 0, y = 0;
    while (y != row) {
        int col = nbc(str, i);
        tab[y] = malloc(sizeof(char) * (col + 1));
        int c = 0;
        while (c != col && str[i] != '\0') {
            (str[i] != ':') ? tab[y][x] = str[i] : 0;
            i++;
            x++;
            c++;
        }
        tab[y][x] = '\0';
        x = 0;
        y += 1;
    }
    tab[y] = NULL;
    return tab;
}

char *my_strpath(char *path, char *str)
{
    int i = my_strlen(path);
    int j = my_strlen(str);
    char *cat = malloc(sizeof(char) * (i + j + 2));
    int a = 0;
    int b = 0;
    int c = 0;
    for (; path[a] != '\0'; a++) {
        cat[c] = path[a];
        c += 1;
    }
    cat[c] = '/';
    c += 1;
    for (; str[b] != '\0'; b++) {
        cat[c] = str[b];
        c++;
    }
    cat[c] = '\0';
    return cat;
}
