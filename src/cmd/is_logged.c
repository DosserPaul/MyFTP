/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** is_logged
*/

#include "../../includes/myftp.h"

bool is_logged(client_t *client)
{
    if (client->logged)
        return true;
    dprintf(client->fd, "530 Please login with USER and PASS.\r\n");
    return false;
}