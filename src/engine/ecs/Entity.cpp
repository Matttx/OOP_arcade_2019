/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

engine::ecs::Entity::Entity(engine::ecs::World& world) : _world(world)
{
}

engine::ecs::Entity::~Entity()
{
    for (const auto& _component : _components)
        delete &_component.second.get();
};

engine::ecs::World& engine::ecs::Entity::getWorld() const
{
    return this->_world;
}
