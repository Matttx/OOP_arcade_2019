/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Collision.hpp
*/

/**
 * @brief Collision event
 */

#ifndef OOP_ARCADE_2019_EVENT_COLLISION_HPP
#define OOP_ARCADE_2019_EVENT_COLLISION_HPP

#include "../ecs/Entity.hpp"
#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {
/**
 * @class Class of Collision
 *
 */
class Collision : public eventbus::AEvent {
  public:
    /**
     * @brief entity1 : Reference to the first entity
     *
     */
    ecs::Entity& entity1;
    /**
     * @brief entity2 : Reference to the second entity
     *
     */
    ecs::Entity& entity2;

  public:
    /**
     * @brief Constructor of Collision
     *
     * @param entity1 : Reference to the first entity
     * @param entity2 : Reference to the second entity
     */
    Collision(ecs::Entity& entity1, ecs::Entity& entity2);
    /**
     * @brief Destructor of Collision
     *
     */
    ~Collision() override;
};

} // namespace event

} // namespace engine

#endif // OOP_ARCADE_2019_EVENT_COLLISION_HPP
