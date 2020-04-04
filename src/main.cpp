/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main.cpp
*/

#include <unistd.h>

#include "engine/core/Core.hpp"

int main()
{
    engine::core::Core core;

    core.loadGames();
    core.loadGraphics();

    core.setCurrentGraphical("lib_arcade_sdl.so");
    core.switchGraphical();
    core.setCurrentGame("emulator");

    auto &universe = core.getUniverse();

    universe.init();

    for (int i = 0; i >= 0; ++i) {
        core.switchGraphical();
        core.getCurrentGraphical().dispatchEvent();
        universe.update();
        universe.render();

        usleep(16666);
    }
}