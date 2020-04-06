/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_ENTITY_HPP
#define OOP_ARCADE_2019_ECS_ENTITY_HPP

/**
 * @brief Entity class, container of components
 */

namespace engine {
namespace ecs {
class World;
} // namespace ecs
} // namespace engine

#include <functional>
#include <map>
#include <typeindex>
#include <typeinfo>
#include <vector>

#include "../component/AAudio.hpp"
#include "../component/ARender.hpp"
#include "../component/AText.hpp"
#include "../util/Error.hpp"
#include "AComponent.hpp"

namespace engine {

namespace ecs {

/**
 * @brief Class of entity
 */
class Entity {
  public:
    /**
     * @brief Constructor of Entity
     *
     * @param world World that the entity belongs to
     */
    explicit Entity(World& world);
    /**
     * @brief Destructor of Entity
     */
    ~Entity();

    /**
     * @brief
     */
  public:
    /**
     * @brief Get the world
     *
     * @return Reference of the world
     */
    World& getWorld() const;

  public:
    /**
     * @brief Add a component
     *
     * @tparam T Type of the component
     * @tparam TArgs Variadic parameter-pack
     * @param args Arguments of the component
     *
     * @return Reference of the added component
     */
    template<typename T, typename... TArgs>
    T& addComponent(TArgs&&... args)
    {
        std::type_index id = typeid(T);

        if (this->_components.count(id))
            throw util::Error("engine::ecs::Entity::addComponent()", "Already has this type of component");

        auto* component = new T(*this, args...);

        this->_components.emplace(id, *component);

        return *component;
    }

    /**
     * @brief Check if the entity has the specified components
     *
     * @tparam T Type of the component
     * @tparam TArgs Type of the components
     *
     * @return true : Entity has the components
     * @return false : Entity doesn't have all the components
     */
    template<typename T = void, typename... TArgs>
    bool hasComponents() const
    {
        std::type_index id = typeid(T);
        bool has = this->_components.count(id);

        if (sizeof...(TArgs))
            has &= this->hasComponents<TArgs...>();

        return has;
    }

    /**
     * @brief Get the specified component
     *
     * @tparam T Type of the component
     *
     * @return Reference of the component
     */
    template<typename T>
    T& getComponent() const
    {
        std::type_index id = typeid(T);

        if (this->_components.count(id) == 0)
            throw util::Error("engine::ecs::Entity::getComponent()", "Doesn't have this type of component");

        AComponent& component = this->_components.at(id).get();

        return dynamic_cast<T&>(component);
    }

    /**
     * @brief Remove the specified component
     *
     * @tparam T Type of the component
     */
    template<typename T>
    void removeComponent()
    {
        std::type_index id = typeid(T);

        if (this->_components.count(id) == 0)
            throw util::Error("engine::ecs::Entity::getComponent()", "Doesn't have this type of component");

        delete &this->_components.at(id).get();

        this->_components.erase(id);
    }

  private:
    /**
     * @brief Reference to the world
     */
    World& _world;

  private:
    /**
     * @brief Map of components
     * Key: Component identifier
     * Value: Component
     */
    std::map<std::type_index, std::reference_wrapper<AComponent>> _components;
};

template<>
component::AAudio& Entity::addComponent<component::AAudio>(const std::vector<std::string>& paths);

template<>
component::ARender& Entity::addComponent<component::ARender>(const std::vector<std::string>& paths);

template<>
engine::component::AText& engine::ecs::Entity::addComponent<engine::component::AText>(
    const std::string& text, const std::vector<std::string>& paths);

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ENTITY_HPP
