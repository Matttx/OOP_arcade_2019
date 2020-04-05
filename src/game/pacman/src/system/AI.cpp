/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI.cpp
*/

#include "AI.hpp"

#include "../../../../engine/component/AAI.hpp"
#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/ecs/Universe.hpp"
#include "../../../../engine/event/Collision.hpp"
#include "../component/AI.hpp"

pacman::system::AI::AI(engine::ecs::World& world) : engine::system::AAI(world)
{
}

void pacman::system::AI::init()
{
    auto& eventBus = getWorld().getUniverse().getEventBus();

    eventBus.subscribe(*this, &AI::collisionHandler);
}

void pacman::system::AI::update()
{
    auto entities = getWorld().getEntities<pacman::component::AI>();
    for (const auto& entity : entities) {
        auto& motion = entity.get().getComponent<engine::component::Motion>();
        auto& transform = entity.get().getComponent<engine::component::Transform>();
        if (motion.velocity.x > 0) {
            transform.position.x += NEXT_DIRECTION.at(RIGHT).first;
            transform.position.y += NEXT_DIRECTION.at(RIGHT).second;
        }
        if (motion.velocity.x < 0) {
            transform.position.x += NEXT_DIRECTION.at(LEFT).first;
            transform.position.y += NEXT_DIRECTION.at(LEFT).second;
        }
        if (motion.velocity.y > 0) {
            transform.position.x += NEXT_DIRECTION.at(BOTTOM).first;
            transform.position.y += NEXT_DIRECTION.at(BOTTOM).second;
        }
        if (motion.velocity.y < 0) {
            transform.position.x += NEXT_DIRECTION.at(TOP).first;
            transform.position.y += NEXT_DIRECTION.at(TOP).second;
        }
        if (motion.velocity.x == 0 && motion.velocity.y == 0) {
            transform.position.x += NEXT_DIRECTION.at(TOP).first;
            transform.position.y += NEXT_DIRECTION.at(TOP).second;
        }
    }
}

void pacman::system::AI::render()
{
}

std::vector<bool> pacman::system::AI::isCollide(const engine::component::Motion& motion)
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

void pacman::system::AI::collisionHandler(engine::event::Collision &collision)
{
    std::srand(time(nullptr));
    int rand = 0;
    if (collision.entity1.hasComponents<pacman::component::AI>() &&
        collision.entity2.getWorld().hasGroup(collision.entity2,"wall")) {
        auto& motion = collision.entity1.getComponent<engine::component::Motion>();
        auto& transform = collision.entity1.getComponent<engine::component::Transform>();
        auto vec = isCollide(motion);
        rand = std::rand() % DIRECTION::COUNT;
        while (vec[rand])
            rand = std::rand() % DIRECTION::COUNT;
        transform.position.x = NEXT_DIRECTION.at(rand).first;
        transform.position.y = NEXT_DIRECTION.at(rand).second;
    }
    if (collision.entity1.getWorld().hasGroup(collision.entity1,"wall") &&
        collision.entity2.hasComponents<pacman::component::AI>()) {
        auto& motion = collision.entity2.getComponent<engine::component::Motion>();
        auto& transform = collision.entity2.getComponent<engine::component::Transform>();
        auto vec = isCollide(motion);
        rand = std::rand() % DIRECTION::COUNT;
        while (vec[rand])
            rand = std::rand() % DIRECTION::COUNT;
        transform.position.x = NEXT_DIRECTION.at(rand).first;
        transform.position.y = NEXT_DIRECTION.at(rand).second;
    }
}