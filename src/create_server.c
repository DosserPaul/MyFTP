/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** create_server
*/

#include <arpa/inet.h>

#include "../includes/myftp.h"

static server_t *config_server(server_t *server)
{
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_addr.s_addr = INADDR_ANY;
    server->server_addr.sin_port = htons(server->port);

    return server;
}

server_t *create_server(server_t *server)
{
    server->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    check_error(server->server_fd, "[-]Error: socket()\n");
    printf("[+]Server socket created\n");

    server = config_server(server);

    if (bind(server->server_fd, (struct sockaddr *)&server->server_addr,
        sizeof(server->server_addr)) == -1)
        check_error(server->server_fd, "[-]Error: bind()\n");
    printf("[+]Server binded\n");

    if (listen(server->server_fd, 10) == -1)
        check_error(server->server_fd, "[-]Error: listen()\n");
    printf("[+]Server listening\n");

    return server;
}