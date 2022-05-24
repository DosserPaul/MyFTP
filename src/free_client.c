/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** free_client
*/

#include "myftp.h"

void free_clients(client_t **clients)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (clients[i] != NULL) {
            free(clients[i]->path);
            free(clients[i]->original_path);
            free(clients[i]);
        }
    }
    free(clients);
}