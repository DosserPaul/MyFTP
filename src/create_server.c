/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** create_server
*/

#include "myftp.h"

static server_t *config_server(server_t *server)
{
    server->addr.sin_family = AF_INET;
    server->addr.sin_addr.s_addr = INADDR_ANY;
    server->addr.sin_port = htons(server->port);

    return server;
}

server_t *create_server(int port) {
    server_t *server = malloc(sizeof(server_t));
    server->port = port;

    server->fd = socket(AF_INET, SOCK_STREAM, 0);
    check_error(server->fd, "[-]Error: socket()\n");
    printf("[+]Server socket created\n");

    server = config_server(server);

    if (bind(server->fd, (struct sockaddr *)
            &server->addr, sizeof(server->addr)) == -1)
        check_error(server->fd, "[-]Error: bind()\n");
    printf("[+]Server binded\n");

    if (listen(server->fd, 10) == -1)
        check_error(server->fd, "[-]Error: listen()\n");
    printf("[+]Server listening\n");

    return server;
}