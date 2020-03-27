/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ASystem.cpp
*/

#include "ASystem.hpp"

engine::ecs::ASystem::ASystem(World& world) : _world(world)
{
}

engine::ecs::ASystem::~ASystem() = default;

engine::ecs::World& engine::ecs::ASystem::getWorld() const
{
    return this->_world;
}