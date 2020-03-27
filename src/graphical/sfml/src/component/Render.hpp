/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render.hpp
*/

#ifndef OOP_ARCADE_2019_RENDER_HPP
#define OOP_ARCADE_2019_RENDER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "ARender.hpp"

namespace sfml {

namespace component {

class Render : public engine::component::ARender {
  public:
    Render(engine::ecs::Entity &entity, std::vector<std::string> &paths);
    ~Render() override = 0;

  private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Text _text;
    sf::Font _font;
};

} // namespace component

} // namespace sfml

#endif // OOP_ARCADE_2019_RENDER_HPP
