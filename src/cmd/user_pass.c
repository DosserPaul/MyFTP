/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** user_pass
*/
#include <ctype.h>

#include "../../includes/myftp.h"

client_t *user(client_t *client, char *cmd)
{
    if (client->is_logged)
        return client;

    char **tab = cmd_to_array(cmd);
    int array_len = get_array_size(tab);

    if (array_len != 2) {
        dprintf(client->client_fd, "530 Bad USER.\r\n");
        free(tab);
        return client;
    }


    if (array_len == 2) {
        if (strcmp(tab[1], "Anonymous\r") == 0) {
            dprintf(client->client_fd, "230 User logged in.\r\n");
            client->user = true;
            free(tab);
            return client;
        }
        dprintf(client->client_fd, "530 Bad USER.\r\n");
        free(tab);
        return client;
    }
}

client_t *pass(client_t *client, char *cmd)
{
    if (client->is_logged)
        return client;

    if (!client->user) {
        dprintf(client->client_fd, "503 Login with USER before.\r\n");
        return client;
    }
    char **tab = cmd_to_array(cmd);
    int array_len = get_array_size(tab);
    if (array_len == 1) {
        dprintf(client->client_fd, "530 Bad PASS.\r\n");
        free(tab);
        return client;
    }
    if (array_len == 2) {
        if (strcmp(tab[1], "\r") == 0) {
            dprintf(client->client_fd, "230 User logged in.\r\n");
            client->is_logged = true;
            free(tab);
            return client;
        }
        dprintf(client->client_fd, "530 Bad PASS.\r\n");
        free(tab);
        return client;
    }
}