/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render
*/

#include "Render.hpp"

#include <algorithm>

#include "../../../../engine/component/AText.hpp"
#include "../../../../engine/component/Size.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../component/Render.hpp"
#include "../component/Text.hpp"

using namespace sdl;
using namespace system;

Render::Render(engine::ecs::World& world, SDL_Renderer& renderer) : ARender(world), _renderer(renderer)
{
}

void Render::init()
{
}

void Render::update()
{
    auto entitiesTrans = getWorld().getEntities<engine::component::Transform>();
    for (const auto& entity : entitiesTrans) {
        if (entity.get().hasComponents<engine::component::AText>()) {
            auto& component = entity.get().getComponent<engine::component::AText>();
            auto& transform = entity.get().getComponent<engine::component::Transform>();
            auto& sdlText = dynamic_cast<sdl::component::Text&>(component);
            sdlText.dstRect.x = transform.position.x;
            sdlText.dstRect.y = transform.position.y;
        }
        if (entity.get().hasComponents<engine::component::ARender>()) {
            auto& component = entity.get().getComponent<engine::component::ARender>();
            auto& transform = entity.get().getComponent<engine::component::Transform>();
            auto& sdlRender = dynamic_cast<sdl::component::Render&>(component);
            sdlRender.dstRect.x = transform.position.x;
            sdlRender.dstRect.y = transform.position.y;
        }
    }
    auto entitiesSize = getWorld().getEntities<engine::component::Size>();
    for (const auto& entity : entitiesSize) {
        if (entity.get().hasComponents<engine::component::AText>()) {
            auto& size = entity.get().getComponent<engine::component::Size>();
            auto& component = entity.get().getComponent<engine::component::AText>();
            auto& sdlText = dynamic_cast<sdl::component::Text&>(component);
            sdlText.dstRect.w = size.width;
            sdlText.dstRect.h = size.height;
        }
        if (entity.get().hasComponents<engine::component::ARender>()) {
            auto& size = entity.get().getComponent<engine::component::Size>();
            auto& component = entity.get().getComponent<engine::component::ARender>();
            auto& sdlRender = dynamic_cast<sdl::component::Render&>(component);
            sdlRender.dstRect.w = size.width;
            sdlRender.dstRect.h = size.height;
        }
    }
}

void Render::render()
{
    auto entities = getWorld().getEntities<engine::component::Transform>();
    std::sort(entities.begin(), entities.end(), [](const engine::ecs::Entity& lhs, const engine::ecs::Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer <
            rhs.getComponent<engine::component::Transform>().layer;
    });

    SDL_RenderClear(&_renderer);

    for (const auto& entity : entities) {
        if (entity.get().hasComponents<engine::component::ARender>()) {
            auto& component = entity.get().getComponent<engine::component::ARender>();
            auto& sdlRender = dynamic_cast<sdl::component::Render&>(component);
            SDL_RenderCopy(&_renderer, sdlRender.texture, &sdlRender.srcRect, &sdlRender.dstRect);
        }
        if (entity.get().hasComponents<engine::component::AText>()) {
            auto& component = entity.get().getComponent<engine::component::AText>();
            auto& sdlText = dynamic_cast<sdl::component::Text&>(component);
            SDL_RenderCopy(&_renderer, sdlText.texture, nullptr, &sdlText.dstRect);
        }
    }

    SDL_RenderPresent(&_renderer);
}