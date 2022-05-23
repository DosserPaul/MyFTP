/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** client_handler
*/

#include "myftp.h"

void client_handler(int fd, client_t *client)
{
    client->fd = fd;
    char buffer[4096];

    read(fd, buffer, 4096);
    client = command_handler(client, buffer);
}