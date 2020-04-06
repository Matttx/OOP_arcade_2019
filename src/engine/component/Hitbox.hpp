/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Hitbox.hpp
*/

/**
 * @brief Class for hitbox
 */

#ifndef OOP_ARCADE_2019_COMPONENT_HITBOX_HPP
#define OOP_ARCADE_2019_COMPONENT_HITBOX_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @class Class of Hitbox component
 *
 */
class Hitbox : public ecs::AComponent {
  public:
    /**
     * @brief width : Width of the entity's hitbox
     *
     */
    int width;
    /**
     * @brief height : Height of the entity's hitbox
     *
     */
    int height;

  public:
    /**
     * @brief Constructor of Hitbox
     *
     * @param entity : Entity that the component belongs to
     * @param width : Width of the hitbox
     * @param height : Height of the hitbox
     */
    Hitbox(engine::ecs::Entity& entity, int width, int height);
    /**
     * @brief Destructor of Hitbox
     *
     */
    ~Hitbox() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_HITBOX_HPP
