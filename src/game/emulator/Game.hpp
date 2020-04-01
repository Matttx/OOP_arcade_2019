/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game.hpp
*/

#ifndef OOP_ARCADE_2019_GAME_HPP
#define OOP_ARCADE_2019_GAME_HPP

#include "../AGame.hpp"

namespace game {

namespace emulator {

class Game : public AGame {
  public:
    explicit Game(engine::ecs::Universe& universe);
    ~Game() override;

  public:
    void init() override;
    void destroy() override;
};

}

}

#endif // OOP_ARCADE_2019_GAME_HPP
