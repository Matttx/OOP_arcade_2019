/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AText.hpp
*/

/**
 * @brief Class for text implementation
 */

#ifndef OOP_ARCADE_2019_ATEXT_HPP
#define OOP_ARCADE_2019_ATEXT_HPP

#include <string>
#include <vector>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @class Abstract class of Text component
 *
 */
class AText : public ecs::AComponent {
  public:
    /**
     * @brief text : Text to display
     *
     */
    const std::string text;
    /**
     * @brief paths : Vector of fonts used to display the text
     *
     */
    const std::vector<std::string> paths;

  public:
    /**
     * @brief Constructor of AText
     *
     * @param entity : Entity that the component belongs to
     * @param text : Text to display
     * @param paths : Vector of fonts used to display the text
     */
    AText(ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths);
    /**
     * @brief Destructor of AText
     *
     */
    ~AText() override = 0;
};
} // namespace component
} // namespace engine

#endif // OOP_ARCADE_2019_ATEXT_HPP
