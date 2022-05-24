/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** commands_handler
*/

#include "myftp.h"

commands_t commands[] = {
        {"USER", &user},
        {"PASS", &pass},
        {"CWD", &cwd},
        {"CDUP", &cdup},
        {"DELETE", &delete},
        {"PWD", &pwd},
        {"HELP", &help},
        {"NOOP", &noop}
};


client_t *command_handler(client_t *client, char *command, fd_set *master)
{
    strtok(command, "\r\n");
    char **array = split(command, " ");

    if (strcmp(array[0], "QUIT") == 0) {
        quit(client, master);
    }

    for (size_t i = 0; commands[i].name; i++) {
        if (strcmp(array[0], commands[i].name) == 0) {
            client = commands[i].func(client, array);
            free_split(array);
            return client;
        }
    }

    free_split(array);
    dprintf(client->fd, "500 Syntax error, command unrecognized.\r\n");
    return client;
}