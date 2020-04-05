/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGame.hpp
*/

#ifndef OOP_ARCADE_2019_AGAME_HPP
#define OOP_ARCADE_2019_AGAME_HPP

#include "IGame.hpp"

namespace game {

class AGame : public IGame {
  public:
    explicit AGame(const std::string& name, engine::ecs::Universe& universe);
    ~AGame() override = 0;

  public:
    std::string getName() const override;
    engine::ecs::Universe& getUniverse() const override;

  public:
    void init() override = 0;
    void destroy() override = 0;

  private:
    std::string _name;
    engine::ecs::Universe& _universe;
};

} // namespace game

#endif // OOP_ARCADE_2019_AGAME_HPP
