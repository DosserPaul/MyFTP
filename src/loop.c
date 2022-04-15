/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** loop
*/

#include "../includes/myftp.h"

void loop(server_t *server)
{
    client_t *client = malloc(sizeof(client_t));
    client->client_len = sizeof(client->client_addr);

    while (1) {
        client->client_fd = accept(server->server_fd, (struct sockaddr *)
                &client->client_addr, &client->client_len);
        check_error(client->client_len, "[-]Error accept()");
        printf("[+]Client connected\n");

        while (1) {
            if ((client->client_len = recv(client->client_fd, server->buffer,
                                          1024, 0) < 0))
                check_error(client->client_len, "[-]Error recv()");
            printf("%s\n", server->buffer);
        }
    }
}

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