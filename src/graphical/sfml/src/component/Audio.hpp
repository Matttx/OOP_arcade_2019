/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio.hpp
*/

#ifndef OOP_ARCADE_2019_AUDIO_HPP
#define OOP_ARCADE_2019_AUDIO_HPP

#include <string>
#include <vector>
#include <SFML/Audio.hpp>

#include "../../../../engine/component/AAudio.hpp"
#include "../../../../engine/ecs/Entity.hpp"

namespace sfml {
namespace component {
class Audio : public engine::component::AAudio {
  public:
    Audio(engine::ecs::Entity &entity, const std::vector<std::string> &paths);
    sf::Music music;
};
} // namespace component
} // namespace sfml

#endif // OOP_ARCADE_2019_AUDIO_HPP
