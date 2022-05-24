/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** quit
*/

#include "myftp.h"

client_t *quit(client_t *client, fd_set *master)
{

    client->path = realloc(client->path, 2);
    client->path[0] = '/';
    client->path[1] = '\0';
    client->pass = false;
    client->user = false;

    close(client->fd);
    FD_CLR(client->fd, master);
    dprintf(client->fd, "221 Goodbye.\r\n");

    return client;
}
