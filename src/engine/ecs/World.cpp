/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** World.cpp
*/

#include "World.hpp"

#include <algorithm>

#include "../core/Core.hpp"

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
    auto it = std::find_if(this->_entities.begin(), this->_entities.end(), [&entity](const auto& wrapper) {
        return (&wrapper.get() == &entity);
    });

    if (it == this->_entities.end())
        throw util::Error("engine::ecs::World::deleteEntity()", "The entity doesn't exist");

    for (const auto& _group : _groups)
        if (this->hasGroup(it->get(), _group.first))
            this->removeFromGroup(it->get(), _group.first);

    delete &it->get();

    this->_entities.erase(it);
}

void engine::ecs::World::addToGroup(engine::ecs::Entity& entity, const std::string& name)
{
    if (this->_groups.count(name) == 0)
        this->_groups[name] = {};

    if (this->hasGroup(entity, name))
        throw util::Error("engine::ecs::World::addToGroup()", "The entity is already in the group '" + name + "'");

    this->_groups.at(name).emplace_back(entity);
}

bool engine::ecs::World::hasGroup(engine::ecs::Entity& entity, const std::string& name) const
{
    if (this->_groups.count(name) == 0)
        throw util::Error("engine::ecs::World::hasGroup()", "The group '" + name + "' doesn't exist");

    auto it =
        std::find_if(this->_groups.at(name).begin(), this->_groups.at(name).end(), [&entity](const auto& wrapper) {
            return (&wrapper.get() == &entity);
        });

    return (it != this->_groups.at(name).end());
}

std::vector<std::reference_wrapper<engine::ecs::Entity>>& engine::ecs::World::getGroup(const std::string& name) const
{
    if (this->_groups.count(name) == 0)
        throw util::Error("engine::ecs::World::getGroup()", "The group '" + name + "' doesn't exist");

    return const_cast<std::vector<std::reference_wrapper<engine::ecs::Entity>>&>(this->_groups.at(name));
}

void engine::ecs::World::removeFromGroup(engine::ecs::Entity& entity, const std::string& name)
{
    if (this->_groups.count(name) == 0)
        throw util::Error("engine::ecs::World::removeFromGroup()", "The group '" + name + "' doesn't exist");

    auto it =
        std::find_if(this->_groups.at(name).begin(), this->_groups.at(name).end(), [&entity](const auto& wrapper) {
            return (&wrapper.get() == &entity);
        });

    if (it == this->_groups.at(name).end())
        throw util::Error("engine::ecs::World::removeFromGroup()", "The entity is not in the group '" + name + "'");

    this->_groups.at(name).erase(it);

    if (this->_groups.at(name).empty())
        this->_groups.erase(name);
}

template<>
engine::system::AAnimations& engine::ecs::World::addSystem<engine::system::AAnimations>()
{
    std::type_index id = typeid(system::AAnimations);

    if (this->_systems.count(id))
        throw util::Error("engine::ecs::World::addSystem()", "Already has this type of system");

    auto& graphical = this->getUniverse().getCore().getCurrentGraphical();
    auto& system = graphical.createAnimationsSystem(*this);

    this->_systems.emplace(id, system);

    return system;
}

template<>
engine::system::AAudio& engine::ecs::World::addSystem<engine::system::AAudio>()
{
    std::type_index id = typeid(system::AAudio);

    if (this->_systems.count(id))
        throw util::Error("engine::ecs::World::addSystem()", "Already has this type of system");

    auto& graphical = this->getUniverse().getCore().getCurrentGraphical();
    auto& system = graphical.createAudioSystem(*this);

    this->_systems.emplace(id, system);

    return system;
}

template<>
engine::system::ARender& engine::ecs::World::addSystem<engine::system::ARender>()
{
    std::type_index id = typeid(system::ARender);

    if (this->_systems.count(id))
        throw util::Error("engine::ecs::World::addSystem()", "Already has this type of system");

    auto& graphical = this->getUniverse().getCore().getCurrentGraphical();
    auto& system = graphical.createRenderSystem(*this);

    this->_systems.emplace(id, system);

    return system;
}
