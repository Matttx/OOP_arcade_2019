/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

#include "../core/Core.hpp"

engine::ecs::Entity::Entity(engine::ecs::World& world) : _world(world)
{
}

engine::ecs::Entity::~Entity()
{
    for (const auto& _component : _components)
        delete &_component.second.get();
};

engine::ecs::World& engine::ecs::Entity::getWorld() const
{
    return this->_world;
}

template<>
engine::component::AAudio&
    engine::ecs::Entity::addComponent<engine::component::AAudio>(
        const std::vector<std::string>& paths)
{
    std::type_index id = typeid(component::AAudio);

    if (this->_components.count(id))
        throw util::Error("engine::ecs::Entity::addComponent()",
            "Already has this type of component");

    auto& graphical =
        this->getWorld().getUniverse().getCore().getCurrentGraphical();
    auto& component = graphical.createAudio(*this, paths);

    this->_components.emplace(id, component);

    return component;
}

template<>
engine::component::ARender&
    engine::ecs::Entity::addComponent<engine::component::ARender>(
        const std::vector<std::string>& paths)
{
    std::type_index id = typeid(component::ARender);

    if (this->_components.count(id))
        throw util::Error("engine::ecs::Entity::addComponent()",
            "Already has this type of component");

    auto& graphical =
        this->getWorld().getUniverse().getCore().getCurrentGraphical();
    auto& component = graphical.createRender(*this, paths);

    this->_components.emplace(id, component);

    return component;
}

template<>
engine::component::AText&
    engine::ecs::Entity::addComponent<engine::component::AText>(
        const std::string& text, const std::vector<std::string>& paths)
{
    std::type_index id = typeid(component::AText);

    if (this->_components.count(id))
        throw util::Error("engine::ecs::Entity::addComponent()",
            "Already has this type of component");

    auto& graphical =
        this->getWorld().getUniverse().getCore().getCurrentGraphical();
    auto& component = graphical.createText(*this, text, paths);

    this->_components.emplace(id, component);

    return component;
}
