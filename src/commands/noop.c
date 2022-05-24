/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** noop
*/

#include "myftp.h"

client_t *noop(client_t *client, char **cmd UNUSED)
{
    if (is_logged(client) == false)
        return client;

    dprintf(client->fd, "200 NOOP command successful.\r\n");
    return client;
}
