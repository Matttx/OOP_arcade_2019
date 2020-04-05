/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAI.hpp : Abstract class of component AI
*/

#ifndef OOP_ARCADE_2019_COMPONENT_AAI_HPP
#define OOP_ARCADE_2019_COMPONENT_AAI_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @brief Abstract Class of component AI
 * 
 */
class AAI : public ecs::AComponent {
  public:
    /**
     * @brief Construct a new AAI object
     * 
     * @param entity : the entity which the component belongs to
     */
    explicit AAI(engine::ecs::Entity& entity);
    ~AAI() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_AAI_HPP
