/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.cpp
*/

#include "User.hpp"

#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/event/Collision.hpp"
#include "../component/User.hpp"
#include "AI.hpp"

pacman::system::User::User(engine::ecs::World& world) : engine::system::AUser(world)
{
}

void pacman::system::User::init()
{
    auto& eventBus = getWorld().getUniverse().getEventBus();

    eventBus.subscribe(*this, &User::collisionHandler);
}

void pacman::system::User::update()
{
}

void pacman::system::User::render()
{
}

std::vector<bool> pacman::system::User::isCollide(const engine::component::Motion& motion)
{
    std::vector<bool> vec = {false, false, false, false};
    if (motion.velocity.x > 0) {
        vec[DIRECTION::RIGHT] = true;
    }
    if (motion.velocity.x < 0) {
        vec[DIRECTION::LEFT] = true;
    }
    if (motion.velocity.y > 0) {
        vec[DIRECTION::BOTTOM] = true;
    }
    if (motion.velocity.y < 0) {
        vec[DIRECTION::TOP] = true;
    }
    return vec;
}

void pacman::system::User::collisionHandler(engine::event::Collision &collision)
{
    std::srand(time(nullptr));
    int rand = 0;
    if (collision.entity1.hasComponents<pacman::component::User>() &&
        collision.entity2.getWorld().hasGroup(collision.entity2,"wall")) {
        auto& motion = collision.entity1.getComponent<engine::component::Motion>();
        auto& transform = collision.entity1.getComponent<engine::component::Transform>();
        auto vec = isCollide(motion);
        rand = std::rand() % DIRECTION::COUNT;
        while (vec[rand])
            rand = std::rand() % DIRECTION::COUNT;
        transform.position.x = 0;
        transform.position.y = 0;
    }
    if (collision.entity1.getWorld().hasGroup(collision.entity1,"wall") &&
        collision.entity2.hasComponents<pacman::component::User>()) {
        auto& motion = collision.entity2.getComponent<engine::component::Motion>();
        auto& transform = collision.entity2.getComponent<engine::component::Transform>();
        auto vec = isCollide(motion);
        rand = std::rand() % DIRECTION::COUNT;
        while (vec[rand])
            rand = std::rand() % DIRECTION::COUNT;
        transform.position.x = 0;
        transform.position.y = 0;
    }
}
