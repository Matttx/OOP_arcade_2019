/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Collision.hpp
*/

#ifndef OOP_ARCADE_2019_EVENT_COLLISION_HPP
#define OOP_ARCADE_2019_EVENT_COLLISION_HPP

#include "../ecs/Entity.hpp"
#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {
/**
 * @class Collision that inherits from AEvent
 *
 */
class Collision : public eventbus::AEvent {
  public:
    /**
     * @brief entity1 : a reference to an entity
     *
     */
    ecs::Entity& entity1;
    /**
     * @brief entity2 : a reference to an entity
     *
     */
    ecs::Entity& entity2;

  public:
    /**
     * @brief Construct a new Collision object
     *
     * @param entity1 : a reference to an entity
     * @param entity2 : a reference to an entity
     */
    Collision(ecs::Entity& entity1, ecs::Entity& entity2);
    /**
     * @brief Destroy the Collision object
     *
     */
    ~Collision() override;
};

} // namespace event

} // namespace engine

#endif // OOP_ARCADE_2019_EVENT_COLLISION_HPP
