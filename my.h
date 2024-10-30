/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my all include
*/

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

typedef struct {
    char *str;
} nod;

    void my_putchar(char c);
    void my_putstr(char *str);
    int my_strlen(char *str);
    int my_putnbr(int nb);
    int my_getnbr (char *str);
    char *my_strcpy(char *dest, char *src);
    char *my_strdup(char *str);
    char **str_to_array(char *str);
    void put_tab(char **tab);
    char *my_strcat(char *dest, char *src);
    int nbl(char *str);
    int nbc(char *str, int i);
    char **path_array(char *str);
    char *concat_str(char *path, char *str);
    char *addstr(char *path, char *str);
    char *my_strpath(char *path, char *str);
    char *recup_path(char **env);
    void print_bin(char **env, char *get, char **tab);
    char *my_strdup(char *str);
    char *my_getline(void);
    char *catenv(char *str);
    int my_strcmp(char *str, char *str2);
    char **my_setenv(char **env, char **tab);
    void print_env(char **env);
    char **my_set(char **env);
    char **my_set2(char **env, char **tab);
    char **command(char **env, char *get, char **tab);
    char **my_set3(char **env, int c, char **tab);
    int my_strcmp2(char *str, char *str2);
    int nbrow(char **env);
    int alphanum(char **tab);
    char **my_unsetenv(char **env, char **tab);
    int firstchar(char **tab);
    char **array_separator(char *str);
    void print_tab(char **tab);
    int nbtab(char **tab);
    int limax(char *str);
    char **tabsup(char *str);
