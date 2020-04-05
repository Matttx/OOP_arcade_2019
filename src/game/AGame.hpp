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
/**
 * @class AGame that inherits from IGame
 * 
 */
class AGame : public IGame {
  public:
    /**
     * @brief Construct a new AGame object
     * 
     * @param name : the name of the game
     * @param universe : a reference to an universe
     */
    explicit AGame(const std::string& name, engine::ecs::Universe& universe);
    /**
     * @brief Destroy the AGame object
     * 
     */
    ~AGame() override = 0;

  public:
    /**
     * @brief getName : get the name of the game
     * 
     * @return std::string : return the name of the game
     */
    std::string getName() const override;
    /**
     * @brief Get the Universe object
     * 
     * @return engine::ecs::Universe& : return a reference to the universe of the game
     */
    engine::ecs::Universe& getUniverse() const override;

  public:
    /**
     * @brief init : pure virtual to init the child game
     * 
     */
    void init() override = 0;
    /**
     * @brief destroy : pure virtual to destroy the child game
     * 
     */
    void destroy() override = 0;

  private:
    /**
     * @brief _name : the game name
     * 
     */
    std::string _name;
    /**
     * @brief _universe : a reference to an universe
     * 
     */
    engine::ecs::Universe& _universe;
};

} // namespace game

#endif // OOP_ARCADE_2019_AGAME_HPP
