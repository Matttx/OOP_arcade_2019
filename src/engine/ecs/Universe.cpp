/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Universe.cpp
*/

#include "Universe.hpp"

engine::ecs::Universe::Universe(core::Core& core) : _core(core)
{
}

engine::ecs::Universe::~Universe()
{
    for (const auto& _world : _worlds)
        delete &_world.second.get();
}

engine::core::Core& engine::ecs::Universe::getCore() const
{
    return this->_core;
}

engine::eventbus::EventBus& engine::ecs::Universe::getEventBus() const
{
    return const_cast<eventbus::EventBus&>(this->_eventBus);
}

void engine::ecs::Universe::init()
{
    if (this->_worlds.count(this->_current) == 0)
        throw util::Error("engine::ecs::Universe::init()",
            "The world '" + this->_current + "' doesn't exist");

    this->_worlds.at(this->_current).get().init();
}

void engine::ecs::Universe::update()
{
    if (this->_worlds.count(this->_current) == 0)
        throw util::Error("engine::ecs::Universe::update()",
            "The world '" + this->_current + "' doesn't exist");

    this->_worlds.at(this->_current).get().update();
}

void engine::ecs::Universe::render()
{
    if (this->_worlds.count(this->_current) == 0)
        throw util::Error("engine::ecs::Universe::render()",
            "The world '" + this->_current + "' doesn't exist");

    this->_worlds.at(this->_current).get().render();
}

engine::ecs::World& engine::ecs::Universe::createWorld(const std::string& name)
{
    auto* entity = new World(*this);

    this->_worlds.emplace(name, *entity);

    return this->_worlds.at(name).get();
}

bool engine::ecs::Universe::hasWorld(const std::string& name) const
{
    return this->_worlds.count(name);
}

bool engine::ecs::Universe::hasCurrentWorld() const
{
    return this->_worlds.count(this->_current);
}

engine::ecs::World& engine::ecs::Universe::getWorld(
    const std::string& name) const
{
    if (this->_worlds.count(name) == 0)
        throw util::Error("engine::ecs::Universe::getWorld()",
            "The world '" + this->_current + "' doesn't exist");

    return this->_worlds.at(name).get();
}

engine::ecs::World& engine::ecs::Universe::getCurrentWorld() const
{
    if (this->_worlds.count(this->_current) == 0)
        throw util::Error("engine::ecs::Universe::getCurrentWorld()",
            "The world '" + this->_current + "' doesn't exist");

    return this->_worlds.at(this->_current).get();
}

std::vector<std::string> engine::ecs::Universe::getWorldNames() const
{
    std::vector<std::string> names {};

    for (const auto& _world : _worlds)
        names.push_back(_world.first);

    return names;
}

void engine::ecs::Universe::setCurrentWorld(const std::string& name)
{
    if (this->_worlds.count(name) == 0)
        throw util::Error("engine::ecs::Universe::setCurrentWorld()",
            "The world '" + this->_current + "' doesn't exist");

    this->_current = name;
}

void engine::ecs::Universe::deleteWorld(const std::string& name)
{
    if (this->_worlds.count(name) == 0)
        throw util::Error("engine::ecs::Universe::deleteWorld()",
            "The world '" + this->_current + "' doesn't exist");

    delete &this->_worlds.at(name).get();

    this->_worlds.erase(name);
}
