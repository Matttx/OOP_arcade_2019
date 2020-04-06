/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animations
*/

#include "Animations.hpp"

#include "../../../../engine/component/ARender.hpp"
#include "../../../../engine/component/Animations.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../../../../engine/system/AAnimations.hpp"
#include "../component/Render.hpp"

using namespace sdl;
using namespace system;

Animations::Animations(engine::ecs::World& world) : AAnimations(world)
{
}

void Animations::init()
{
    auto entities = this->getWorld().getEntities<engine::component::Animations>();

    for (const auto& entity : entities) {
        auto& animations = entity.get().getComponent<engine::component::Animations>();

        animations.lastTimeMs = 0;
    }
}

void Animations::update()
{
    unsigned int currentTimeMs = SDL_GetTicks();

    auto entities = getWorld().getEntities<engine::component::ARender, engine::component::Animations>();

    for (auto& entity : entities) {
        auto& animations = entity.get().getComponent<engine::component::Animations>();
        auto& render = entity.get().getComponent<engine::component::ARender>();
        auto& sdlRender = dynamic_cast<sdl::component::Render&>(render);
        auto& currentAnimation = animations.list.at(animations.currentAnimation);

        if (currentTimeMs > animations.lastTimeMs + (unsigned int)(currentAnimation.speed)) {
            int x = 0;
            int y = 0;

            SDL_QueryTexture(sdlRender.texture, nullptr, nullptr, &x, &y);

            sdlRender.srcRect.w = x / currentAnimation.frames;
            sdlRender.srcRect.h = y / (int)(animations.list.size());
            sdlRender.srcRect.x = animations.currentFrame * sdlRender.srcRect.w;
            sdlRender.srcRect.y = currentAnimation.row * sdlRender.srcRect.h;

            if (animations.currentFrame == currentAnimation.frames) {
                animations.currentFrame = 0;
                sdlRender.srcRect.x = 0;
            } else {
                animations.currentFrame += 1;
            }

            animations.lastTimeMs = currentTimeMs;
        }
    }
}

void Animations::render()
{
}