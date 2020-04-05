/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.hpp
*/

#ifndef OOP_ARCADE_2019_TEXT_HPP
#define OOP_ARCADE_2019_TEXT_HPP

#include <SFML/Graphics/Text.hpp>

#include "../../../../engine/component/AText.hpp"

namespace sfml {

namespace component {
class Text : public engine::component::AText {
  public:
    Text(engine::ecs::Entity& entity, const std::string& text,
        const std::vector<std::string>& paths);
    ~Text() override = default;
    sf::Text text;
    sf::Font font;
};
} // namespace component
} // namespace sfml

#endif // OOP_ARCADE_2019_TEXT_HPP
