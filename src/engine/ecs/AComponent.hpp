/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AComponent.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_ACOMPONENT_HPP
#define OOP_ARCADE_2019_ECS_ACOMPONENT_HPP

namespace engine {
namespace ecs {
/**
 * @class Entity
 * 
 */
class Entity;
} // namespace ecs
} // namespace engine

namespace engine {

namespace ecs {
/**
 * @class AComponent
 * 
 */
class AComponent {
  public:
    /**
     * @brief Construct a new AComponent object
     * 
     * @param entity : : the entity that the component belongs to
     */
    explicit AComponent(Entity& entity);
    /**
     * @brief Destroy the AComponent object
     * 
     */
    virtual ~AComponent() = 0;

  public:
    /**
     * @brief Get the Entity object
     * 
     * @return Entity& : return the entity get
     */
    Entity& getEntity() const;

  private:
    /**
     * @brief _entity : reference to an Entity
     * 
     */
    Entity& _entity;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ACOMPONENT_HPP
