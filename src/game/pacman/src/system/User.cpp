/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.cpp
*/

#include "User.hpp"

#include <ctime>

#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/event/Collision.hpp"
#include "../component/AI.hpp"
#include "../component/User.hpp"
#include "../../../../engine/core/Core.hpp"

pacman::system::User::User(engine::ecs::World& world) : engine::system::AUser(world)
{
}

void pacman::system::User::init()
{
    auto& eventBus = getWorld().getUniverse().getEventBus();

    eventBus.subscribe(*this, &User::inputHandler);
    eventBus.subscribe(*this, &User::collisionHandler);
}

void pacman::system::User::update()
{
    static clock_t t = clock();
    static int count = 1;
    auto entities = getWorld().getEntities<pacman::component::User>();
    for (const auto& entity : entities) {
        if (entity.get().getComponent<pacman::component::User>().supaSayajin) {
            auto tmp = clock() - t;
            if ((((float)tmp) / CLOCKS_PER_SEC) >= 10 * count) {
                entity.get().getComponent<pacman::component::User>().supaSayajin = false;
                auto& ghosts = getWorld().getGroup("ghost");
                for (const auto& ghost : ghosts) {
                    ghost.get().getComponent<pacman::component::AI>().scared = false;
                }
                count++;
            }
        }
    }
    int remaining = 0;
    auto pacGums = getWorld().getGroup("pacGums");
    auto specialPacGums = getWorld().getGroup("specialPacGums");
    for (const auto& pacGum : pacGums)
        if (pacGum.get().hasComponents<engine::component::ARender>())
            remaining++;
    for (const auto& specialPacGum : specialPacGums)
        if (specialPacGum.get().hasComponents<engine::component::ARender>())
            remaining++;
    if (remaining == 0) {
        getWorld().getUniverse().getCore().setCurrentGame("emulator");
    }
}

void pacman::system::User::render()
{
}

void pacman::system::User::inputHandler(engine::event::Input& input)
{
    auto entities = getWorld().getEntities<pacman::component::User>();
    for (const auto& entity : entities) {
        auto& motion = entity.get().getComponent<engine::component::Motion>();
        if (input.code == engine::event::Input::KEY_LEFT) {
            motion.velocity.x = NEXT_DIRECTION.at(LEFT).first;
            motion.velocity.y = NEXT_DIRECTION.at(LEFT).second;
        }
        if (input.code == engine::event::Input::KEY_RIGHT) {
            motion.velocity.x = NEXT_DIRECTION.at(RIGHT).first;
            motion.velocity.y = NEXT_DIRECTION.at(RIGHT).second;
        }
        if (input.code == engine::event::Input::KEY_UP) {
            motion.velocity.x = NEXT_DIRECTION.at(TOP).first;
            motion.velocity.y = NEXT_DIRECTION.at(TOP).second;
        }
        if (input.code == engine::event::Input::KEY_DOWN) {
            motion.velocity.x = NEXT_DIRECTION.at(BOTTOM).first;
            motion.velocity.y = NEXT_DIRECTION.at(BOTTOM).second;
        }
    }
}

void pacman::system::User::collisionHandler(engine::event::Collision &collision)
{
    if (collision.entity1.hasComponents<pacman::component::User>() &&
        collision.entity2.hasComponents<pacman::component::AI>()) {
        auto& pacman = collision.entity1;
        if (!pacman.getComponent<pacman::component::User>().supaSayajin) {
            getWorld().getUniverse().getCore().setCurrentGame("emulator");
        }
    }
    if (collision.entity1.hasComponents<pacman::component::AI>() &&
        collision.entity2.hasComponents<pacman::component::User>()) {
        auto& pacman = collision.entity2;
        if (!pacman.getComponent<pacman::component::User>().supaSayajin) {
            getWorld().getUniverse().getCore().setCurrentGame("emulator");
        }
    }
    if (collision.entity1.hasComponents<pacman::component::User>() &&
        collision.entity2.getWorld().hasGroup(collision.entity2, "pacGums")) {
        if (collision.entity2.hasComponents<engine::component::ARender>()) {
            collision.entity2.removeComponent<engine::component::ARender>();
            collision.entity1.getComponent<pacman::component::User>().eat++;
        }
    }
    if (collision.entity1.getWorld().hasGroup(collision.entity1, "pacGums") &&
        collision.entity2.hasComponents<pacman::component::User>()) {
        if (collision.entity1.hasComponents<engine::component::ARender>()) {
            collision.entity1.removeComponent<engine::component::ARender>();
            collision.entity2.getComponent<pacman::component::User>().eat++;
        }
    }
    if (collision.entity1.getWorld().hasGroup(collision.entity1, "specialPacGums") &&
        collision.entity2.hasComponents<pacman::component::User>()) {
        if (collision.entity1.hasComponents<engine::component::ARender>()) {
            collision.entity1.removeComponent<engine::component::ARender>();
            collision.entity2.getComponent<pacman::component::User>().eat++;
            collision.entity2.getComponent<pacman::component::User>().supaSayajin = true;
        }
    }
    if (collision.entity1.hasComponents<pacman::component::User>() &&
        collision.entity2.getWorld().hasGroup(collision.entity2, "specialPacGums")) {
        if (collision.entity2.hasComponents<engine::component::ARender>()) {
            collision.entity2.removeComponent<engine::component::ARender>();
            collision.entity1.getComponent<pacman::component::User>().eat++;
            collision.entity1.getComponent<pacman::component::User>().supaSayajin = true;
        }
    }
}