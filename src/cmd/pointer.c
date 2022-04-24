/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** pointer
*/

#include "../../includes/myftp.h"

bool is_equal(char *str1, char *str2)
{
    char *tmp = strdup(str1);
    printf("-*-%s-*-\n", tmp);

    if (tmp == NULL || str2 == NULL) {
        free(tmp);
        return false;
    }
    if (strlen(tmp) != strlen(str2)) {
        free(tmp);
        return false;
    }

    for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] != str2[i]) {
            free(tmp);
            return false;
        }
    }
    free(tmp);
    return true;
}

command_t command_tab[] = {
        {"USER", &user},
        {"PASS", &pass},
        {"CWD", &cwd},
        {"CDUP\r", &cdup},
//        {"QUIT", &quit},
//        {"DELE", &dele},
        {"PWD\r", &pwd},
//        {"PASV", &pasv},
//        {"PORT", &port},
//        {"HELP", &help},
        {"NOOP\r", &noop},
//        {"RETR", &retr},
//        {"STOR", &stor},
//        {"LIST", &list}
};

client_t *pointer(char *cmd, client_t *client)
{
    int i = 0;

    char **tab = cmd_to_array(cmd);

//    if (tab[0][strlen(tab[0])] == '\n')
//        tab[0][strlen(tab[0])] = '\0';

    for (int i = 0; i < strlen(tab[0]); i++)
        printf("%c -*- %d\n", tab[0][i], tab[0][i]);


    while (i < 6) {
        if (is_equal(tab[0], command_tab[i].command)) {
//            if (strcmp(command_tab[i].command, tab[0]) == 0) {
            printf("%s\n", command_tab[i].command);
            return command_tab[i].func(client, cmd);
        }
        i++;
    }
    dprintf(client->client_fd, "500 Syntax error, command unrecognized.\r\n");
    return client;
}