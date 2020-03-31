/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render.cpp
*/

#include "Render.hpp"

#include "../../../../engine/component/Transform.hpp"

#include "../component/Render.hpp"

sfml::system::Render::Render(
    engine::ecs::World& world, sf::RenderWindow& window)
    : ARender(world), _window(window)
{
}

void sfml::system::Render::init()
{
}

void sfml::system::Render::update()
{
    auto entities = getWorld()
                        .getEntities<engine::component::ARender,
                            engine::component::Transform>();
    for (const auto& entity : entities) {
        auto& component =
            entity.get().getComponent<engine::component::ARender>();
        auto& transform =
            entity.get().getComponent<engine::component::Transform>();
        auto& sfmlRender = dynamic_cast<sfml::component::Render&>(component);
        sfmlRender.sprite.setPosition(static_cast<float>(transform.position.x),
            static_cast<float>(transform.position.y));
    }
}

void sfml::system::Render::render()
{
    auto entities = getWorld().getEntities<engine::component::ARender>();
    for (const auto& entity : entities) {
        auto& component = entity.get().getComponent<sfml::component::Render>();
        auto& sfmlRender = dynamic_cast<sfml::component::Render&>(component);
        _window.draw(sfmlRender.sprite);
    }
}