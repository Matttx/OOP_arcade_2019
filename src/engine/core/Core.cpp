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

bool engine::core::Core::hasGameGraphical() const
{
    return this->_games.count(this->_currentGame);
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

    if (name == this->_currentGame)
        return;

    auto previousGame = this->_currentGame;

    this->_currentGame = name;

    this->_games.at(this->_currentGame).get().init();

    if (this->_games.count(previousGame))
        this->_games.at(previousGame).get().destroy();
}

bool engine::core::Core::hasGraphical(const std::string& name) const
{
    return this->_graphicals.count(name);
}

bool engine::core::Core::hasCurrentGraphical() const
{
    return this->_graphicals.count(this->_currentGraphical);
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

    if (name == this->_currentGraphical)
        return;

    auto previousGraphical = this->_currentGraphical;

    this->_currentGraphical = name;

    this->_graphicals.at(this->_currentGraphical).get().init();

    if (this->getUniverse().hasCurrentWorld()) {
        this->updateGraphicalComponent();
        this->updateGraphicalSystem();
    }

    if (this->_graphicals.count(previousGraphical))
        this->_graphicals.at(previousGraphical).get().destroy();
}

void engine::core::Core::updateGraphicalComponent()
{
    auto entities = this->getUniverse()
                        .getCurrentWorld()
                        .getEntities<engine::component::AAudio>();

    for (const auto& entity : entities) {
        auto& audio = entity.get().getComponent<engine::component::AAudio>();
        const auto paths = audio.paths;

        entity.get().removeComponent<engine::component::AAudio>();
        entity.get().addComponent<engine::component::AAudio>(paths);
    }

    entities = this->getUniverse()
                   .getCurrentWorld()
                   .getEntities<engine::component::ARender>();

    for (const auto& entity : entities) {
        auto& render = entity.get().getComponent<engine::component::ARender>();
        const auto paths = render.paths;

        entity.get().removeComponent<engine::component::ARender>();
        entity.get().addComponent<engine::component::ARender>(paths);
    }
}

void engine::core::Core::updateGraphicalSystem()
{
    this->getUniverse()
        .getCurrentWorld()
        .removeSystem<engine::system::AAudio>();
    this->getUniverse().getCurrentWorld().addSystem<engine::system::AAudio>();

    this->getUniverse()
        .getCurrentWorld()
        .removeSystem<engine::system::ARender>();
    this->getUniverse().getCurrentWorld().addSystem<engine::system::ARender>();
}

std::map<std::string, engine::core::DynamicLibrary<game::IGame>>&
    engine::core::Core::getGames() const
{
    return const_cast<
        std::map<std::string, engine::core::DynamicLibrary<game::IGame>>&>(
        _games);
}
std::map<std::string, engine::core::DynamicLibrary<graphical::IGraphical>>&
    engine::core::Core::getGraphicals() const
{
    return const_cast<
        std::map<std::string, engine::core::DynamicLibrary<graphical::IGraphical>>&>(
        _graphicals);
}
