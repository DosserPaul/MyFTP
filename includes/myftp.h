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
#include <dirent.h>

typedef struct server {
    int port;
    int server_fd;
//    int client_fd;
    struct sockaddr_in server_addr;
    int addr_size;
    char *path;
} server_t;

typedef struct client {
    int client_fd;
    struct sockaddr_in client_addr;
    int addr_size;
    char *path;
    char *original_path;
    bool user;
    bool is_logged;
} client_t;

typedef struct command {
    char *command;
    client_t *(*func)(client_t *client, char *cmd);
} command_t;

server_t *create_server(server_t *server);
int check_error(int nb, const char *str);
void loop_connection(server_t server);
void loop(server_t *server);
client_t *pointer(char *cmd, client_t *client);

char **cmd_to_array(char *cmd);
int get_array_size(char **array);
char *my_strcat(char *dest, char *src);

void free_2d_array(char **array);
void free_server(server_t *server);
void free_client(client_t *client);

// CMD
bool is_logged(client_t *client);
client_t *noop(client_t *client, char *cmd);
client_t *pwd(client_t *client, char *cmd);
client_t *user(client_t *client, char *cmd);
client_t *pass(client_t *client, char *cmd);
client_t *help(client_t *client, char *cmd);

client_t *cwd(client_t *client, char *cmd);
client_t *cdup(client_t *client, char *cmd);

#endif //MYFTP_MYFTP_H
