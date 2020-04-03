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

#include "../util/Error.hpp"

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
            throw util::Error("engine::core::DynamicLibrary()", dlerror());

        auto creator = reinterpret_cast<Creator>(dlsym(_handler, "create"));

        if (!creator)
            throw util::Error("engine::core::DynamicLibrary()", dlerror());

        _instance = creator(args...);
    }

    explicit DynamicLibrary(T* instance)
    {
        _instance = instance;
        _handler = nullptr;
    }

    ~DynamicLibrary()
    {
        if (_instance)
            delete _instance;

        if (_handler)
            dlclose(_handler);
    }

  public:
    T& get() const
    {
        if (_instance == nullptr)
            throw util::Error(
                "engine::core::DynamicLibrary::get()", "Bad instance");

        return *_instance;
    }

  private:
    void* _handler;
    T* _instance;
};

} // namespace core

} // namespace engine

#endif // OOP_ARCADE_2019_DYNAMICLIBRARY_HPP
