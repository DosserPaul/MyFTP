/*
** EPITECH PROJECT, 2022
** MyFTP
** File description:
** main
*/

#include "myftp.h"

int main(int ac UNUSED, char **av UNUSED)
{
    // TODO: check args
    server_t *server = create_server(atoi(av[1]));

    // TODO: add path
//    loop(server, av[2]);
    loop(server, ".");
//    loop(server, "/src");

    return 0;
}