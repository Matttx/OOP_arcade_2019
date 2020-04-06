/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** World.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_WORLD_HPP
#define OOP_ARCADE_2019_ECS_WORLD_HPP

/**
 * @brief World class, container of entities, groups and systems
 */

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

#include "../system/AAnimations.hpp"
#include "../system/AAudio.hpp"
#include "../system/ARender.hpp"
#include "ASystem.hpp"
#include "Entity.hpp"

namespace engine {

namespace ecs {

/**
 * @brief Class of World
 */
class World {
  public:
    /**
     * @brief Constructor of World
     *
     * @param universe Universe that the world belongs to
     */
    explicit World(Universe& universe);
    /**
     * @brief Destructor of World
     */
    ~World();

  public:
    /**
     * @brief Get the universe
     *
     * @return Reference of the universe
     */
    Universe& getUniverse() const;

  public:
    /**
     * @brief Initialize the world
     */
    void init();
    /**
     * @brief Update the world
     */
    void update();
    /**
     * @brief Render the world
     */
    void render();

  public:
    /**
     * @brief Create an entity
     *
     * @return Reference of the created entity
     */
    Entity& createEntity();
    /**
     * @brief Delete the specified entity
     *
     * @param entity Entity to delete
     */
    void deleteEntity(Entity& entity);

    /**
     * @brief Get entities by component
     *
     * @tparam TArgs Type of components
     *
     * @return Vector of matching entities
     */
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
    /**
     * @brief Add an entity to a group
     *
     * @param entity Entity to add
     * @param name Name of the group
     */
    void addToGroup(Entity& entity, const std::string& name);
    /**
     * @brief Check if the specified entity is in the specified group
     *
     * @param entity Entity to check
     * @param name Name of the group
     *
     * @return true : Entity is in the group
     * @return false : Entity is not in the group
     */
    bool hasGroup(Entity& entity, const std::string& name) const;
    /**
     * @brief Get the specified group
     *
     * @param name Name of the group
     *
     * @return Vector of entities in the group
     */
    std::vector<std::reference_wrapper<Entity>>& getGroup(const std::string& name) const;
    /**
     * @brief Remove the specified entity from the specified group
     *
     * @param entity Entity to remove
     * @param name Name of the group
     */
    void removeFromGroup(Entity& entity, const std::string& name);

  public:
    /**
     * @brief Add a system
     *
     * @tparam T Type of the system
     * @tparam TArgs Variadic parameter-pack
     * @param args Arguments of the system
     *
     * @return Reference of the added system
     */
    template<typename T, typename... TArgs>
    T& addSystem(TArgs&&... args)
    {
        std::type_index id = typeid(T);

        if (this->_systems.count(id))
            throw util::Error("engine::ecs::World::addSystem()", "Already has this type of system");

        auto* system = new T(*this, args...);

        this->_systems.emplace(id, *system);

        return *system;
    }

    /**
     * @brief Check if the world has the specified system
     *
     * @tparam T Type of the system
     * @tparam TArgs Type of the systems
     *
     * @return true : World has the systems
     * @return false : World doesn't have all the systems
     */
    template<typename T = void, typename... TArgs>
    bool hasSystems() const
    {
        std::type_index id = typeid(T);
        bool has = this->_systems.count(id);

        if (sizeof...(TArgs))
            has &= this->hasSystems<TArgs...>();

        return has;
    }

    /**
     * @brief Get the specified system
     *
     * @tparam T Type of the system
     *
     * @return Reference of the system
     */
    template<typename T>
    T& getSystem() const
    {
        std::type_index id = typeid(T);

        if (this->_systems.count(id) == 0)
            throw util::Error("engine::ecs::World::getSystem()", "Doesn't have this type of system");

        ASystem& system = this->_systems.at(id).get();

        return dynamic_cast<T&>(system);
    }

    /**
     * @brief Remove the specified system
     *
     * @tparam T Type of the system
     */
    template<typename T>
    void removeSystem()
    {
        std::type_index id = typeid(T);

        if (this->_systems.count(id) == 0)
            throw util::Error("engine::ecs::World::removeSystem()", "Doesn't have this type of system");

        delete &this->_systems.at(id).get();

        this->_systems.erase(id);
    }

  private:
    /**
     * @brief Reference of the universe
     */
    Universe& _universe;

  private:
    /**
     * @brief Vector of entities
     */
    std::vector<std::reference_wrapper<Entity>> _entities;
    /**
     * @brief Map of groups
     * Key: Group name
     * Value: Vector of entities
     */
    std::map<std::string, std::vector<std::reference_wrapper<Entity>>> _groups;

  private:
    /**
     * @brief Map of systems
     * Key: System identifier
     * Value: System
     */
    std::map<std::type_index, std::reference_wrapper<ASystem>> _systems;
};

template<>
engine::system::AAnimations& engine::ecs::World::addSystem<engine::system::AAnimations>();

template<>
system::AAudio& World::addSystem<system::AAudio>();

template<>
system::ARender& World::addSystem<system::ARender>();

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_WORLD_HPP
