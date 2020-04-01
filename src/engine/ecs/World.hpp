/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** World.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_WORLD_HPP
#define OOP_ARCADE_2019_ECS_WORLD_HPP

namespace engine {
namespace ecs {
class Universe;
} // namespace ecs
} // namespace engine

#include <functional>
#include <map>
#include <set>
#include <typeindex>
#include <typeinfo>
#include <vector>

#include "../system/AAudio.hpp"
#include "../system/ARender.hpp"
#include "ASystem.hpp"
#include "Entity.hpp"

namespace engine {

namespace ecs {

class World {
  public:
    explicit World(Universe& universe);
    ~World();

  public:
    Universe& getUniverse() const;

  public:
    void init();
    void update();
    void render();

  public:
    Entity& createEntity();
    void deleteEntity(Entity& entity);

    template<typename... TArgs>
    std::vector<std::reference_wrapper<Entity>> getEntities() const
    {
        std::vector<std::reference_wrapper<Entity>> entities;

        for (const auto& _entity : _entities)
            if (_entity.get().hasComponents<TArgs...>())
                entities.emplace_back(_entity.get());

        return entities;
    }

  public:
    void addToGroup(Entity& entity, const std::string& name);
    bool hasGroup(Entity& entity, const std::string& name) const;
    std::vector<std::reference_wrapper<Entity>>& getGroup(
        const std::string& name) const;
    void removeFromGroup(Entity& entity, const std::string& name);

  public:
    template<typename T, typename... TArgs>
    T& addSystem(TArgs&&... args)
    {
        std::type_index id = typeid(T);

        if (this->_systems.count(id))
            throw util::Error("engine::ecs::World::addSystem()",
                "Already has this type of system");

        auto* system = new T(*this, args...);

        this->_systems.emplace(id, *system);

        return *system;
    }

    template<typename T = void, typename... TArgs>
    bool hasSystems() const
    {
        std::type_index id = typeid(T);
        bool has = this->_systems.count(id);

        if (sizeof...(TArgs))
            has &= this->hasSystems<TArgs...>();

        return has;
    }

    template<typename T>
    T& getSystem() const
    {
        std::type_index id = typeid(T);

        if (this->_systems.count(id) == 0)
            throw util::Error("engine::ecs::World::getSystem()",
                "Doesn't have this type of system");

        ASystem& system = this->_systems.at(id).get();

        return dynamic_cast<T&>(system);
    }

    template<typename T>
    void removeSystem()
    {
        std::type_index id = typeid(T);

        if (this->_systems.count(id) == 0)
            throw util::Error("engine::ecs::World::removeSystem()",
                "Doesn't have this type of system");

        delete &this->_systems.at(id).get();

        this->_systems.erase(id);
    }

  private:
    Universe& _universe;

  private:
    std::vector<std::reference_wrapper<Entity>> _entities;
    std::map<std::string, std::vector<std::reference_wrapper<Entity>>> _groups;

  private:
    std::map<std::type_index, std::reference_wrapper<ASystem>> _systems;
};

template<>
system::AAudio& World::addSystem<system::AAudio>();

template<>
system::ARender& World::addSystem<system::ARender>();

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_WORLD_HPP
