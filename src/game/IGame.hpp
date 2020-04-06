/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame.hpp
*/

/**
 * @file IGame.hpp
 * @brief Interface for game implementation
 */

#ifndef OOP_ARCADE_2019_IGAME_HPP
#define OOP_ARCADE_2019_IGAME_HPP

#include <string>

#include "../engine/ecs/Universe.hpp"

namespace game {
/**
 * @class Interface for game
 *
 */
class IGame {
  public:
    /**
     * @brief Destructor of IGame
     *
     */
    virtual ~IGame() = 0;

  public:
    /**
     * @brief getName : Get the name of the game
     *
     * @return std::string : Name of the game
     */
    virtual std::string getName() const = 0;
    /**
     * @brief getUniverse : Get the universe
     *
     * @return engine::ecs::Universe& : Reference to the universe
     */
    virtual engine::ecs::Universe& getUniverse() const = 0;

  public:
    /**
     * @brief init : Initialize the game
     *
     */
    virtual void init() = 0;
    /**
     * @brief destroy : Destroy the game
     *
     */
    virtual void destroy() = 0;
};

} // namespace game

#endif // OOP_ARCADE_2019_IGAME_HPP
