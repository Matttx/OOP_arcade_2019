/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animations.hpp
*/

#ifndef OOP_ARCADE_2019_ANIMATIONS_HPP
#define OOP_ARCADE_2019_ANIMATIONS_HPP

#include <SFML/System/Clock.hpp>

#include "../../../../engine/system/AAnimations.hpp"
#include "../../../../engine/type/Animation.hpp"

namespace sfml {
namespace system {
class Animations : public engine::system::AAnimations {
  public:
    explicit Animations(engine::ecs::World& world);
    ~Animations() override = default;
    void init() override;
    void update() override;
    void render() override;

  private:
    sf::Clock _clock;
};
} // namespace system
} // namespace sfml

#endif // OOP_ARCADE_2019_ANIMATION_HPP
