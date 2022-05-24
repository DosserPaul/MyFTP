/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** pwd
*/

#include "myftp.h"

client_t *pwd(client_t *client, char **cmd UNUSED)
{
    if (is_logged(client) == false)
        return client;

    char *path = getcwd(NULL, 0);

    if (path == NULL)
        return client;

    int len = (int)strlen(client->path);
    if (len != 1 && client->path[len - 1] == '/')
        client->path[strlen(client->path) - 1] = '\0';

    dprintf(client->fd, "257 \"%s\"\r\n", client->path);
    free(path);
    return client;
}
