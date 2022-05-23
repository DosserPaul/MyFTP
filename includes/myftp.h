/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** myftp
*/

#ifndef UNUSED
    #define UNUSED __attribute__((unused))
#endif

#ifndef NORETURN
    #define NORETURN __attribute__ ((noreturn))
#endif

#ifndef MYFTP_MYFTP_H
    #define MYFTP_MYFTP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

    typedef struct client_fd client_fd_t;
    typedef struct server server_t;
    typedef struct client client_t;
    typedef struct commands commands_t;

    struct client_fd {
        int fd[FD_SETSIZE];
        struct sockaddr_in addr;
        int max_fd;
    };

    struct server {
        int port;
        int fd;
        struct sockaddr_in addr;
    };

    struct client {
        int fd;
        char *path;
        char *original_path;
        bool user;
        bool pass;
    };

    struct commands {
        char *name;
        client_t *(*func)(client_t * client, char **cmd);
    };

server_t *create_server(int port);
int loop(server_t *server);
void client_handler(int fd);
int check_error(int nb, const char *str);
char **split(char *str, const char *delim);
void free_split(char **array);

// Commands
client_t *command_handler(client_t *client, char *command);

#endif //MYFTP_MYFTP_H
