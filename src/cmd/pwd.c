/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** pwd
*/

#include "../../includes/myftp.h"

void pwd(client_t *client)
{
    if (!is_logged(client))
        return;

    dprintf(client->client_fd, "257 \"%s\" is the current directory.\r\n",
        client->path);
}