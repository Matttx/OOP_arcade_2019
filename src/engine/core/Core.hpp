/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core.hpp
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
     * @brief Construct a new Core object
     * 
     */
    Core();
    /**
     * @brief Destroy the Core object
     * 
     */
    ~Core();

  public:
    /**
     * @brief Get the Universe object
     * 
     * @return ecs::Universe& 
     */
    ecs::Universe& getUniverse() const;

  public:
    /**
     * @brief Load the Games lib
     * 
     */
    void init(const std::string& graphical);
    void run();

  public:
    void loadGames();
    /**
     * @brief Load the Graphics lib
     * 
     */
    void loadGraphics();

  public:
    /**
     * @brief hasGame : Function that check if the core has a game with his name
     * 
     * @param name : name of the game
     * @return true : the core has the game
     * @return false : the core don't has the game
     */
    bool hasGame(const std::string& name) const;
    /**
     * @brief hasGameGraphical : Function that check if a game is displaying
     * 
     * @return true : the game is displaying
     * @return false : the game is not displaying
     */
    bool hasGameGraphical() const;
    /**
     * @brief Get the Game
     * 
     * @param name : the name of the game
     * @return game::IGame& : return a reference of IGame 
     */
    game::IGame& getGame(const std::string& name) const;
    /**
     * @brief Get the Current Game
     * 
     * @return game::IGame& : return a reference of IGame
     */
    game::IGame& getCurrentGame() const;
    /**
     * @brief Set the Current Game
     * 
     * @param name : the name of the game to set
     */
    void setCurrentGame(const std::string& name);
    /**
     * @brief Get the Games
     * 
     * @return std::map<std::string, std::string> : return a map of games : the first key is a string of ... and the second is a string of ...
     */
    std::map<std::string, std::string> getGames() const;
    /**
     * @brief switchGame : function that switch a game with another
     * 
     */
    void switchGame();

  public:
    /**
     * @brief hasGraphical : check if there is a graphical library
     * 
     * @param name : name of the library
     * @return true : the library is found
     * @return false : the library is not found
     */
    bool hasGraphical(const std::string& name) const;
    /**
     * @brief hasCurrentGraphical : check if a graphical library is displaying
     * 
     * @return true : a graphical library is displaying
     * @return false : a graphical library is not displaying
     */
    bool hasCurrentGraphical() const;
    /**
     * @brief getGraphical : get a special graphical library 
     * 
     * @param name : the name of the library to get
     * @return graphical::IGraphical& : return a IGraphical reference of the graphical library get
     */
    graphical::IGraphical& getGraphical(const std::string& name) const;
    /**
     * @brief getCurrentGraphical : get the current graphical library
     * 
     * @return graphical::IGraphical& : return a IGraphical reference of the current graphical library
     */
    graphical::IGraphical& getCurrentGraphical() const;
    /**
     * @brief setCurrentGraphical : set the current graphical library
     * 
     * @param name : the name of the library to set
     */
    void setCurrentGraphical(const std::string& name);
    /**
     * @brief getGraphicals : get the graphicals library
     * 
     * @return std::map<std::string, std::string> : return a map of strings that correspond of the graphical library
     */
    std::map<std::string, std::string> getGraphicals() const;
    /**
     * @brief switchGraphical : switch graphical library
     * 
     */
    void switchGraphical();

  private:
    /**
     * @brief _currentGame : string that represent the current game
     * 
     */
    std::string _currentGame;
    /**
     * @brief _nextGame : string that represent the next game
     * 
     */
    std::string _nextGame;
    /**
     * @brief _games : map of games : the first key is a string that represent the name of the game and the second is e dynamic library of the corresponding game
     * 
     */
    std::map<std::string, DynamicLibrary<game::IGame>> _games;
    /**
     * @brief _currentGraphical : string that represent the current graphical library
     * 
     */
    std::string _currentGraphical;
    bool _running;
    /**
     * @brief _nextGraphical : string that represent the next graphical library
     * 
     */
    std::string _nextGraphical;
    /**
     * @brief _graphicals : map of graphical library : the first key is a string that represent the name of the library and the second is a dynamic library of the corresponding library
     * 
     */
    std::map<std::string, DynamicLibrary<graphical::IGraphical>> _graphicals;

    ecs::Universe _universe;

  private:
    void closeManager(engine::event::Close&);
    std::vector<save::component::AAudio> saveAAudioComponents();
    /**
     * @brief saveARenderComponents : save a copy of render parameters for the library change
     * 
     * @return std::vector<save::component::ARender> : return a vector of ARender component
     */
    std::vector<save::component::ARender> saveARenderComponents();
    /**
     * @brief saveTextComponents : save a copy of text parameters for the library change
     * 
     * @return std::vector<save::component::AText> : return a vector of AText component
     */
    std::vector<save::component::AText> saveATextComponents();
    /**
     * @brief saveAAnimationsSystem : save a copy of animations systems parameters for the library change
     * 
     * @return std::vector<save::system::AAnimations> : return a vector of AAnimation system
     */
    std::vector<save::system::AAnimations> saveAAnimationsSystems();
    /**
     * @brief saveAAudioSystems : save a copy of audio systems parameters for the library change
     * 
     * @return std::vector<save::system::AAudio> : return a vector of AAudio systems
     */
    std::vector<save::system::AAudio> saveAAudioSystems();
    /**
     * @brief saveARenderSystems : save a copy of render systems parameters for the library change
     * 
     * @return std::vector<save::system::ARender> : return a vector of ARender systems
     */
    std::vector<save::system::ARender> saveARenderSystems();
};

} // namespace core

} // namespace engine

#endif // OOP_ARCADE_2019_CORE_HPP
