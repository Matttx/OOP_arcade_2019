/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Action.hpp
*/

#ifndef OOP_ARCADE_2019_SRC_GAME_EMULATOR_COMPONENT_ACTION_HPP
#define OOP_ARCADE_2019_SRC_GAME_EMULATOR_COMPONENT_ACTION_HPP

#include <functional>

#include "../../../engine/ecs/AComponent.hpp"
#include "../../../engine/ecs/Universe.hpp"

namespace emulator {

namespace component {

class Action : public engine::ecs::AComponent {
  public:
    using Callback = std::function<void(engine::ecs::Universe&)>;

  public:
    explicit Action(engine::ecs::Entity& entity, const Callback& callback);
    ~Action() override;

  public:
    Callback callback;
};

} // namespace component

} // namespace emulator

#endif // OOP_ARCADE_2019_SRC_GAME_EMULATOR_COMPONENT_ACTION_HPP
