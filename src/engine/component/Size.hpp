/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Size.hpp
*/

/**
 * @brief Class for size
 */

#ifndef OOP_ARCADE_2019_COMPONENT_SIZE_HPP
#define OOP_ARCADE_2019_COMPONENT_SIZE_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @class Class of the Size component
 *
 */
class Size : public ecs::AComponent {
  public:
    /**
     * @brief width : Width of the entity
     *
     */
    int width;
    /**
     * @brief height : Height of the entity
     *
     */
    int height;

  public:
    /**
     * @brief Constructor of Size
     *
     * @param entity : Entity that the component belongs to
     * @param width : Width of the entity
     * @param height : Height of the entity
     */
    Size(ecs::Entity& entity, int width, int height);
    /**
     * @brief Destructor of Size
     *
     */
    ~Size() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_SIZE_HPP
