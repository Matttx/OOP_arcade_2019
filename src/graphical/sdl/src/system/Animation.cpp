/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animation
*/

#include "Animation.hpp"

#include "../../../../engine/component/ARender.hpp"
#include "../../../../engine/system/AAnimations.hpp"
#include "../../../../engine/component/Animations.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../component/Render.hpp"

using namespace sdl;
using namespace system;

Animation::Animation(engine::ecs::World& world) : AAnimations(world)
{
}

void Animation::init()
{
}

void Animation::update()
{
    auto entities = getWorld().getEntities<engine::component::ARender, engine::component::Animations>();

    for (auto& entity : entities) {
        auto& compAnimation = entity.get().getComponent<engine::component::Animations>();
        auto& compSprite = entity.get().getComponent<engine::component::ARender>();
        auto& sdlRender = dynamic_cast<sdl::component::Render&>(compSprite);
        auto& currentAnimation = compAnimation.list.at(compAnimation.currentAnimation);
        SDL_QueryTexture(sdlRender.texture, NULL, NULL, &sdlRender.srcRect->w, &sdlRender.srcRect->h);
        int y = sdlRender.srcRect->w;
        sdlRender.srcRect->y = currentAnimation.row * (y / compAnimation.list.size());
        if (compAnimation.currentFrame == currentAnimation.frames) {
            compAnimation.currentFrame = 0;
            sdlRender.srcRect->x = 0;
        } else {
            sdlRender.srcRect->x += sdlRender.srcRect->w;
            compAnimation.currentFrame += 1;
        }
    }
}

void Animation::render()
{
}