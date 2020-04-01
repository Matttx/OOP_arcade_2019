/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render
*/

#include "Render.hpp"

using namespace sdl;
using namespace system;

Render::Render(engine::ecs::World& world, SDL_Window& window) : ARender(world), _window(window)
{
}

void Render::init()
{
}

void Render::update()
{
    auto entities = getWorld().getEntities<engine::component::ARender, engine::component::Transform>();
    for (const auto& entity : entities) {
        auto& component = entity.get().getComponent<engine::component::ARender>();
        auto& transform = entity.get().getComponent<engine::component::Transform>();
        auto& sdlRender = dynamic_cast<sdl::component::Render&>(component);

        TODO : voir a quoi correspond le transform (si propre sfml ou non)

        sdlRender.sprite.setPosition(static_cast<float>(transform.position.x), static_cast<float>(transform.position.y));
    }
}

void Render::render()
{
    auto entities = getWorld().getEntities<engine::component::ARender, engine::component::Transform>();
    std::sort(entities.begin(), entities.end(), [](const engine::ecs::Entity& lhs, const engine::ecs::Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer < rhs.getComponent<engine::component::Transform>().layer;
    });
    for (const auto& entity : entities) {
        auto& component = entity.get().getComponent<sdl::component::Render>();
        auto& sdlRender = dynamic_cast<sdl::component::Render&>(component);
        _window.(sdlRender.sprite);
    }
}