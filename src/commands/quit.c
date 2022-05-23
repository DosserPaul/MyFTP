/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** quit
*/

#include "myftp.h"

client_t *quit(client_t *client, char **cmd UNUSED)
{
//    if (is_logged(client) == false)
//        return client;

    dprintf(client->fd, "221 Goodbye.\r\n");
    client->is_closed = true;
    return client;
}