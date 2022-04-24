/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** my_strcat
*/

#include "../includes/myftp.h"

char *my_strcat(char *dest, char *src)
{
    char *str = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1));

    for (size_t i = 0; i < strlen(dest); i++)
        str[i] = dest[i];

    for (size_t i = 0; i < strlen(src); i++)
        str[strlen(dest) + i] = src[i];

    str[strlen(dest) + strlen(src)] = '\0';

    return str;
}