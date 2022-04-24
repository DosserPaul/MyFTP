/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** parse_cmd
*/

#include "../includes/myftp.h"

static char *remove_multiple_space(char *cmd)
{
    char *new_cmd;

    for (; *str; ++str) {
        *dest = *str;

        if (*str == ' ' || *str == '\t') {
            while (*str == ' ' || *str == '\t')
                ++str;
            *dest++ = ' ';
        }
    }

    *dest = '\0';

    return new_cmd;
}

static char **toMalloc(char *cmd)
{
    char **cmd_tab;
    size_t count = 0;

    for (size_t i = 0; i < strlen(cmd); i++) {
        if (cmd[i] != ' ') {
            count++;
        }
            count++;
    }
}

char **parse_cmd(char *cmd)
{
    char *cmd = remove_multiple_space(cmd);
    char *ptr = strtok(cmd, " ");



    return cmd_tab;
}