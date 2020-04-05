/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI.cpp
*/

#include "AI.hpp"

#include <iostream>

#include "../../../../engine/component/AAI.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/ecs/Universe.hpp"
#include "../../../../engine/event/Collision.hpp"
#include "../component/AI.hpp"
#include "../component/User.hpp"

pacman::system::AI::AI(engine::ecs::World& world) : engine::system::AAI(world)
{
}

void pacman::system::AI::init()
{
    auto& eventBus = getWorld().getUniverse().getEventBus();
    auto& ghosts = getWorld().getGroup("ghost");
    for (const auto& ghost : ghosts) {
        auto& motion = ghost.get().getComponent<engine::component::Motion>();
        motion.velocity.x = NEXT_DIRECTION.at(TOP).first;
        motion.velocity.y = NEXT_DIRECTION.at(TOP).second;
    }

    eventBus.subscribe(*this, &AI::collisionHandler);
}

void pacman::system::AI::update()
{
    static clock_t t = clock();
    std::cout << t << std::endl;
    auto entities = getWorld().getEntities<pacman::component::AI>();
    for (const auto& entity : entities) {
        auto& motion = entity.get().getComponent<engine::component::Motion>();
        auto& transform = entity.get().getComponent<engine::component::Transform>();
        if (!entity.get().getComponent<pacman::component::AI>().isAlive) {
            auto tmp = clock() - t;
            std::cout << "Condition + " << tmp << std::endl;
            transform.position.x = entity.get().getComponent<pacman::component::AI>().startPosX;
            transform.position.y = entity.get().getComponent<pacman::component::AI>().startPosY;
            motion.velocity.x = 0;
            motion.velocity.y = 0;
            if ((((float)tmp) / CLOCKS_PER_SEC) >= 10) {
                entity.get().getComponent<pacman::component::AI>().isAlive = true;
                motion.velocity.x = NEXT_DIRECTION.at(TOP).first;
                motion.velocity.y = NEXT_DIRECTION.at(TOP).second;
            }
        }
        if (!entity.get().getComponent<pacman::component::AI>().scared) {
            auto tmp = clock() - t;
            if ((((float)tmp) / CLOCKS_PER_SEC) >= 10) {
                entity.get().getComponent<pacman::component::AI>().scared = false;
            }
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
        auto vec = isCollide(motion);
        rand = std::rand() % DIRECTION::COUNT;
        while (vec[rand])
            rand = std::rand() % DIRECTION::COUNT;
        motion.velocity.x = NEXT_DIRECTION.at(rand).first;
        motion.velocity.y = NEXT_DIRECTION.at(rand).second;
    }
    if (collision.entity1.getWorld().hasGroup(collision.entity1,"wall") &&
        collision.entity2.hasComponents<pacman::component::AI>()) {
        auto& motion = collision.entity2.getComponent<engine::component::Motion>();
        auto vec = isCollide(motion);
        rand = std::rand() % DIRECTION::COUNT;
        while (vec[rand])
            rand = std::rand() % DIRECTION::COUNT;
        motion.velocity.x = NEXT_DIRECTION.at(rand).first;
        motion.velocity.y = NEXT_DIRECTION.at(rand).second;
    }
    if (collision.entity1.hasComponents<pacman::component::AI>() &&
        collision.entity2.hasComponents<pacman::component::User>()) {
        auto& ghost = collision.entity2;
        if (ghost.getComponent<pacman::component::AI>().scared) {
            ghost.getComponent<pacman::component::AI>().isAlive = false;

        }
    }
    if (collision.entity1.hasComponents<pacman::component::User>() &&
        collision.entity2.hasComponents<pacman::component::AI>()) {
        auto& ghost = collision.entity1;
        if (ghost.getComponent<pacman::component::AI>().scared) {
            ghost.getComponent<pacman::component::AI>().isAlive = false;
        }
    }
    if (collision.entity1.hasComponents<pacman::component::User>() &&
        collision.entity2.getWorld().hasGroup(collision.entity2, "specialPacGums")) {
        auto& ghosts = getWorld().getGroup("ghost");
        for (const auto& ghost : ghosts) {
            ghost.get().getComponent<pacman::component::AI>().scared = true;
        }
    }
    if (collision.entity1.getWorld().hasGroup(collision.entity1, "specialPacGums") &&
        collision.entity2.hasComponents<pacman::component::User>()) {
        auto& ghosts = getWorld().getGroup("ghost");
        for (const auto& ghost : ghosts) {
            ghost.get().getComponent<pacman::component::AI>().scared = true;
        }
    }
}