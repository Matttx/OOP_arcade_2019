/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLManager.cpp
*/

#include "DLManager.hpp"

#include <dlfcn.h>

#include <iostream>

#include "../../dynamicLibrary/IGraphical.hpp"

DLManager::DLManager(const std::string& libpath)
{
    _handler = dlopen(libpath.c_str(), RTLD_LAZY);
    if (!_handler) {
        throw std::runtime_error(dlerror());
    }
    resetDlerror();
    _creator = reinterpret_cast<Creator>(dlsym(_handler, "createObject"));
    checkDlerror();
}

DLManager::~DLManager()
{
    if (_handler) {
        dlclose(_handler);
    }
}

IGraphical* DLManager::create() const
{
    return _creator();
}

void DLManager::resetDlerror()
{
    dlerror();
}

void DLManager::checkDlerror()
{
    std::string dlsymError = dlerror();
    if (dlsymError.c_str()) {
        throw std::runtime_error(dlsymError);
    }
}
