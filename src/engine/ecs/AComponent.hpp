/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AComponent.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_ACOMPONENT_HPP
#define OOP_ARCADE_2019_ECS_ACOMPONENT_HPP

/**
 * @brief Base class of components
 */

namespace engine {
namespace ecs {
class Entity;
} // namespace ecs
} // namespace engine

namespace engine {

namespace ecs {
/**
 * @class Abstract class of component
 *
 */
class AComponent {
  public:
    /**
     * @brief Constructor of AComponent
     *
     * @param entity : : Entity that the component belongs to
     */
    explicit AComponent(Entity& entity);
    /**
     * @brief Destructor of AComponent
     *
     */
    virtual ~AComponent() = 0;

  public:
    /**
     * @brief Get the entity
     *
     * @return Entity& : Reference of the entity
     */
    Entity& getEntity() const;

  private:
    /**
     * @brief _entity : Reference of the entity
     *
     */
    Entity& _entity;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ACOMPONENT_HPP
