/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** check_error
*/

#include "myftp.h"

int check_error(int nb, const char *str)
{
    if (nb == -1) {
        perror(str);
        exit(84);
    }
    return nb;
}