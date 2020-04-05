/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Hitbox.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_HITBOX_HPP
#define OOP_ARCADE_2019_COMPONENT_HITBOX_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @class Class of component Hitbox
 * 
 */
class Hitbox : public ecs::AComponent {
  public:
    /**
     * @brief width : width of the hitbox
     * 
     */
    int width;
    /**
     * @brief height : height of the hitbox
     * 
     */
    int height;

  public:
    /**
     * @brief Construct a new Hitbox object
     * 
     * @param entity : the entity that the component belongs to
     * @param width : width of the hitbox
     * @param height : height of the hitbox
     */
    Hitbox(engine::ecs::Entity& entity, int width, int height);
    /**
     * @brief Destroy the Hitbox object
     * 
     */
    ~Hitbox() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_HITBOX_HPP
