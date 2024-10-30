/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** sc
*/

#include "my.h"

int exist(char **env, char *str)
{
    char **set;
    int i = 0;
    while (env[i] != NULL) {
        int a = my_strcmp2(env[i], str);
        if (a == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

int tailletab(char **tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        i++;
    }
    i++;
    if (i > 4) {
        my_putstr("setenv: Too many arguments.\n");
    }
    return i;
}

char **my_setenv(char **env, char **tab)
{
    if (tab[1] == NULL) {
        print_env(env);
        return env;
    }
    if (firstchar(tab) == 0) {
        return env;
    }
    if (alphanum(tab) == 1) {
        return env;
    }
    if (tailletab(tab) > 4) {
        return env;
    }
    char *str = catenv(tab[1]); char **set; int i = 0, c = exist(env, str);
    if (c == -1) {
        set = my_set2(env, tab);
    } else {
        set = my_set3(env, c, tab);
    }
    return set;
}

char **my_set2(char **env, char **tab)
{
    tab[1] = catenv(tab[1]);
    int c = nbrow(env);
    char **set = malloc(sizeof(char *) * (c + 2));
    int i = 0;
    while (env[i] != NULL) {
        set[i] = malloc(sizeof(char) * my_strlen(env[i]));
        set[i] = my_strcpy(set[i], env[i]);
        i++;
    }
    set[i] = malloc(sizeof(char) * my_strlen(tab[1]));
    set[i] = my_strcpy(set[i], tab[1]);
    if (tab[2] != NULL) {
        set[i] = malloc(sizeof(char) * (my_strlen(tab[1])
        + my_strlen(tab[2]) + 1));
        set[i] = my_strcat(tab[1], tab[2]);
    }
    set[i + 1] = NULL;
    return set;
}

char **my_set3(char **env, int c, char **tab)
{
    tab[1] = catenv(tab[1]);
    char *newstr = malloc(sizeof(char) * (my_strlen(tab[1]) + 1));
    newstr = my_strcpy(newstr, tab[1]);
    if (tab[2] != NULL) {
        newstr = malloc(sizeof(char) * (my_strlen(tab[1])
        + my_strlen(tab[2]) + 1));
        newstr = my_strcat(tab[1], tab[2]);
    }
    env[c] = my_strdup(newstr);
    return env;
}
