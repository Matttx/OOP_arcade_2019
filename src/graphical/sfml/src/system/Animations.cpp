/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animations.cpp
*/

#include "Animations.hpp"

#include "../../../../engine/component/ARender.hpp"
#include "../../../../engine/component/Animations.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../../../../engine/system/AAnimations.hpp"
#include "../component/Render.hpp"
sfml::system::Animations::Animations(engine::ecs::World& world)
    : engine::system::AAnimations(world)
{
}

void sfml::system::Animations::init()
{
    auto entities =
        this->getWorld().getEntities<engine::component::Animations>();

    for (const auto& entity : entities) {
        auto& animations =
            entity.get().getComponent<engine::component::Animations>();

        animations.lastTimeMs = 0;
    }
}

void sfml::system::Animations::update()
{
    unsigned int currentTimeMs = _clock.getElapsedTime().asMilliseconds();

    auto entities = getWorld()
                        .getEntities<engine::component::ARender,
                            engine::component::Animations>();

    for (auto& entity : entities) {
        auto& animations =
            entity.get().getComponent<engine::component::Animations>();
        auto& render = entity.get().getComponent<engine::component::ARender>();
        auto& sfmlRender = dynamic_cast<sfml::component::Render&>(render);
        auto& currentAnimation =
            animations.list.at(animations.currentAnimation);

        if (currentTimeMs >
            animations.lastTimeMs + (unsigned int)(currentAnimation.speed)) {
            sfmlRender.srcRect.width =
                sfmlRender.texture.getSize().x / currentAnimation.frames;
            sfmlRender.srcRect.height =
                sfmlRender.texture.getSize().y / (int)(animations.list.size());
            sfmlRender.srcRect.left =
                animations.currentFrame * sfmlRender.srcRect.width;
            sfmlRender.srcRect.top =
                currentAnimation.row * sfmlRender.srcRect.height;

            if (animations.currentFrame == currentAnimation.frames) {
                animations.currentFrame = 0;
                sfmlRender.srcRect.left = 0;
            } else {
                animations.currentFrame += 1;
            }

            animations.lastTimeMs = currentTimeMs;
        }

        sfmlRender.sprite.setTextureRect(sfmlRender.srcRect);
    }
}

void sfml::system::Animations::render()
{
}
