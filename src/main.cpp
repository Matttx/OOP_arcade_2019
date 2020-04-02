/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main.cpp
*/

#include "engine/core/Core.hpp"

int main()
{
    engine::core::Core core;

    core.loadGames();
    core.loadGraphics();

    core.setCurrentGraphical("lib_arcade_sfml.so");
    core.setCurrentGame("emulator");

    core.getCurrentGraphical().init();
    core.getCurrentGame().init();

    auto &universe = core.getUniverse();

    universe.init();

    while (true) {
        universe.update();
        universe.render();
    }
}