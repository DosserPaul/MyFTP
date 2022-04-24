/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** cmd_to_array
*/

#include <string.h>

#include "../includes/myftp.h"

int count_words(char *cmd)
{
    int count = 0;

    for (int i = 0; i < (int)strlen(cmd); i++) {
        if (cmd[i] == ' ' || cmd[i] == '\t')
            count++;
    }
    count++;
    return count;
}

static int *count_char(char *cmd, int nb_words)
{
    int *nb_char = malloc(sizeof(int) * nb_words);
    int count = 0;
    int pos = 0;

    for (size_t i = 0; i < (int)strlen(cmd) + 1; i++) {
        count++;
        if (cmd[i] == ' ' || cmd[i + 1] == '\0') {
            nb_char[pos] = count;
            count = 0;
            pos++;
        }
    }

    for (int i = 0; i < nb_words; i++)
        nb_char[i]--;

    return nb_char;
}

static char **malloc_2d(int nb_words, int *nb_char)
{
    char **array = malloc(sizeof(char *) * (nb_words + 1));

    for (int i = 0; i < nb_words; i++)
        array[i] = malloc(sizeof(char) * (nb_char[i] + 1));

    array[nb_words] = NULL;

    return array;
}

char **cmd_to_array(char *cmd)
{
    int nb_words = count_words(cmd);
    int *nb_char = count_char(cmd, nb_words);
    char **cmd_array = malloc_2d(nb_words, nb_char);
    int current_word = 0;
    int current_char = 0;

    for (size_t i = 0; i < strlen(cmd) - 1; i++) {
        cmd_array[current_word][current_char] = cmd[i];
        if (cmd[i] == ' ') {
            current_word++;
            current_char = 0;
        } else
            current_char++;
    }

    for (size_t i = 0; i < (size_t)nb_words; i++)
        cmd_array[i][nb_char[i]] = '\0';

    free(nb_char);
    return cmd_array;
}

int get_array_size(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;

    return i;
}