/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** free
*/

#include "../includes/myftp.h"

void free_2d_array(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        free(array[i]);
        i++;
    }
    free(array);
}

void free_server(server_t *server)
{
    free(server->path);
    free(server);
}

void free_client(client_t *client)
{
    free(client->path);
    free(client->original_path);
    free(client);
}