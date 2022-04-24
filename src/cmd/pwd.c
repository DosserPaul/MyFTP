/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** pwd
*/

#include "../../includes/myftp.h"

client_t *pwd(client_t *client, char *cmd)
{
    if (!is_logged(client))
        return client;

    if(cmd == NULL) {
        dprintf(client->client_fd, "550 No such file or directory.\n");
        return client;
    }

    dprintf(client->client_fd, "257 \"%s\" is the current directory.\r\n",
        client->path);

    return client;
}