/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** noop
*/

#include "../../includes/myftp.h"

client_t *noop(client_t *client, char *cmd)
{
    if (cmd == NULL)
        return client;

    dprintf(client->client_fd, "200 NOOP command successful.\r\n");

    return client;
}