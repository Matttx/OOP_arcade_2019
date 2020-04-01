/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animation.cpp
*/

#include "Animations.hpp"

#include "../../../../engine/component/ARender.hpp"
#include "../../../../engine/system/AAnimations.hpp"
#include "../../../../engine/component/Animations.hpp"

#include "../component/Render.hpp"
sfml::system::Animations::Animations(engine::ecs::World& world)
    : engine::system::AAnimations(world)
{
}

void sfml::system::Animations::init()
{
}

void sfml::system::Animations::update()
{
    auto entities =
        getWorld()
            .getEntities<engine::component::ARender,
                engine::component::Animations>();
    for (auto& entity : entities) {
        auto& compAnimation =
            entity.get().getComponent<engine::component::Animations>();
        auto& compSprite =
            entity.get().getComponent<engine::component::ARender>();
        auto& sfmlRender = dynamic_cast<sfml::component::Render&>(compSprite);
        auto& currentAnimation =
            compAnimation.list.at(compAnimation.currentAnimation);
        sfmlRender.srcRect.top = currentAnimation.row * (sfmlRender.texture.getSize().y / compAnimation.list.size());
        if (compAnimation.currentFrame == currentAnimation.frames) {
            compAnimation.currentFrame = 0;
            sfmlRender.srcRect.left = 0;
        } else {
            sfmlRender.srcRect.left += sfmlRender.srcRect.width;
            compAnimation.currentFrame += 1;
        }
    }
}

void sfml::system::Animations::render()
{
}
