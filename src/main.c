/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** main
*/

#include "../includes/myftp.h"

static bool check_if_path_exist(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == 0)
        return true;
    return false;
}

static server_t *get_path(char *path, server_t *server)
{
    char *current_path = malloc(sizeof(char) * 1024);
    getcwd(current_path, 1024);
    char *new_path = malloc(sizeof(char) * 1024);
    strcpy(new_path, current_path);
    if (path[strlen(path) - 1] == '/')
        path[strlen(path) - 1] = '\0';
    if (strcmp(path, ".") != 0) {
        strcat(new_path, "/");
        strcat(new_path, path);
    }
    if (check_if_path_exist(new_path) == false) {
        fprintf(stderr, "[-]Error: Directory %s does not exist\n", new_path);
        exit(84);
    }
    server->path = malloc(sizeof(char) * (strlen(new_path) + 1));
    strcpy(server->path, new_path);
    return server;
}

static server_t *check_args(int ac, char **av)
{
    if (ac < 3) {
        fprintf(stderr, "Usage: ./myftp port\n");
        exit(84);
    }
    if (atoi(av[1]) < 1 || atoi(av[1]) > 65535) {
        fprintf(stderr, "[-]Port must be between 1 and 65535\n");
        exit(84);
    }

    server_t *server = malloc(sizeof(server_t));
    server->port = atoi(av[1]);
    server = get_path(av[2], server);
    return server;
}

int main(int ac, char **av)
{
    server_t *server = check_args(ac, av);
    server = create_server(server);

    loop(server);

    return 0;
}