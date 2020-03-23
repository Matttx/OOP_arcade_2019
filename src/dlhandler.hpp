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
    dlHandler(const char *file = "dynamicLibrary/Guillaume/libgui.so") {
        handler = dlopen(file, RTLD_LAZY);
        if (! handler) {
            throw std::runtime_error(dlerror());
        }
        Reset_dlerror();
        creator = reinterpret_cast<DesCreator>(dlsym(handler, "create_object"));
        destroyer = (void (*)(IDescription*))dlsym(handler, "destroy_object");
        Check_dlerror();
    }

    IDescription* create() const {
        return creator();
    }

    void destroy(IDescription* obj) {
        destroyer(obj);
    }

    ~dlHandler() {
        if (handler) {
            dlclose(handler);
        }
    }
private:
    void * handler = nullptr;
    DesCreator creator = nullptr;
    void (*destroyer)(IDescription*);

    static void Reset_dlerror() {
        dlerror();
    }

    static void Check_dlerror() {
        const char * dlsym_error = dlerror();
        if (dlsym_error) {
            throw std::runtime_error(dlsym_error);
        }
    }
};

#endif // OOP_ARCADE_2019_DLHANDLER_HPP
