/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AUser.hpp
*/

/**
 * @file AUser.hpp
 * @brief Class for user component implementation
 */

#ifndef OOP_ARCADE_2019_COMPONENT_AUSER_HPP
#define OOP_ARCADE_2019_COMPONENT_AUSER_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @class Abstract class of user component
 *
 */
class AUser : public ecs::AComponent {
  public:
    /**
     * @brief Constructor of AUser
     *
     * @param entity : Entity that the component belongs to
     */
    explicit AUser(engine::ecs::Entity& entity);
    /**
     * @brief Destructor of AUser
     *
     */
    ~AUser() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_AUSER_HPP
