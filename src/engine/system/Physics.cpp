/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Physics.cpp
*/

#include "Physics.hpp"

#include <iostream>

#include "../component/Hitbox.hpp"
#include "../component/Transform.hpp"
#include "../ecs/Universe.hpp"
#include "../event/Collision.hpp"

static bool isCollide(engine::component::Hitbox& hitbox1,
    engine::component::Transform& transform1,
    engine::component::Hitbox& hitbox2,
    engine::component::Transform& transform2)
{
    if ((transform1.position.x >= transform2.position.x) &&
        (transform1.position.x <= transform2.position.x + hitbox2.width) &&
        (transform1.position.y >= transform2.position.y) &&
        (transform1.position.y <= transform2.position.y + hitbox2.height))
        return true;

    return (transform2.position.x >= transform1.position.x) &&
        (transform2.position.x <= transform1.position.x + hitbox1.width) &&
        (transform2.position.y >= transform1.position.y) &&
        (transform2.position.y <= transform1.position.y + hitbox1.height);
}

engine::system::Physics::Physics(engine::ecs::World& world) : ASystem(world)
{
}

engine::system::Physics::~Physics() = default;

void engine::system::Physics::init()
{
}

void engine::system::Physics::update()
{
    auto entities =
        this->getWorld().getEntities<component::Hitbox, component::Transform>();

    for (std::size_t i = 0; i < entities.size(); ++i) {
        auto& hitbox1 = entities[i].get().getComponent<component::Hitbox>();
        auto& transform1 =
            entities[i].get().getComponent<component::Transform>();

        for (std::size_t j = i + 1; j < entities.size(); ++j) {
            auto& hitbox2 = entities[j].get().getComponent<component::Hitbox>();
            auto& transform2 =
                entities[j].get().getComponent<component::Transform>();

            if (isCollide(hitbox1, transform1, hitbox2, transform2)) {
                auto* event =
                    new event::Collision(entities[i].get(), entities[j].get());
                std::cout << "entity1: " << std::endl << "tranform : " << transform1.position.x << ", " << transform1.position.y << std::endl << "Hitbox : " << hitbox1.width << ", " << hitbox1.height << std::endl << "entity2:" << std::endl << "transform : " << transform2.position.x << ", " << transform2.position.y << std::endl << "Hitbox : " << hitbox2.width << ", " << hitbox2.height <<std::endl;
                this->getWorld().getUniverse().getEventBus().publish(*event);
                delete event;
            }
        }
    }
}

void engine::system::Physics::render()
{
}
