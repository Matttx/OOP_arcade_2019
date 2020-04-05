/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AUser.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_AUSER_HPP
#define OOP_ARCADE_2019_COMPONENT_AUSER_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @class Abstract class of component User
 * 
 */
class AUser : public ecs::AComponent {
  public:
    /**
     * @brief Construct a new AUser object
     * 
     * @param entity : the entity that the component belongs to
     */
    explicit AUser(engine::ecs::Entity& entity);
    /**
     * @brief Destroy the AUser object
     * 
     */
    ~AUser() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_AUSER_HPP
