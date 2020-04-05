/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame.hpp
*/

#ifndef OOP_ARCADE_2019_IGAME_HPP
#define OOP_ARCADE_2019_IGAME_HPP

#include <string>

#include "../engine/ecs/Universe.hpp"

namespace game {
/**
 * @class IGame interface
 * 
 */
class IGame {
  public:
    /**
     * @brief Destroy the IGame object
     * 
     */
    virtual ~IGame() = 0;

  public:
    /**
     * @brief getName : pure virtual to get name 
     * 
     * @return std::string : return a string of the name
     */
    virtual std::string getName() const = 0;
    /**
     * @brief getUniverse : pure virtual to get universe 
     * 
     * @return engine::ecs::Universe& : return a reference to an universe
     */
    virtual engine::ecs::Universe& getUniverse() const = 0;

  public:
    /**
     * @brief init : pure virtual for the init of the game
     * 
     */
    virtual void init() = 0;
    /**
     * @brief destroy : pure virtual for the destroy of the game
     * 
     */
    virtual void destroy() = 0;
};

} // namespace game

#endif // OOP_ARCADE_2019_IGAME_HPP
