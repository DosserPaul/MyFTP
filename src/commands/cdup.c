/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** cdup
*/

#include "myftp.h"

static int count_nb_slash(char *path)
{
    size_t count = 0;
    size_t len = strlen(path);

    for (size_t i = 0; i < len; i++) {
        if (path[i] == '/')
            count++;
    }
    return (int)count;
}

client_t *cdup(client_t *client, char **cmd UNUSED)
{
    if (is_logged(client) == false)
        return client;
    if (strcmp(client->path, "/") == 0) {
        dprintf(client->fd, "550 No such directory.\r\n");
        return client;
    }
    if (chdir("..") == -1) {
        dprintf(client->fd, "550 No such directory.\r\n");
        return client;
    }
    int len = (int)strlen(client->path);
    if (client->path[len - 1] == '/')
        client->path[len - 1] = '\0';

    if (count_nb_slash(client->path) > 1)
        client->path = strrchr(client->path, '/');
    else
        client->path = "/";

    dprintf(client->fd, "200 Command okay.\r\n");
    return client;
}