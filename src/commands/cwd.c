/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** cwd
*/

#include "myftp.h"

static void test(client_t *client, char *path)
{
    if (path[strlen(path) - 1] == '/')
        path[strlen(path) - 1] = '\0';

    char **array = split(path, "/");
//    size_t total = 0;

    for (size_t i = 0; array[i] != NULL; i++) {
        if (strcmp(array[i], "..") == 0) {
            if (client->path[strlen(client->path) - 1] == '/')
                client->path[strlen(client->path) - 1] = '\0';
            char *tmp = strrchr(client->path, '/');
            if (tmp != NULL)
                *tmp = '\0';
        } else if (strcmp(array[i], ".") != 0) {
            if (client->path[strlen(client->path) - 1] != '/')
                strcat(client->path, "/");
            strcat(client->path, array[i]);
        }
    }
    free_split(array);
}

static void change_path(client_t *client, char *path)
{
    char *tmp = strdup(client->path);
    if (strcmp(path, "..") != 0) {
        client->path = realloc(client->path, strlen(client->path) +
                               strlen(path) + 2);
        if (tmp[strlen(tmp) - 1] != '/')
            strcat(client->path, "/");
        strcat(client->path, path);
    } else {
        test(client, path);
    }
    free(tmp);
    if (strlen(client->path) == 0) {
        client->path = realloc(client->path, 2);
        client->path[0] = '/';
        client->path[1] = '\0';
    }
}

client_t *cwd(client_t *client, char **cmd)
{
    if (is_logged(client) == false)
        return client;

    if (cmd[1] == NULL) {
        dprintf(client->fd, "550 No such directory.\r\n");
        return client;
    }

    if (strcmp(client->path, "/") == 0 && strcmp(cmd[1], "..") == 0) {
        dprintf(client->fd, "550 No such directory.\r\n");
        return client;
    }

    if (chdir(cmd[1]) == -1) {
        dprintf(client->fd, "550 No such directory.\r\n");
        return client;
    }

    change_path(client, cmd[1]);
    dprintf(client->fd, "250 CWD command successful.\r\n");
    return client;
}
