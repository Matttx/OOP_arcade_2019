/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.cpp
*/

#include "User.hpp"

#include <ctime>

#include "../../../../engine/component/Hitbox.hpp"
#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/event/Collision.hpp"
#include "../component/AI.hpp"
#include "../component/User.hpp"

pacman::system::User::User(engine::ecs::World& world) : engine::system::AUser(world)
{
}

void pacman::system::User::init()
{
    auto& eventBus = getWorld().getUniverse().getEventBus();

    eventBus.subscribe(*this, &User::collisionHandler);
    eventBus.subscribe(*this, &User::inputHandler);
}

void pacman::system::User::update()
{
    static clock_t t = clock();
    auto entities = getWorld().getEntities<pacman::component::User>();
    for (const auto& entity : entities) {
        if (entity.get().getComponent<pacman::component::User>().supaSayajin) {
            auto tmp = clock() - t;
            if ((((float)tmp) / CLOCKS_PER_SEC) >= 10) {
                entity.get().getComponent<pacman::component::User>().supaSayajin = false;
            }
        }
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
    if (collision.entity1.hasComponents<pacman::component::User>() &&
        collision.entity2.getWorld().hasGroup(collision.entity2,"wall")) {
        auto& motion = collision.entity1.getComponent<engine::component::Motion>();
        motion.velocity.x = 0;
        motion.velocity.y = 0;
    }
    if (collision.entity1.getWorld().hasGroup(collision.entity1,"wall") &&
        collision.entity2.hasComponents<pacman::component::User>()) {
        auto& motion = collision.entity2.getComponent<engine::component::Motion>();
        motion.velocity.x = 0;
        motion.velocity.y = 0;
    }
    if (collision.entity1.hasComponents<pacman::component::User>() &&
        collision.entity2.hasComponents<pacman::component::AI>()) {
        auto& pacman = collision.entity1;
        if (!pacman.getComponent<pacman::component::User>().supaSayajin) {
            //loose
        }
    }
    if (collision.entity1.hasComponents<pacman::component::AI>() &&
        collision.entity2.hasComponents<pacman::component::User>()) {
        auto& pacman = collision.entity2;
        if (!pacman.getComponent<pacman::component::User>().supaSayajin) {
            //loose
        }
    }
    if (collision.entity1.hasComponents<pacman::component::User>() &&
        collision.entity2.getWorld().hasGroup(collision.entity2, "pacGums")) {
        auto& pacGums = collision.entity2.getWorld().getGroup("pacGums");
        for (const auto& pacGum : pacGums) {
            auto& motionPG = pacGum.get().getComponent<engine::component::Transform>();
            auto& hitboxPG = pacGum.get().getComponent<engine::component::Hitbox>();
            auto& motionPM = collision.entity1.getComponent<engine::component::Transform>();
            auto& hitboxPM = collision.entity1.getComponent<engine::component::Hitbox>();
            if (isCollide(motionPM, hitboxPM, motionPG, hitboxPG)) {
                getWorld().deleteEntity(pacGum);
                collision.entity1.getComponent<pacman::component::User>().eat++;
            }
        }
    }
    if (collision.entity1.getWorld().hasGroup(collision.entity1, "pacGums") &&
        collision.entity2.hasComponents<pacman::component::User>()) {
        auto& pacGums = collision.entity1.getWorld().getGroup("pacGums");
        for (const auto& pacGum : pacGums) {
            auto& motionPG = pacGum.get().getComponent<engine::component::Transform>();
            auto& hitboxPG = pacGum.get().getComponent<engine::component::Hitbox>();
            auto& motionPM = collision.entity2.getComponent<engine::component::Transform>();
            auto& hitboxPM = collision.entity2.getComponent<engine::component::Hitbox>();
            if (isCollide(motionPM, hitboxPM, motionPG, hitboxPG)) {
                getWorld().deleteEntity(pacGum);
                collision.entity2.getComponent<pacman::component::User>().eat++;
            }
        }
    }
    if (collision.entity1.hasComponents<pacman::component::User>() &&
        collision.entity2.getWorld().hasGroup(collision.entity2, "specialPacGums")) {
        auto& specialPacGums = collision.entity2.getWorld().getGroup("specialPacGums");
        for (const auto& specialPacGum : specialPacGums) {
            auto& motionPG = specialPacGum.get().getComponent<engine::component::Transform>();
            auto& hitboxPG = specialPacGum.get().getComponent<engine::component::Hitbox>();
            auto& motionPM = collision.entity1.getComponent<engine::component::Transform>();
            auto& hitboxPM = collision.entity1.getComponent<engine::component::Hitbox>();
            if (isCollide(motionPM, hitboxPM, motionPG, hitboxPG)) {
                getWorld().deleteEntity(specialPacGum);
                collision.entity1.getComponent<pacman::component::User>().eat++;
                collision.entity1.getComponent<pacman::component::User>().supaSayajin = true;
            }
        }
    }
    if (collision.entity1.getWorld().hasGroup(collision.entity1, "specialPacGums") &&
        collision.entity2.hasComponents<pacman::component::User>()) {
        auto& specialPacGums = collision.entity1.getWorld().getGroup("specialPacGums");
        for (const auto& specialPacGum : specialPacGums) {
            auto& motionPG = specialPacGum.get().getComponent<engine::component::Transform>();
            auto& hitboxPG = specialPacGum.get().getComponent<engine::component::Hitbox>();
            auto& motionPM = collision.entity2.getComponent<engine::component::Transform>();
            auto& hitboxPM = collision.entity2.getComponent<engine::component::Hitbox>();
            if (isCollide(motionPM, hitboxPM, motionPG, hitboxPG)) {
                getWorld().deleteEntity(specialPacGum);
                collision.entity2.getComponent<pacman::component::User>().eat++;
                collision.entity2.getComponent<pacman::component::User>().supaSayajin = true;
            }
        }
    }
}

bool pacman::system::User::isCollide(
    const engine::component::Transform& transform1,
    const engine::component::Hitbox& hitbox1,
    const engine::component::Transform& transform2,
    const engine::component::Hitbox& hitbox2)
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
