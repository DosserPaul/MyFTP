/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** check_error
*/

#include <errno.h>
#include "myftp.h"

int check_error(int nb, const char *str)
{
    if (nb == -1 && errno != EINTR) {
        perror(str);
        exit(84);
    }
    return nb;
}
