/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render.cpp
*/

#include "Render.hpp"

#include "../../../../engine/component/Size.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../component/Render.hpp"
#include "../component/Text.hpp"

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
    auto entitiesTrans = getWorld()
                        .getEntities<engine::component::Transform>();
    for (const auto& entity : entitiesTrans) {
        if (entity.get().hasComponents<engine::component::AText>()) {
            auto& component =
                entity.get().getComponent<engine::component::AText>();
            auto& transform =
                entity.get().getComponent<engine::component::Transform>();
            auto& sfmlText =
                dynamic_cast<sfml::component::Text&>(component);
            sfmlText.text.setPosition(
                static_cast<float>(transform.position.x),
                static_cast<float>(transform.position.y));
        }
        if (entity.get().hasComponents<engine::component::ARender>()) {
            auto& component =
                entity.get().getComponent<engine::component::ARender>();
            auto& transform =
                entity.get().getComponent<engine::component::Transform>();
            auto& sfmlRender =
                dynamic_cast<sfml::component::Render&>(component);
            sfmlRender.sprite.setPosition(
                static_cast<float>(transform.position.x),
                static_cast<float>(transform.position.y));
        }
    }
    auto entitiesSize = getWorld()
        .getEntities<engine::component::Size>();
    for (const auto& entity : entitiesSize) {
        if (entity.get().hasComponents<engine::component::AText>()) {
            auto& size = entity.get().getComponent<engine::component::Size>();
            auto& component =
                entity.get().getComponent<engine::component::AText>();
            auto& sfmlText =
                dynamic_cast<sfml::component::Text&>(component);
            sfmlText.text.setScale(
                size.width / sfmlText.text.getGlobalBounds().width,
                size.height / sfmlText.text.getGlobalBounds().height);
        }
        if (entity.get().hasComponents<engine::component::ARender>()) {
            auto& size = entity.get().getComponent<engine::component::Size>();
            auto& component =
                entity.get().getComponent<engine::component::ARender>();
            auto& sfmlRender =
                dynamic_cast<sfml::component::Render&>(component);
            sfmlRender.destRect.width = size.width;
            sfmlRender.destRect.height = size.height;
            sfmlRender.sprite.setScale(
                sfmlRender.destRect.width / sfmlRender.srcRect.width,
                sfmlRender.destRect.height / sfmlRender.srcRect.height);
        }
    }
}

void sfml::system::Render::render()
{
    auto entities = getWorld().getEntities<engine::component::Transform>();
    std::sort(entities.begin(), entities.end(), [](const engine::ecs::Entity& lhs, const engine::ecs::Entity& rhs) {
        return lhs.getComponent<engine::component::Transform>().layer < rhs.getComponent<engine::component::Transform>().layer;
    });

    _window.clear();

    for (const auto& entity : entities) {
        if (entity.get().hasComponents<engine::component::AText>()) {

        }
        if (entity.get().hasComponents<engine::component::ARender>()) {
            auto& component =
                entity.get().getComponent<engine::component::ARender>();
            auto& sfmlRender =
                dynamic_cast<sfml::component::Render&>(component);
            _window.draw(sfmlRender.sprite);
        }
    }

    _window.display();
}