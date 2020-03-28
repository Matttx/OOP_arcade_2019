/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Collision.cpp
*/

#include "Collision.hpp"

engine::event::Collision::Collision(
    engine::ecs::Entity& entity1, engine::ecs::Entity& entity2)
    : entity1(entity1), entity2(entity2)
{
}

engine::event::Collision::~Collision() = default;
