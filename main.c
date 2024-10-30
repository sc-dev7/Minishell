/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** sc
*/

#include "my.h"

char *my_getline(void)
{
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1) {
        exit(0);
    }
    return line;
}

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}

void print_bin(char **env, char *get, char **tab)
{
    if (get[0] == '\n') {
        return;
    }
    char *str = recup_path(env);
    char **path = path_array(str);
    for (int i = 0; path[i] != NULL; i++) {
        char *cat = my_strpath(path[i], tab[0]);
        if (access(cat, F_OK) == 0) {
            pid_t pid = fork();
            (pid == 0) ? execve(cat, tab, env) : 0;
            return;
        }
    }
    my_putstr(tab[0]);
    my_putstr(": Command not found.\n");
}

char **command(char **env, char *get, char **tab)
{
    if (my_strcmp("exit", tab[0]) == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (my_strcmp("setenv", tab[0]) == 0) {
        env = my_setenv(env, tab);
        return env;
    }
    if (my_strcmp("unsetenv", tab[0]) == 0) {
        env = my_unsetenv(env, tab);
        return env;
    }
    if (my_strcmp("cd", tab[0]) == 0) {
        return env;
    }
    print_bin(env, get, tab);
    return env;
}

int main(int ac, char **av, char **env)
{
    while (1) {
        my_putstr("$> ");
        char *get = my_getline();
        char **teg = array_separator(get);
        int a = 0; int j = nbtab(teg);
        while (a < j) {
            char **tab = str_to_array(teg[a]);
            env = command(env, get, tab);
            wait(NULL);
            a++;
        }
        for (int i = 0; teg[i]; i++) {
            free(teg[i]);
        }
        free(teg);
    }
    return 0;
}
