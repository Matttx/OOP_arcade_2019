/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_ENTITY_HPP
#define OOP_ARCADE_2019_ECS_ENTITY_HPP

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
#include "../util/Error.hpp"
#include "AComponent.hpp"

namespace engine {

namespace ecs {

class Entity {
  public:
    explicit Entity(World& world);
    ~Entity();

  public:
    World& getWorld() const;

  public:
    template<typename T, typename... TArgs>
    T& addComponent(TArgs&&... args)
    {
        std::type_index id = typeid(T);

        if (this->_components.count(id))
            throw util::Error("engine::ecs::Entity::addComponent()",
                "Already has this type of component");

        auto* component = new T(*this, args...);

        this->_components.emplace(id, *component);

        return *component;
    }

    template<typename T = void, typename... TArgs>
    bool hasComponents() const
    {
        std::type_index id = typeid(T);
        bool has = this->_components.count(id);

        if (sizeof...(TArgs))
            has &= this->hasComponents<TArgs...>();

        return has;
    }

    template<typename T>
    T& getComponent() const
    {
        std::type_index id = typeid(T);

        if (this->_components.count(id) == 0)
            throw util::Error("engine::ecs::Entity::getComponent()",
                "Doesn't have this type of component");

        AComponent& component = this->_components.at(id).get();

        return dynamic_cast<T&>(component);
    }

    template<typename T>
    void removeComponent()
    {
        std::type_index id = typeid(T);

        if (this->_components.count(id) == 0)
            throw util::Error("engine::ecs::Entity::getComponent()",
                "Doesn't have this type of component");

        delete &this->_components.at(id).get();

        this->_components.erase(id);
    }

  private:
    World& _world;

  private:
    std::map<std::type_index, std::reference_wrapper<AComponent>> _components;
};

template<>
component::AAudio& Entity::addComponent<component::AAudio>(
    const std::vector<std::string>& paths);

template<>
component::ARender& Entity::addComponent<component::ARender>(
    const std::vector<std::string>& paths);

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ENTITY_HPP
