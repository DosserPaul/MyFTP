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
    if (!check_if_path_exist(av[2])) {
        fprintf(stderr, "[-]Path doesn't exist\n");
        exit(84);
    }

    server_t *server = malloc(sizeof(server_t));
    server->port = atoi(av[1]);
    server->path = malloc(sizeof(char) * (strlen(av[2]) + 1));
    strcpy(server->path, av[2]);

    return server;
}

int main(int ac, char **av)
{
    server_t *server = check_args(ac, av);
    server = create_server(server);

    loop(server);

    return 0;
}