/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** pass
*/

#include "myftp.h"

int count_words(char **array)
{
    int i = 0;

    while (array[i])
        i++;
    return i;
}

client_t *pass(client_t *client, char **cmd)
{
    if (client->pass == true && client->user == true) {
        dprintf(client->fd, "530 Already logged in.\r\n");
        return client;
    }

    if (count_words(cmd) == 1) {
        dprintf(client->fd, "230 User logged in, proceed.\r\n");
        client->pass = true;
        return client;
    } else if (count_words(cmd) > 1 && strcmp(cmd[1], " ") == 0) {
        dprintf(client->fd, "230 User logged in, proceed.\r\n");
        client->pass = true;
        return client;
    }
    dprintf(client->fd, "530 Not logged in.\r\n");
    return client;
}