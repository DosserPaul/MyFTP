/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** cdup
*/

#include "../../includes/myftp.h"

char *remove_last_dir(char *path)
{
    if (strcmp(path, "/") == 0)
        return "/";

    int i = 0;
    int j = 0;

    while (path[i] != '\0') {
        if (path[i] == '/')
            j = i;
        i++;
    }
    path[j] = '\0';
    if (strcmp(path, "") == 0)
        strcpy(path, "/");
    return path;
}

client_t *cdup(client_t *client, char *cmd)
{
    if (!is_logged(client))
        return client;

    if (cmd == NULL)
        return client;

    if (strlen(client->path) == 1 && client->path[0] == '/') {
        dprintf(client->client_fd, "550 No such directory.\n");
        return client;
    } else {
        dprintf(client->client_fd, "200 Directory successfully changed.\n");
        chdir("..");
        client->path = remove_last_dir(client->path);
        return client;
    }
}