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

    core.init("lib_arcade_sdl.so");

    core.run();
}