/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** user
*/

#include "myftp.h"

client_t *user(client_t *client, char **cmd)
{
    if (client->pass == true && client->user == true) {
        dprintf(client->fd, "530 Already logged in.\r\n");
        return client;
    }

    if (cmd[1] == NULL)
        return client;

    if (strcmp("Anonymous", cmd[1]) == 0) {
        dprintf(client->fd, "331 User name okay, need password.\r\n");
        client->user = true;
        return client;
    } else {
        dprintf(client->fd, "530 Not logged in.\r\n");
        return client;
    }
    fprintf(stderr, "[-]Error: user command\n");
    return client;
}
