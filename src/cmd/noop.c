/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** noop
*/

#include "../../includes/myftp.h"

void noop(client_t *client)
{
    dprintf(client->client_fd, "200 NOOP command successful.\r\n");
}