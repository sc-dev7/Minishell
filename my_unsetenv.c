/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** sc
*/

#include "my.h"

char *catenv(char *str)
{
    int a = my_strlen(str);
    char *strcat = malloc(sizeof(char) * (a + 2));
    int i = 0;
    while (str[i] != '\0') {
        strcat[i] = str[i];
        i++;
    }
    strcat[i] = '=';
    strcat[i + 1] = '\0';
    return strcat;
}

char **my_unsetenv(char **env, char **tab)
{
    if (tab[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return env;
    }
    tab[1] = catenv(tab[1]);
    int c = nbrow(env);
    char **set = malloc(sizeof(char *) * (c));
    int i = 0;
    while (env[i] != NULL) {
        if (my_strcmp2(env[i], tab[1]) == 1) {
            set[i] = malloc(sizeof(char) * my_strlen(env[i]));
            set[i] = my_strcpy(set[i], env[i]);
        }
        i++;
    }
    set[i] = NULL;
    return set;
}
