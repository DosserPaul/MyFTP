/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** loop
*/

#include "myftp.h"

static client_t **init_client(char *path)
{
    client_t **client = malloc(sizeof(client_t *) * FD_SETSIZE);

    for (size_t i = 0; i < FD_SETSIZE; i++) {
        client[i] = malloc(sizeof(client_t));
        client[i]->original_path = strdup(path);
        client[i]->path = strdup("/");
        client[i]->user = false;
        client[i]->pass = false;
        client[i]->is_closed = false;
    }
    return client;
}

int accept_new_connection(int server_fd)
{
    UNUSED int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("accept");
        exit(84);
    }
    printf("[#] Client[%d] connected\n", client_fd);
    return client_fd;
}

void new_fd(server_t *server, int i, client_t *client)
{
    int new;

    if (FD_ISSET(i, &server->read_fds)) {
        if (i == server->fd) {
            new = accept_new_connection(server->fd);
            FD_SET(new, &server->master);
            if (new > server->max_fd)
                server->max_fd = new;
        } else {
            client_handler(server, i, client);
        }
    }
}

int loop(server_t *server, char *path)
{
    int select_ret;
    FD_ZERO(&server->master);
    FD_ZERO(&server->read_fds);
    FD_SET(server->fd, &server->master);
    server->max_fd = server->fd;
    client_t **client = init_client(path);
    while (true) {
        server->read_fds = server->master;
        select_ret = select(server->max_fd + 1, &server->read_fds, NULL, NULL, NULL);
        check_error(select_ret, "[-]Select(): ");

        printf("[#] Select returned: %d\n", select_ret);
        printf("[#] Max FD: %d\n", server->max_fd);

        for (int i = 0; i <= server->max_fd; i++) {
            new_fd(server, i, client[i]);
        }

    }
}