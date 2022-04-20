/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** is_logged
*/

#include "../../includes/myftp.h"

bool is_logged(client_t *client)
{
    if (client->is_logged)
        return true;
    dprintf(client->client_fd, "530 Please login with USER and PASS.\r\n");
    return false;
}