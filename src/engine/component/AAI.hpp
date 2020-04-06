/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAI.hpp : Abstract class of component AI
*/

/**
 * @brief Class for AI implementation
 */

#ifndef OOP_ARCADE_2019_COMPONENT_AAI_HPP
#define OOP_ARCADE_2019_COMPONENT_AAI_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @brief Abstract Class of AI component
 *
 */
class AAI : public ecs::AComponent {
  public:
    /**
     * @brief Constructor of AAI
     *
     * @param entity : Entity which the component belongs to
     */
    explicit AAI(engine::ecs::Entity& entity);
    /**
     * @brief Destructor of AAI
     */
    ~AAI() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_AAI_HPP
