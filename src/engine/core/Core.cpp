/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core.cpp
*/

#include "Core.hpp"

#include <dirent.h>

#include "../../game/IGame.hpp"
#include "../../graphical/IGraphical.hpp"

engine::core::Core::Core() : _universe(*this)
{
}

engine::core::Core::~Core() = default;

engine::ecs::Universe& engine::core::Core::getUniverse() const
{
    return const_cast<ecs::Universe&>(this->_universe);
}

void engine::core::Core::loadGames()
{
    DIR* directory = opendir("./games/");

    if (directory == nullptr)
        throw util::Error(
            "engine::core::Core::loadGames()", "Games directory doesn't exist");

    dirent* ent = readdir(directory);

    for (; ent != nullptr; ent = readdir(directory)) {
        if (ent->d_name[0] != '.') {
            const std::string path = "./games/" + std::string(ent->d_name);

            auto* dynamicLibrary =
                new DynamicLibrary<game::IGame>(path, &this->getUniverse());

            this->_games.emplace(ent->d_name, *dynamicLibrary);
        }
    }

    closedir(directory);
}

void engine::core::Core::loadGraphics()
{
    DIR* directory = opendir("./lib/");

    if (directory == nullptr)
        throw util::Error("engine::core::Core::loadGraphics()",
            "Graphicals directory doesn't exist");

    dirent* ent = readdir(directory);

    for (; ent != nullptr; ent = readdir(directory)) {
        if (ent->d_name[0] != '.') {
            const std::string path = "./lib/" + std::string(ent->d_name);

            auto* dynamicLibrary = new DynamicLibrary<graphical::IGraphical>(
                path, &this->getUniverse().getEventBus());

            this->_graphicals.emplace(ent->d_name, *dynamicLibrary);
        }
    }

    closedir(directory);
}

bool engine::core::Core::hasGame(const std::string& name) const
{
    return this->_games.count(name);
}

game::IGame& engine::core::Core::getGame(const std::string& name) const
{
    if (this->_games.count(name) == 0)
        throw util::Error("engine::core::Core::getGame()",
            "The game '" + name + "' doesn't exist");

    return this->_games.at(name).get();
}

game::IGame& engine::core::Core::getCurrentGame() const
{
    if (this->_games.count(this->_currentGame) == 0)
        throw util::Error("engine::core::Core::getCurrentGame()",
            "The game '" + this->_currentGame + "' doesn't exist");

    return this->_games.at(this->_currentGame).get();
}

void engine::core::Core::setCurrentGame(const std::string& name)
{
    if (this->_games.count(name) == 0)
        throw util::Error("engine::core::Core::setCurrentGame()",
            "The game '" + name + "' doesn't exist");

    this->_currentGame = name;
}

bool engine::core::Core::hasGraphical(const std::string& name) const
{
    return this->_graphicals.count(name);
}

graphical::IGraphical& engine::core::Core::getGraphical(
    const std::string& name) const
{
    if (this->_graphicals.count(name) == 0)
        throw util::Error("engine::core::Core::getGraphical()",
            "The graphical '" + name + "' doesn't exist");

    return this->_graphicals.at(name).get();
}

graphical::IGraphical& engine::core::Core::getCurrentGraphical() const
{
    if (this->_graphicals.count(this->_currentGraphical) == 0)
        throw util::Error("engine::core::Core::getCurrentGraphical()",
            "The graphical '" + this->_currentGraphical + "' doesn't exist");

    return this->_graphicals.at(this->_currentGraphical).get();
}

void engine::core::Core::setCurrentGraphical(const std::string& name)
{
    if (this->_graphicals.count(name) == 0)
        throw util::Error("engine::core::Core::setCurrentGraphical()",
            "The graphical '" + name + "' doesn't exist");

    this->_currentGraphical = name;
}
