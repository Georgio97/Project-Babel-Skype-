/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Main.cpp
*/

#include <iostream>
#include "ServerManager.h"

int main(int ac, char **av)
{
    ServerManager *serverManager = new ServerManager;

    serverManager->launchServer();
    delete serverManager;
    return 0;
}