/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_RENDER_HPP
#define OOP_ARCADE_2019_COMPONENT_RENDER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "ARender.hpp"

namespace sfml {
namespace component {
class Render : public engine::component::ARender {
  public:
    Render(engine::ecs::Entity &entity, const std::vector<std::string> &paths);
    ~Render() override = default;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RenderTexture renderTexture;
};
} // namespace component
} // namespace sfml

#endif // OOP_ARCADE_2019_RENDER_HPP
