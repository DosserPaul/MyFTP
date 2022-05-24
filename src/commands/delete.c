/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** delete
*/

#include "myftp.h"

client_t *delete(client_t *client, char **cmd)
{
    if (cmd[1] == NULL) {
        dprintf(client->fd, "550 No file name.\r\n");
        return (client);
    }
    if (remove(cmd[1]) == -1) {
        dprintf(client->fd, "550 File not found.\r\n");
        return (client);
    }
    dprintf(client->fd, "250 File deleted.\r\n");
    return (client);
}