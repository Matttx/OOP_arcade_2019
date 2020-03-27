/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLManager.hpp
*/

#ifndef OOP_ARCADE_2019_DLMANAGER_HPP
#define OOP_ARCADE_2019_DLMANAGER_HPP

#include <dlfcn.h>

#include <memory>
#include <string>

#include "../../dynamicLibrary/IGraphical.hpp"

using Creator = IGraphical* (*)();

class DLManager {
  public:
    explicit DLManager(
        const std::string& file = "dynamicLibrary/Guillaume/libgui.so");
    IGraphical* create() const;
    ~DLManager();

  private:
    void* _handler = nullptr;
    Creator _creator = nullptr;
    static void resetDlerror();
    static void checkDlerror();
};

#endif // OOP_ARCADE_2019_DLMANAGER_HPP
