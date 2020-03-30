/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render.hpp
*/

#ifndef OOP_ARCADE_2019_RENDER_HPP
#define OOP_ARCADE_2019_RENDER_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include "../../../../engine/system/ARender.hpp"

namespace sfml {
namespace system {
class Render : public engine::system::ARender {
  public:
    explicit Render(engine::ecs::World& world, sf::RenderWindow& window);
    ~Render() override = default;
    void init() override;
    void update() override;
    void render() override;

  private:
    sf::RenderWindow& _window;
};
} // namespace system
} // namespace sfml

#endif // OOP_ARCADE_2019_RENDER_HPP
