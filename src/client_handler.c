/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** client_handler
*/

#include "myftp.h"

void client_handler(int fd)
{
    client_t *client = malloc(sizeof(client_t));
    client->user = false;
    client->pass = false;
    client->path = NULL;
    client->original_path = NULL;
    client->fd = fd;
    char buffer[4096];

    read(fd, buffer, 4096);
    command_handler(client, buffer);
}