/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core.hpp
*/

#ifndef OOP_ARCADE_2019_CORE_HPP
#define OOP_ARCADE_2019_CORE_HPP

namespace game {
class IGame;
}

namespace graphical {
class IGraphical;
}

#include "../ecs/Universe.hpp"
#include "DynamicLibrary.hpp"

namespace engine {

namespace core {

class Core {
  public:
    Core();
    ~Core();

  public:
    ecs::Universe& getUniverse() const;

  public:
    void loadGames();
    void loadGraphics();

  public:
    bool hasGame(const std::string& name) const;
    game::IGame& getGame(const std::string& name) const;
    game::IGame& getCurrentGame() const;
    void setCurrentGame(const std::string& name);

  public:
    bool hasGraphical(const std::string& name) const;
    graphical::IGraphical& getGraphical(const std::string& name) const;
    graphical::IGraphical& getCurrentGraphical() const;
    void setCurrentGraphical(const std::string& name);

  private:
    ecs::Universe _universe;
    std::string _currentGame;
    std::map<std::string, DynamicLibrary<game::IGame>> _games;
    std::string _currentGraphical;
    std::map<std::string, DynamicLibrary<graphical::IGraphical>> _graphicals;
};

} // namespace core

} // namespace engine

#endif // OOP_ARCADE_2019_CORE_HPP
