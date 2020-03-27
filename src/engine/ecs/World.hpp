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
class ASystem;
class Entity;
class Universe;
} // namespace ecs
} // namespace engine

#include <functional>
#include <map>
#include <set>
#include <typeindex>
#include <typeinfo>
#include <vector>

#include "ASystem.hpp"
#include "Entity.hpp"
#include "Universe.hpp"

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

        // TODO: To define

        return entities;
    }

  public:
    void addToGroup(Entity& entity, const std::string& name);
    bool hasGroup(Entity& entity, const std::string& name) const;
    const std::vector<std::reference_wrapper<Entity>>& getGroup(
        const std::string& name) const;
    void removeFromGroup(Entity& entity, const std::string& name);

  public:
    template<typename T, typename... TArgs>
    T& addSystem(TArgs&&... args)
    {
        std::type_index id = typeid(T);

        if (this->_systems.count(id))
            throw std::exception(); // TODO: Custom Error class

        auto* system = new T(*this, args...);

        this->_systems.emplace(id, *system);
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
            throw std::exception(); // TODO: Custom Error class

        ASystem& system = this->_systems.at(id).get();

        return static_cast<T&>(system);
    }

    template<typename T>
    void removeSystem()
    {
        std::type_index id = typeid(T);

        if (this->_systems.count(id) == 0)
            throw std::exception(); // TODO: Custom Error class

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

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_WORLD_HPP