/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ARender.hpp
*/

/**
 * @file ARender.hpp
 * @brief Class for render component implementation
 */

#ifndef OOP_ARCADE_2019_COMPONENT_ARENDER_HPP
#define OOP_ARCADE_2019_COMPONENT_ARENDER_HPP

#include <string>
#include <vector>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @class Abstract class of render component
 *
 */
class ARender : public ecs::AComponent {
  public:
    /**
     * @brief paths : Vector of sprite paths
     *
     */
    std::vector<std::string> paths;

  public:
    /**
     * @brief Constructor of ARender
     *
     * @param entity : Entity that the component belongs to
     * @param paths : Vector of sprite paths
     */
    ARender(ecs::Entity& entity, const std::vector<std::string>& paths);
    /**
     * @brief Destructor of ARender
     *
     */
    ~ARender() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_ARENDER_HPP
