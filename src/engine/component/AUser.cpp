/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AUser.cpp
*/

#include "AUser.hpp"

engine::component::AUser::AUser(engine::ecs::Entity& entity)
    : AComponent(entity)
{
}

engine::component::AUser::~AUser() = default;
