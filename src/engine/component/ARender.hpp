/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ARender.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_ARENDER_HPP
#define OOP_ARCADE_2019_COMPONENT_ARENDER_HPP

#include <string>
#include <vector>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @class Abstract class of component Render
 * 
 */
class ARender : public ecs::AComponent {
  public:
    /**
     * @brief paths : vector of sprite paths
     * 
     */
    std::vector<std::string> paths;

  public:
    /**
     * @brief Construct a new ARender object
     * 
     * @param entity : the entity that the component belongs to
     * @param paths : vector of sprite paths
     */
    ARender(ecs::Entity& entity, const std::vector<std::string>& paths);
    /**
     * @brief Destroy the ARender object
     * 
     */
    ~ARender() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_ARENDER_HPP
