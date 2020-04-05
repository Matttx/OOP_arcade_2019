/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Action.cpp
*/

#include "Action.hpp"

emulator::component::Action::Action(
    engine::ecs::Entity& entity, const Callback& callback)
    : AComponent(entity), callback(callback)
{
}

emulator::component::Action::~Action() = default;
