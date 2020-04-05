/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Size.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_SIZE_HPP
#define OOP_ARCADE_2019_COMPONENT_SIZE_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @class Class of the component size
 * 
 */
class Size : public ecs::AComponent {
  public:
    /**
     * @brief width : width of the render of the entity
     * 
     */
    int width;
    /**
     * @brief height : height of the render of the entity
     * 
     */
    int height;

  public:
    /**
     * @brief Construct a new Size object
     * 
     * @param entity : the entity that the component belongs to
     * @param width : width of the render of the entity
     * @param height : height of the render of the entity
     */
    Size(ecs::Entity& entity, int width, int height);
    /**
     * @brief Destroy the Size object
     * 
     */
    ~Size() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_SIZE_HPP
