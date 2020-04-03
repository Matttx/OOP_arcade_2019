/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_AUDIO_HPP
#define OOP_ARCADE_2019_SYSTEM_AUDIO_HPP

#include "../../../../engine/system/AAudio.hpp"

namespace sfml {
namespace system {
class Audio : public engine::system::AAudio {
  public:
    explicit Audio(engine::ecs::World& world);
    ~Audio() override = default;
    void init() override;
    void update() override;
    void render() override;
};
} // namespace system
} // namespace sfml

#endif // OOP_ARCADE_2019_AUDIO_HPP
