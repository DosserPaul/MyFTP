/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** cdw
*/

#include "../../includes/myftp.h"

static char *get_full_path(client_t *client, char *directory)
{
    int len = strlen(client->original_path) + strlen(client->path) + 2;
    char *full_path = malloc(sizeof(char) * len);
    if (!full_path)
        return NULL;

    if (strcmp(client->path, "/") == 0) {
        strcpy(full_path, client->original_path);
        full_path = my_strcat(full_path, "/");
        full_path = my_strcat(full_path, directory);
        full_path = my_strcat(full_path, "\0");
    } else {
        strcpy(full_path, client->original_path);
        full_path = my_strcat(full_path, client->path);
        full_path = my_strcat(full_path, "/");
        full_path = my_strcat(full_path, directory);
        full_path = my_strcat(full_path, "\0");
        printf("%s\n", full_path);
    }

    return full_path;
}

bool directory_exist(client_t *client, char *directory)
{
    char *full_path = get_full_path(client, directory);
    directory[strlen(directory) - 1] = '\0';
    DIR *dir = opendir(full_path);
    full_path[strlen(full_path) - 1] = '\0';
    free(full_path);
    if (!dir) {
        return false;
    }
    closedir(dir);
    return true;
}

client_t *cwd(client_t *client, char *cmd)
{
    if (!is_logged(client))
        return client;
    char **tab = cmd_to_array(cmd);
    int array_len = get_array_size(tab);
    if (array_len == 1) {
        dprintf(client->client_fd, "550 No such directory.\r\n");
        return client;
    }
    char *full_path = get_full_path(client, tab[1]);

    if (directory_exist(client, tab[1])) {
        dprintf(client->client_fd, "550 No such directory.\r\n");
        return client;
    }
    chdir(full_path);
    printf("%s\n", client->path);
    if (strcmp(client->path, "/") != 0)
        client->path = my_strcat(client->path, "/");
    client->path = my_strcat(client->path, tab[1]);
    free(full_path);
    free_2d_array(tab);
}