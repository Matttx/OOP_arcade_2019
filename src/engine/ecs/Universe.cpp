/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Universe.cpp
*/

#include "Universe.hpp"

engine::ecs::Universe::Universe() = default;

engine::ecs::Universe::~Universe()
{
    for (const auto& _world : _worlds)
        delete &_world.second.get();
}

void engine::ecs::Universe::init()
{
    if (this->_worlds.count(this->_current) == 0)
        throw std::exception(); // TODO: Custom Error class

    this->_worlds.at(this->_current).get().init();
}

void engine::ecs::Universe::update()
{
    if (this->_worlds.count(this->_current) == 0)
        throw std::exception(); // TODO: Custom Error class

    this->_worlds.at(this->_current).get().update();
}

void engine::ecs::Universe::render()
{
    if (this->_worlds.count(this->_current) == 0)
        throw std::exception(); // TODO: Custom Error class

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

engine::ecs::World& engine::ecs::Universe::getWorld(
    const std::string& name) const
{
    if (this->_worlds.count(name) == 0)
        throw std::exception(); // TODO: Custom Error class

    return this->_worlds.at(name).get();
}

engine::ecs::World& engine::ecs::Universe::getCurrentWorld() const
{
    if (this->_worlds.count(this->_current) == 0)
        throw std::exception(); // TODO: Custom Error class

    return this->_worlds.at(this->_current).get();
}

void engine::ecs::Universe::setCurrentWorld(const std::string& name)
{
    if (this->_worlds.count(name) == 0)
        throw std::exception(); // TODO: Custom Error class

    this->_current = name;
}

void engine::ecs::Universe::deleteWorld(const std::string& name)
{
    if (this->_worlds.count(name) == 0)
        throw std::exception(); // TODO: Custom Error class

    delete &this->_worlds.at(name).get();

    this->_worlds.erase(name);
}
