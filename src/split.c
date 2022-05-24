/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** split
*/

#include "myftp.h"

static int get_nb_words(const char *str, char delim)
{
    int nb_words = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim && str[i + 1] != '\0')
            nb_words++;
    }

    return nb_words + 1;
}

static int *get_words_size(char *str, const char *delim)
{
    int *words_size = malloc(sizeof(int) * get_nb_words(str, delim[0]));

    int i = 0;
    char *cpy = strdup(str);
    char *tmp = strtok(cpy, delim);

    while (tmp != NULL) {
        words_size[i] = (int)strlen(tmp);
        tmp = strtok(NULL, delim);
        i++;
    }

    free(cpy);
    free(tmp);
    return words_size;
}

static char **malloc_2d_array(char *str, const char *delim)
{
    int nb_words = get_nb_words(str, delim[0]);
    int *words_size = get_words_size(str, delim);
    char **array = malloc(sizeof(char *) * (nb_words + 1));

    for (size_t i = 0; i < (size_t)nb_words; i++)
        array[i] = calloc(words_size[i] + 1, sizeof(char));
    array[nb_words] = NULL;

    free(words_size);
    return array;
}

char **split(char *str, const char *delim)
{
    char **array = malloc_2d_array(str, delim);
    char *cpy = strdup(str);

    int i = 0;
    char *tmp = strtok(cpy, delim);

    while (tmp != NULL) {
        strcpy(array[i], tmp);
        tmp = strtok(NULL, delim);
        i++;
    }
//    int nb_words = get_nb_words(str, delim[0]);
//    char *tmp2 = array[nb_words - 1];
//    array[nb_words - 1][strlen(tmp2) - 1] = '\0';

    free(tmp);
    free(cpy);
    return array;
}

void free_split(char **array)
{
    for (size_t i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
