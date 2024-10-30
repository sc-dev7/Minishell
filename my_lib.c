/*
** EPITECH PROJECT, 2022
** lib.c
** File description:
** sc
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

int my_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return (len);
}

int my_putnbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb > 9) {
        my_putnbr(nb / 10);
        nb %= 10;
    }
    my_putchar(nb % 10 + '0');
    return (0);
}

int my_getnbr(char *str)
{
    long e = 1, pow = 1, result = 0;
    int i = 0;
    if (str[0] == '-') {
        e = -1;
        str = &str[1];
    }
    i = my_strlen(str) - 1;
    for (; i >= 0; i--) {
        result = result + (str[i] - 48) * pow;
        pow = pow * 10;
    }
    result = result * e;
    return result;
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char *str)
{
    int i = 0;
    for (; str[i]; i += 1);
    char *temp = malloc(sizeof(char) * (i + 1));
    for (int i = 0; str[i]; i += 1)
        temp[i] = str[i];
    temp[i] = '\0';
    return temp;
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = my_strlen(src);
    int k = my_strlen(dest);
    while (src[i] != '\0') {
        dest[k] = src[i];
        i++;
        k++;
    }
    return dest;
}

void put_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
