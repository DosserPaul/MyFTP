/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** quit
*/

#include "myftp.h"

client_t *quit(client_t *client, fd_set *master)
{

    client->path = strdup("/");
    client->pass = false;
    client->user = false;
    client->welcome = false;

    dprintf(client->fd, "221 Goodbye.\r\n");
    close(client->fd);
    FD_CLR(client->fd, master);

    return client;
}
