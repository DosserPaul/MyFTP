/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** help
*/

#include "../../includes/myftp.h"

client_t *help(client_t *client, char *cmd)
{
    if (!is_logged(client))
        return client;

    if (cmd == NULL)
        return client;


    char help_tab[][13] = {"USER", "PASS", "CWD", "CDUP", "QUIT", "DELET",
                         "PWD","PASV", "PORT", "HELP", "NOOP", "RETR", "STOR",
                         "LIST"};

    for (int i = 0; i < 13; i++) {
        if ( i != 13)
            dprintf(client->fd, "214 [%s, ", help_tab[i]);
        else
            dprintf(client->fd, "%s", help_tab[i]);
        printf("[%s, ", help_tab[i]);
    }
    printf("]\r\n");

    return client;
}