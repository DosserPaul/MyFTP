/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** loop
*/

#include "myftp.h"

static void new_fd(client_fd_t *client, fd_set *readfds)
{
    int tmp;
    int select_ret;

    for (size_t i = 0; i < FD_SETSIZE; i++) {
        tmp = client->fd[i];
        if (tmp > 0)
            FD_SET(tmp, readfds);
        if (tmp > client->max_fd)
            client->max_fd = tmp;
    }
    select_ret = select(FD_SETSIZE + 1, readfds, NULL, NULL, NULL);
    check_error(select_ret, "[-]Select()");
}

static void check_accept(client_fd_t *client, fd_set *readfds, int server_fd)
{
    socklen_t addr_len = sizeof(client->addr);
    int new_fd;

    if (FD_ISSET(server_fd, readfds)) {
        new_fd = accept(server_fd, (struct sockaddr *)&client->addr, &addr_len);
        check_error(new_fd, "[-]Accept()");
        printf("[+]New client connected\n");
        dprintf(new_fd, "Welcome to the server\n");
        for (size_t i = 0; i < FD_SETSIZE; i++) {
            if (client->fd[i] == 0) {
                client->fd[i] = new_fd;
                break;
            }
        }
    }
}

client_t **init_client(char *path UNUSED)
{
    client_t **client = malloc(sizeof(client_t *) * FD_SETSIZE);

    for (size_t i = 0; i < FD_SETSIZE; i++) {
        client[i] = malloc(sizeof(client_t));
        client[i]->original_path = strdup(path);
        client[i]->path = strdup("/");
        client[i]->user = false;
        client[i]->pass = false;
    }
    return client;
}

static void client_action(client_fd_t *client_fd, fd_set *readfds, client_t **c)
{
    int tmp;

    for (size_t i = 0; i < FD_SETSIZE; i++) {
        tmp = client_fd->fd[i];
        if (FD_ISSET(tmp, readfds)) {
            client_handler(tmp, c[i]);
        }
    }
}

int loop(server_t *server, char *path)
{
    client_fd_t *client = malloc(sizeof(client_fd_t));
    fd_set readfds;
    client_t  **clients = init_client(path);

    for (size_t i = 0; i < FD_SETSIZE; i++)
        client->fd[i] = 0;

    while (true) {
        FD_ZERO(&readfds);
        FD_SET(server->fd, &readfds);
        client->max_fd = server->fd;
        new_fd(client, &readfds);
        check_accept(client, &readfds, server->fd);
        client_action(client, &readfds, clients);
    }
}