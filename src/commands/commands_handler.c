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
        {"NOOP", &noop},
        {"HELP", &help}
};


client_t *command_handler(client_t *client, char *command)
{
    strtok(command, "\r\n");
    char **array = split(command, " ");

    for (size_t i = 0; commands[i].name; i++) {
        if (strcmp(array[0], commands[i].name) == 0) {
            client = commands[i].func(client, array);
            client->test++;
            free_split(array);
            return client;
        }
    }

    free_split(array);
    dprintf(client->fd, "500 Syntax error, command unrecognized.\r\n");
    return client;
}