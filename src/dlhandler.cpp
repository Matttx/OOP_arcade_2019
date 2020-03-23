/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** dlhandler.cpp
*/

#include <dlfcn.h>
#include <iostream>
#include "dlhandler.hpp"

dlHandler::dlHandler(const char *libpath) {
    _handler = dlopen(libpath, RTLD_LAZY);
    if (!_handler) {
        throw std::runtime_error(dlerror());
    }
    resetDlerror();
    _creator = reinterpret_cast<DesCreator>(dlsym(_handler, "create_object"));
    checkDlerror();
}

dlHandler::~dlHandler() {
    std::cout << "je me detruit" << std::endl;
    if (_handler) {
        dlclose(_handler);
    }
}

std::unique_ptr<IDescription> dlHandler::create() const {
    return std::unique_ptr<IDescription>(_creator());
}

void dlHandler::resetDlerror() {
    dlerror();
}

void dlHandler::checkDlerror() {
    const char *dlsymError = dlerror();
    if (dlsymError) {
        throw std::runtime_error(dlsymError);
    }
}