/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** World.cpp
*/

#include "World.hpp"

#include <algorithm>

engine::ecs::World::World(engine::ecs::Universe& universe) : _universe(universe)
{
}

engine::ecs::World::~World()
{
    for (const auto& _entity : _entities)
        delete &_entity.get();
    for (const auto& _system : _systems)
        delete &_system.second.get();
}

engine::ecs::Universe& engine::ecs::World::getUniverse() const
{
    return this->_universe;
}

void engine::ecs::World::init()
{
    for (const auto& _system : _systems)
        _system.second.get().init();
}

void engine::ecs::World::update()
{
    for (const auto& _system : _systems)
        _system.second.get().update();
}

void engine::ecs::World::render()
{
    for (const auto& _system : _systems)
        _system.second.get().render();
}

engine::ecs::Entity& engine::ecs::World::createEntity()
{
    auto* entity = new Entity(*this);

    this->_entities.emplace_back(*entity);

    return this->_entities.back().get();
}

void engine::ecs::World::deleteEntity(engine::ecs::Entity& entity)
{
    auto it = std::find_if(this->_entities.begin(), this->_entities.end(),
        [entity](const auto& wrapper) {
            return (&wrapper.get() == &entity);
        });

    if (it == this->_entities.end())
        throw std::exception(); // TODO: Custom Error class

    for (const auto& _group : _groups)
        if (this->hasGroup(it->get(), _group.first))
            this->removeFromGroup(it->get(), _group.first);

    delete &it->get();

    this->_entities.erase(it);
}

void engine::ecs::World::addToGroup(
    engine::ecs::Entity& entity, const std::string& name)
{
    if (this->_groups.count(name) == 0)
        throw std::exception(); // TODO: Custom Error class

    if (this->hasGroup(entity, name))
        throw std::exception(); // TODO: Custom Error class

    this->_groups.at(name).emplace_back(entity);
}

bool engine::ecs::World::hasGroup(
    engine::ecs::Entity& entity, const std::string& name) const
{
    if (this->_groups.count(name) == 0)
        throw std::exception(); // TODO: Custom Error class

    auto it = std::find_if(this->_groups.at(name).begin(),
        this->_groups.at(name).end(), [entity](const auto& wrapper) {
            return (&wrapper.get() == &entity);
        });

    return (it != this->_groups.at(name).end());
}

std::vector<std::reference_wrapper<engine::ecs::Entity>>&
    engine::ecs::World::getGroup(const std::string& name) const
{
    if (this->_groups.count(name) == 0)
        throw std::exception(); // TODO: Custom Error class

    return const_cast<
        std::vector<std::reference_wrapper<engine::ecs::Entity>>&>(
        this->_groups.at(name));
}

void engine::ecs::World::removeFromGroup(
    engine::ecs::Entity& entity, const std::string& name)
{
    if (this->_groups.count(name) == 0)
        throw std::exception(); // TODO: Custom Error class

    if (!this->hasGroup(entity, name))
        throw std::exception(); // TODO: Custom Error class

    auto it = std::find_if(this->_groups.at(name).begin(),
        this->_groups.at(name).end(), [entity](const auto& wrapper) {
            return (&wrapper.get() == &entity);
        });

    this->_groups.at(name).erase(it);
}
