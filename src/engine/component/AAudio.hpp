/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_AAUDIO_HPP
#define OOP_ARCADE_2019_COMPONENT_AAUDIO_HPP

#include <string>
#include <vector>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @brief Abstract class of component Audio
 * 
 */
class AAudio : public ecs::AComponent {
  public:
    /**
     * @brief Vector of audio paths
     * 
     */
    const std::vector<std::string> paths;

  public:
    /**
     * @brief Construct a new AAudio object
     * 
     * @param entity : the entity that the component belongs to
     * @param paths : vector of audio paths
     */
    AAudio(ecs::Entity& entity, const std::vector<std::string>& paths);
    /**
     * @brief Destroy the AAudio object
     * 
     */
    ~AAudio() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_AAUDIO_HPP
