/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** dlhandler.hpp
*/

#ifndef OOP_ARCADE_2019_DLHANDLER_HPP
#define OOP_ARCADE_2019_DLHANDLER_HPP

#include "IDescription.hpp"
#include <dlfcn.h>
#include <string>
#include <memory>

class dlHandler {
public:
    explicit dlHandler(const char *file = "dynamicLibrary/Guillaume/libgui.so");
    IDescription* create() const;
    ~dlHandler();
private:
    void * _handler = nullptr;
    DesCreator _creator = nullptr;
    static void resetDlerror();
    static void checkDlerror();
};

#endif // OOP_ARCADE_2019_DLHANDLER_HPP
