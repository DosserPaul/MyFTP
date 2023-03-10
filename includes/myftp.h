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
#include <dirent.h>
#include <signal.h>

    typedef struct client_fd client_fd_t;
    typedef struct server server_t;
    typedef struct client client_t;
    typedef struct commands commands_t;

    struct client_fd {
        int fd[FD_SETSIZE];
        struct sockaddr_in addr;
        int max_fd;
        fd_set master;
    };

    struct server {
        int port;
        int fd;
        struct sockaddr_in addr;
        int max_fd;
        fd_set master;
        fd_set read_fds;
    };

    struct client {
        int fd;
        char *path;
        char *original_path;
        bool user;
        bool pass;
        bool is_closed;
        fd_set master;
        bool welcome;
    };

    struct commands {
        char *name;
        client_t *(*func)(client_t * client, char **cmd);
    };

    server_t *create_server(int port);
    int loop(server_t *server, char *path);
    void client_handler(server_t *server, int fd, client_t *client);
    int check_error(int nb, const char *str);
    char **split(char *str, const char *delim);
    void free_split(char **array);
    void free_clients(client_t **clients);

    // Commands
    client_t *command_handler(client_t *client, char *command, fd_set *master);
    bool is_logged(client_t *client);
    client_t *user(client_t *client, char **array);
    client_t *pass(client_t *client, char **array);
    client_t *noop(client_t *client, char **cmd);
    client_t *help(client_t *client, char **cmd);
    client_t *pwd(client_t *client, char **cmd);
    client_t *cwd(client_t *client, char **cmd);
    client_t *cdup(client_t *client, char **cmd);
    client_t *quit(client_t *client, fd_set *master);
    client_t *delete(client_t *client, char **cmd);

#endif //MYFTP_MYFTP_H
