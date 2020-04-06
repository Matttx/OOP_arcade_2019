/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core.hpp
*/

/**
 * @brief Class to manage core system, game and graphicals libraries
 */

#ifndef OOP_ARCADE_2019_CORE_HPP
#define OOP_ARCADE_2019_CORE_HPP

#include "../../game/IGame.hpp"
#include "../../graphical/IGraphical.hpp"
#include "../ecs/Universe.hpp"
#include "../event/Close.hpp"
#include "../save/Component.hpp"
#include "../save/System.hpp"
#include "DynamicLibrary.hpp"

namespace engine {

namespace core {
/**
 * @class Core
 *
 */
class Core {
  public:
    /**
     * @brief Constructor of Core
     *
     */
    Core();
    /**
     * @brief Destructor of Core
     *
     */
    ~Core();

  public:
    /**
     * @brief Get the universe
     *
     * @return ecs::Universe& : Reference of the universe
     */
    ecs::Universe& getUniverse() const;

  public:
    /**
     * @brief Load the game libraries
     *
     */
    void init(const std::string& graphical);
    void run();

  public:
    void loadGames();
    /**
     * @brief Load the graphical libraries
     *
     */
    void loadGraphics();

  public:
    /**
     * @brief hasGame : Check if the core has a game with the specified name
     *
     * @param name : Name of the game
     *
     * @return true : Core has the game
     * @return false : Core doesn't have the game
     */
    bool hasGame(const std::string& name) const;
    /**
     * @brief hasCurrentGame : Check if the core has a valid current game
     *
     * @return true : Current game is valid
     * @return false : Current game is invalid
     */
    bool hasCurrentGame() const;
    /**
     * @brief Get the game with the specified name
     *
     * @param name : Name of the game
     *
     * @return game::IGame& : Reference of the game
     */
    game::IGame& getGame(const std::string& name) const;
    /**
     * @brief Get the current game
     *
     * @return game::IGame& : Reference of the game
     */
    game::IGame& getCurrentGame() const;
    /**
     * @brief Set the current game
     *
     * @param name : Name of the game
     */
    void setCurrentGame(const std::string& name);
    /**
     * @brief Get the game names
     *
     * @return std::map<std::string, std::string> : Map of games
     * Key: Game identifier
     * Value: Game name
     */
    std::map<std::string, std::string> getGames() const;
    /**
     * @brief switchGame : Switch the current game
     *
     */
    void switchGame();

  public:
    /**
     * @brief hasGraphical : Check if the core has a graphical with the specified name
     *
     * @param name : Name of the graphical
     *
     * @return true : Core has the game
     * @return false : Core doesn't have the game
     */
    bool hasGraphical(const std::string& name) const;
    /**
     * @brief hasCurrentGraphical : Check if the core has a valid current graphical
     *
     * @return true : Current game is valid
     * @return false : Current game is invalid
     */
    bool hasCurrentGraphical() const;
    /**
     * @brief getGraphical : Get the graphical with the specified name
     *
     * @param name : Name of the graphical
     *
     * @return graphical::IGraphical& : Reference of the graphical
     */
    graphical::IGraphical& getGraphical(const std::string& name) const;
    /**
     * @brief getCurrentGraphical : Get the current graphical
     *
     * @return graphical::IGraphical& : Reference of the graphical
     */
    graphical::IGraphical& getCurrentGraphical() const;
    /**
     * @brief setCurrentGraphical : Set the current graphical
     *
     * @param name : Name of the graphical
     */
    void setCurrentGraphical(const std::string& name);
    /**
     * @brief Get the graphical names
     *
     * @return std::map<std::string, std::string> : Map of graphicals
     * Key: Graphical identifier
     * Value: Graphical name
     */
    std::map<std::string, std::string> getGraphicals() const;
    /**
     * @brief switchGraphical : Switch the current graphical
     *
     */
    void switchGraphical();

  private:
    /**
     * @brief _currentGame : Identifier of the current game
     *
     */
    std::string _currentGame;
    /**
     * @brief _nextGame : Identifier of the next game
     *
     */
    std::string _nextGame;
    /**
     * @brief _games : Map of games
     * Key: Game identifier
     * Value: Game
     *
     */
    std::map<std::string, DynamicLibrary<game::IGame>> _games;
    /**
     * @brief _currentGraphical : Identifier of the current graphical
     *
     */
    std::string _currentGraphical;
    bool _running;
    /**
     * @brief _nextGraphical : Identifier of the next graphical
     *
     */
    std::string _nextGraphical;
    /**
     * @brief _games : Map of graphicals
     * Key: Graphical identifier
     * Value: Graphical
     *
     */
    std::map<std::string, DynamicLibrary<graphical::IGraphical>> _graphicals;

    ecs::Universe _universe;

  private:
    /**
     * @brief Close event manager
     *
     * @param Close event reference
     */
    void closeManager(engine::event::Close&);
    /**
     * @brief saveAAudioComponents : Save a copy of audio component parameters
     *
     * @return std::vector<save::component::AAudio> : Vector of AAudio component saves
     */
    std::vector<save::component::AAudio> saveAAudioComponents();
    /**
     * @brief saveARenderComponents : Save a copy of render component parameters
     *
     * @return std::vector<save::component::ARender> : Vector of ARender component saves
     */
    std::vector<save::component::ARender> saveARenderComponents();
    /**
     * @brief saveTextComponents : Save a copy of text component parameters
     *
     * @return std::vector<save::component::AText> : Vector of AText component saves
     */
    std::vector<save::component::AText> saveATextComponents();
    /**
     * @brief saveAAnimationsSystem : Save a copy of animations system parameters
     *
     * @return std::vector<save::system::AAnimations> : Vector of AAnimations system saves
     */
    std::vector<save::system::AAnimations> saveAAnimationsSystems();
    /**
     * @brief saveAAudioSystems : Save a copy of audio system parameters
     *
     * @return std::vector<save::system::AAudio> : Vector of AAudio system saves
     */
    std::vector<save::system::AAudio> saveAAudioSystems();
    /**
     * @brief saveARenderSystems : Save a copy of render system parameters
     *
     * @return std::vector<save::system::ARender> : Vector of ARender system saves
     */
    std::vector<save::system::ARender> saveARenderSystems();
};

} // namespace core

} // namespace engine

#endif // OOP_ARCADE_2019_CORE_HPP
