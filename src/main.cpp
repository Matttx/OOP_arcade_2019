/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main.cpp
*/

#include <iostream>
#include "dlhandler.hpp"

int openLib(const char *libpath)
{
    dlHandler handler(libpath);
    IDescription *guy = handler.create();
    std::cout << guy->getFirstName() << " " << guy->getLastName() << " " << guy->getAge() << std::endl;
    return 0;
}

int main()
{
    openLib("dynamicLibrary/Guillaume/libgui.so");
    openLib("dynamicLibrary/Matteo/libmat.so");
    openLib("dynamicLibrary/Thomas/libtom.so");
    return 0;
}