/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

engine::ecs::AComponent::AComponent(Entity& entity) : _entity(entity)
{
}

engine::ecs::AComponent::~AComponent() = default;

engine::ecs::Entity& engine::ecs::AComponent::getEntity() const
{
    return this->_entity;
}