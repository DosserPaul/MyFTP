/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** is_logged
*/

#include "myftp.h"

bool is_logged(client_t *client)
{
    if (client->pass == true && client->user == true)
        return true;
    dprintf(client->fd, "332 Need account for this command\r\n");
//    OR
//    dprintf(client->fd, "530 Please login with USER and PASS.\r\n");
    return false;
}
