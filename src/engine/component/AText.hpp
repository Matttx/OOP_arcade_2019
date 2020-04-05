/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AText.hpp
*/

#ifndef OOP_ARCADE_2019_ATEXT_HPP
#define OOP_ARCADE_2019_ATEXT_HPP

#include <string>
#include <vector>

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {
/**
 * @class Abstract class of component text
 * 
 */
class AText : public ecs::AComponent {
  public:
    /**
     * @brief text : string that contain the text
     * 
     */
    const std::string text;
    /**
     * @brief paths : vector of fonts use to display the text
     * 
     */
    const std::vector<std::string> paths;

  public:
    /**
     * @brief Construct a new AText object
     * 
     * @param entity : the entity that the component belongs to
     * @param text : the text to display
     * @param paths : vector of fonts use to display the text
     */
    AText(ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths);
    /**
     * @brief Destroy the AText object
     * 
     */
    ~AText() override = 0;
};
}
}

#endif // OOP_ARCADE_2019_ATEXT_HPP
