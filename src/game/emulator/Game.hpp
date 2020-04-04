/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game.hpp
*/

#ifndef OOP_ARCADE_2019_SRC_GAME_EMULATOR_GAME_HPP
#define OOP_ARCADE_2019_SRC_GAME_EMULATOR_GAME_HPP

#include "../../engine/ecs/Universe.hpp"
#include "../AGame.hpp"

namespace emulator {

class Game : public game::AGame {
  public:
    explicit Game(engine::ecs::Universe& universe);
    ~Game() override;

  public:
    void init() override;
    void destroy() override;

  private:
    void initBackground(engine::ecs::World& main);
    void initGraphicalMenu(engine::ecs::World& main);
    void initGameMenu(engine::ecs::World& main);
};

} // namespace emulator

#endif // OOP_ARCADE_2019_SRC_GAME_EMULATOR_GAME_HPP
