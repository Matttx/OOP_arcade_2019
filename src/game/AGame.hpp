/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGame.hpp
*/

/**
 * @file AGame.hpp
 * @brief Class for game implementation
 */

#ifndef OOP_ARCADE_2019_AGAME_HPP
#define OOP_ARCADE_2019_AGAME_HPP

#include "IGame.hpp"

namespace game {
/**
 * @class Abstract class for game
 *
 */
class AGame : public IGame {
  public:
    /**
     * @brief Constructor of AGame
     *
     * @param name : Name of the game
     * @param universe : Reference to an universe
     */
    explicit AGame(const std::string& name, engine::ecs::Universe& universe);
    /**
     * @brief Destructor of AGame
     *
     */
    ~AGame() override = 0;

  public:
    /**
     * @brief getName : Get the name of the game
     *
     * @return std::string : Name of the game
     */
    std::string getName() const override;
    /**
     * @brief Get the universe
     *
     * @return engine::ecs::Universe& : Reference to the universe
     */
    engine::ecs::Universe& getUniverse() const override;

  public:
    /**
     * @brief init : Initialize the game
     *
     */
    void init() override = 0;
    /**
     * @brief destroy : Destroy the game
     *
     */
    void destroy() override = 0;

  private:
    /**
     * @brief _name : Name of the game
     *
     */
    std::string _name;
    /**
     * @brief _universe : Reference of the universe
     *
     */
    engine::ecs::Universe& _universe;
};

} // namespace game

#endif // OOP_ARCADE_2019_AGAME_HPP
