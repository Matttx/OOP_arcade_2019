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

#include "AAudio.hpp"

namespace sfml {

namespace component {

class Audio : public engine::component::AAudio {
  public:
    Audio(engine::ecs::Entity &entity, std::vector<std::string> &paths);
    ~Audio() override;
};

} // namespace system

} // namespace sfml

#endif // OOP_ARCADE_2019_AUDIO_HPP
