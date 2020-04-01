/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DynamicLibrary.hpp
*/

#ifndef OOP_ARCADE_2019_DYNAMICLIBRARY_HPP
#define OOP_ARCADE_2019_DYNAMICLIBRARY_HPP

#include <dlfcn.h>

#include <stdexcept>
#include <string>

namespace engine {

namespace core {

template<typename T>
class DynamicLibrary {
  public:
    template<typename... TArgs>
    explicit DynamicLibrary(const std::string& path, TArgs... args)
    {
        using Creator = T* (*)(TArgs... args);

        _handler = dlopen(path.c_str(), RTLD_LAZY);

        if (!_handler)
            throw std::runtime_error(dlerror()); // TODO: Custom Error class

        auto creator = reinterpret_cast<Creator>(dlsym(_handler, "create"));

        if (!creator)
            throw std::runtime_error(dlerror()); // TODO: Custom Error class

        _instance = creator(args...);
    }

    ~DynamicLibrary()
    {
        delete _instance;

        dlclose(_handler);
    }

  public:
    T& get() const
    {
        return *_instance;
    }

  private:
    void* _handler;
    T* _instance;
};

} // namespace core

} // namespace engine

#endif // OOP_ARCADE_2019_DYNAMICLIBRARY_HPP
