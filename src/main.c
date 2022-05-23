/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** main
*/

#include "myftp.h"

static char *get_path(char *path)
{
    char buffer[1024];
    char *full_path = NULL;
    char *tmp = NULL;

    getcwd(buffer, 1024);

    if (strcmp(path, ".") == 0)
       return strdup(buffer);


    tmp = malloc(sizeof(char) * (strlen(buffer) + 2));
    tmp = strcpy(tmp, buffer);
    full_path = malloc(sizeof(char) * (strlen(tmp) + strlen(path) + 2));
    strncpy(full_path, tmp, strlen(tmp) + 1);
    if (path[0] != '/')
        full_path = strcat(full_path, "/");
    full_path = strcat(full_path, path);
    free(tmp);
    return full_path;
}

static bool check_path(char *path)
{
    char *full_path = get_path(path);
    DIR *dir = opendir(full_path);
    if (!dir) {
        free(full_path);
        return false;
    }
    free(full_path);
    closedir(dir);
    return true;
}

static bool is_arg_valid(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: ./myftp port path\n");
        return false;
    }
    if (atoi(argv[1]) == 0) {
        fprintf(stderr, "Invalid port\n");
        return false;
    }
    if (atoi(argv[1]) < 0 || atoi(argv[1]) > 65535) {
        fprintf(stderr, "Invalid port\n");
        return false;
    }
    if (!check_path(argv[2])) {
        fprintf(stderr, "Invalid path\n");
        return false;
    }
    return true;
}

int main(int ac UNUSED, char **av UNUSED)
{
    if (!is_arg_valid(ac, av))
        return 84;

    server_t *server = create_server(atoi(av[1]));
    if (!server)
        return 84;

    loop(server, get_path(av[2]));

    return 0;
}