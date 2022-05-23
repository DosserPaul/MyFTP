/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** help
*/

#include "myftp.h"

client_t *help(client_t *client, char **cmd UNUSED)
{
    if (client->pass == false && client->user == false) {
        dprintf(client->fd, "214 Help:\r\nUSER username\r\n");
        dprintf(client->fd, "PASS password\r\n");
        return client;
    }
    char *help[13] = {"USER", "PASS", "CWD", "CDUP", "QUIT",
                      "PWD", "PASV", "PORT", "HELP", "NOOP",
                      "RETR", "STOR", "LIST"};

    dprintf(client->fd, "214 Help:\n");
    for (size_t i = 0; i < 13; i++) {
            dprintf(client->fd, "%s\r\n", help[i]);
    }
    return client;
}