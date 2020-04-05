/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Movement.cpp
*/

#include "Movement.hpp"

#include "../component/Motion.hpp"
#include "../component/Transform.hpp"
#include "../ecs/World.hpp"

engine::system::Movement::Movement(engine::ecs::World& world) : ASystem(world)
{
}

engine::system::Movement::~Movement() = default;

void engine::system::Movement::init()
{
}

void engine::system::Movement::update()
{
    auto entities =
        this->getWorld().getEntities<component::Motion, component::Transform>();

    for (const auto& entity : entities) {
        auto& motion = entity.get().getComponent<component::Motion>();
        auto& transform = entity.get().getComponent<component::Transform>();

        motion.velocity.x += motion.acceleration.x;
        motion.velocity.y += motion.acceleration.y;

        transform.position.x += motion.velocity.x;
        transform.position.y += motion.velocity.y;
    }
}

void engine::system::Movement::render()
{
}
