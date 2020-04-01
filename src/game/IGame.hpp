/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame.hpp
*/

#ifndef OOP_ARCADE_2019_IGAME_HPP
#define OOP_ARCADE_2019_IGAME_HPP

#include <string>

namespace game {

class IGame {
  public:
    virtual ~IGame() = 0;

  public:
    virtual std::string getName() = 0;

  public:
    virtual void init() = 0;
    virtual void destroy() = 0;
};

}

#endif // OOP_ARCADE_2019_IGAME_HPP