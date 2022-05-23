/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** commands_handler
*/

#include "myftp.h"

//command_t commands[] = {
//        {"/help", &help},
//        {"/login", &login}
//};


client_t *command_handler(client_t *client, char *command)
{
    strtok(command, "\r\n");
    char **array = split(command, " ");

    printf("[~]Command: \n");

    for (size_t i = 0; array[i] != NULL; i++)
        printf("\t[~] array[%zu]: %s\n", i, array[i]);
//    char **array = split(command, " ");
//    char **array = tmp(command);
//
//    for (size_t i = 0; commands[i].name; i++) {
//        if (strcmp(array[0], commands[i].name) == 0) {
//            client = commands[i].func(client, array);
//            free_split(array);
//            return client;
//        }
//    }
    free_split(array);
//    dprintf(client->fd, "Unknown command.\n");
    return client;
}