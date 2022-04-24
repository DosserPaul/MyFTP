/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** loop
*/

#include "../includes/myftp.h"

static client_t *new_connection(server_t *server)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL) {
        fprintf(stderr, "[-]Error malloc new_connection\n");
        exit(84);
    }
    client->user = false;
    client->is_logged = true;
    client->path = strdup("/");
//    client->original_path = malloc(sizeof(char) * (strlen(server->path) + 1));
//    memcpy(client->original_path, server->path, strlen(server->path) + 1);
    client->original_path = strdup(server->path);

    client->addr_size = sizeof(client->client_addr);
    client->client_fd = accept(server->server_fd, (struct sockaddr *)
            &client->client_addr, &client->addr_size);
    check_error(client->client_fd, "[-]Error accept()\n");
    printf("[+]New connection\n");
    return client;
}

static bool handle_action(server_t *server, client_t *client)
{
    char *cmd = malloc(sizeof(char) * 1024);
    while (true) {
        if (read(client->client_fd, cmd, 1024) == 0) {
            printf("[-]Client disconnected\n");
            break;
        }
//        strtok(cmd, "\n");


        char *action = strdup(cmd);
        strtok(action, " ");
        printf("[+]Client sent: %s\n", cmd);

        if (strncmp(action, "QUIT", 4) == 0) {
            printf("[+]Client disconnected\n");
//            close(client->client_fd);
            break;
        }

//        client = pointer(cmd, client);

//        if (strncmp(action, "NOOP", 4) == 0)
//            client = noop(client, cmd);
//        if (strncmp(action, "PWD", 3) == 0)
//            client = pwd(client, cmd);
//        if (strncmp(action, "USER", 4) == 0)
//            client = user(client, cmd);
//        if (strncmp(action, "PASS", 4) == 0)
//            client = pass(client, cmd);
//
//        if (strncmp(action, "CWD", 3) == 0)
//            client = cwd(client, cmd);
//
//        if (strncmp(action, "..", 2) == 0)
//            client = cdup(client, cmd);

        memset(cmd, 0, 1024);

//        pointer(action, client);

//        if (strncmp(action, "QUIT", 4) == 0) {
//            close(client->client_fd);
//            printf("[+]Client disconnected\n");
//            close(server->server_fd);
//            printf("[+]Server closed\n");
//            exit(0);
//        }
    }
    close(client->client_fd);
    close(server->server_fd);
    free_client(client);
    free(server);
    free(cmd);
    exit(0);
}

void loop(server_t *server)
{
    while (true) {
        client_t *client = new_connection(server);

        handle_action(server, client);
    }
}

//        client->client_fd = accept(server->server_fd, (struct sockaddr *)
//                &client->client_addr, &client->client_len);
//        check_error(client->client_len, "[-]Error accept()");
//        printf("[+]Client connected\n");

//while (1) {
//            handle_action(server, client);
////            if ((client->client_len = recv(client->client_fd, server->buffer,
////                                          1024, 0) < 0))
////                check_error(client->client_len, "[-]Error recv()");
////            printf("%s\n", server->buffer);
//        }

//static int new_connection(int server_fd)
//{
//    int addrlen = sizeof(struct sockaddr_in);
//    int client_fd;
//    struct sockaddr_in client_addr;
//    check_error(client_fd = accept(server_fd, (struct sockaddr *)
//            &client_addr, (socklen_t *) &addrlen), "accept error");
//    return (client_fd);
//}
//
//static void handle_connection(int client)
//{
//    char *buffer = malloc(sizeof(char) * 1024);
//    size_t bytes_read;
//    int message_len = 0;
////    char path[1024+1];
//
//    while((bytes_read = recv(client, buffer, 1024, 0)) > 0) {
//        printf("[+]Connection successful\n");
//        message_len += bytes_read;
//        if (message_len > 1024 - 1 || buffer[bytes_read - 1] != '\n') {
//            printf("[-]Message too long\n");
//            break;
//        }
//        check_error(bytes_read, "[-]recv failed");
//        buffer[bytes_read - 1] = 0;
//
//        printf("REQUEST: %s\n", buffer);
//    }
//}

//void loop_connection(server_t server)
//{
//
//}