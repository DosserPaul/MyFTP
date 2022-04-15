/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** myftp
*/

#ifndef MYFTP_MYFTP_H
#define MYFTP_MYFTP_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct server {
    // port number
    int port;
    // socket file descriptor
    int server_fd;
    int client_fd;
    // server data structure for socket
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    // size of the data structure
    int server_len;
    int client_len;
    char buffer[1024];
} server_t;

typedef struct client {
    int client_fd;
    int client_len;
    struct sockaddr_in client_addr;
} client_t;

server_t *create_server(server_t *server);
int check_error(int nb, const char *str);
void loop_connection(server_t server);
void loop(server_t *server);

#endif //MYFTP_MYFTP_H
