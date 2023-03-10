/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** client_handler
*/

#include "myftp.h"

void client_handler(server_t *server, int fd, client_t *client)
{
    char buffer[BUFSIZ];
    client->fd = fd;

    read(fd, buffer, 4096);
    client = command_handler(client, buffer, &server->master);
}
