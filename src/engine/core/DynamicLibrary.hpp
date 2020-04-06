/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DynamicLibrary.hpp
*/

/**
 * @brief Class to manage dynamic library
 */

#ifndef OOP_ARCADE_2019_DYNAMICLIBRARY_HPP
#define OOP_ARCADE_2019_DYNAMICLIBRARY_HPP

#include <dlfcn.h>

#include <stdexcept>
#include <string>

#include "../util/Error.hpp"

namespace engine {

namespace core {
/**
 * @class Class of DynamicLibrary
 *
 */
template<typename T>
class DynamicLibrary {
  public:
    /**
     * @brief Constructor of DynamicLibrary
     *
     * @tparam TArgs Variadic parameter pack
     * @param path Path of the dynamic library
     * @param args Arguments that dynamic library constructor takes
     */
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

    /**
     * @brief Constructor of DynamicLibrary (with an already defined instance)
     *
     * @param instance Instance of the dynamic library
     */
    explicit DynamicLibrary(T* instance)
    {
        _handler = nullptr;
        _instance = instance;
    }

    /**
     * @brief Destructor of DynamicLibrary
     */
    ~DynamicLibrary()
    {
        if (_instance)
            delete _instance;

        if (_handler)
            dlclose(_handler);
    }

    /**
     * @brief Get the instance of the dynamic library
     *
     * @return Reference of the instance
     */
  public:
    T& get() const
    {
        if (_instance == nullptr)
            throw util::Error("engine::core::DynamicLibrary::get()", "Bad instance");

        return *_instance;
    }

  private:
    /**
     * @brief Handler of the dynamic library
     */
    void* _handler;
    /**
     * @brief Instance of the dynamic library
     */
    T* _instance;
};

} // namespace core

} // namespace engine

#endif // OOP_ARCADE_2019_DYNAMICLIBRARY_HPP
