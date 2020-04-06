/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

/**
 * @file AAudio.hpp
 * @brief Class for audio component implementation
 */

#ifndef OOP_ARCADE_2019_COMPONENT_AAUDIO_HPP
#define OOP_ARCADE_2019_COMPONENT_AAUDIO_HPP

#include <string>
#include <vector>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @brief Abstract class of audio component
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
     * @brief Constructor of AAudio
     *
     * @param entity : Entity that the component belongs to
     * @param paths : Vector of audio paths
     */
    AAudio(ecs::Entity& entity, const std::vector<std::string>& paths);
    /**
     * @brief Destructor of AAudio
     *
     */
    ~AAudio() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_AAUDIO_HPP
