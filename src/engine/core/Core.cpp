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

    this->_nextGame = name;
}

std::map<std::string, std::string> engine::core::Core::getGames() const
{
    std::map<std::string, std::string> map;
    for (const auto& game : _games) {
        map.emplace(game.first, game.second.get().getName());
    }
    return map;
}

void engine::core::Core::switchGame()
{
    if (this->_currentGame == this->_nextGame)
        return;

    if (this->_games.count(this->_currentGame))
        this->_games.at(this->_currentGame).get().destroy();

    this->_currentGame = this->_nextGame;

    this->_games.at(this->_currentGame).get().init();
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

    this->_nextGraphical = name;
}

std::map<std::string, std::string> engine::core::Core::getGraphicals() const
{
    std::map<std::string, std::string> map;
    for (const auto& graphical : _graphicals) {
        map.emplace(graphical.first, graphical.second.get().getName());
    }
    return map;
}

void engine::core::Core::switchGraphical()
{
    if (this->_currentGraphical == this->_nextGraphical)
        return;

    auto aAudioComponentSaves = this->saveAAudioComponents();
    auto aRenderComponentSaves = this->saveARenderComponents();
    auto aAudioSystemSaves = this->saveAAudioSystems();
    auto aRenderSystemSaves = this->saveARenderSystems();

    for (auto& aAudioComponentSave : aAudioComponentSaves)
        aAudioComponentSave.removeFromEntity();

    for (auto& aRenderComponentSave : aRenderComponentSaves)
        aRenderComponentSave.removeFromEntity();

    for (auto& aAudioSystemSave : aAudioSystemSaves)
        aAudioSystemSave.removeFromWorld();

    for (auto& aRenderSystemSave : aRenderSystemSaves)
        aRenderSystemSave.removeFromWorld();

    if (this->_graphicals.count(this->_currentGraphical))
        this->_graphicals.at(this->_currentGraphical).get().destroy();

    this->_currentGraphical = this->_nextGraphical;

    this->_graphicals.at(this->_currentGraphical).get().init();

    for (auto& aAudioComponentSave : aAudioComponentSaves)
        aAudioComponentSave.addToEntity();

    for (auto& aRenderComponentSave : aRenderComponentSaves)
        aRenderComponentSave.addToEntity();

    for (auto& aAudioSystemSave : aAudioSystemSaves)
        aAudioSystemSave.addToWorld();

    for (auto& aRenderSystemSave : aRenderSystemSaves)
        aRenderSystemSave.addToWorld();
}

std::vector<engine::save::component::AAudio>
engine::core::Core::saveAAudioComponents()
{
    std::vector<save::component::AAudio> saves;

    auto worldNames = this->getUniverse().getWorldNames();

    for (const auto& worldName : worldNames) {
        auto entities = this->getUniverse()
            .getWorld(worldName)
            .getEntities<engine::component::AAudio>();

        for (const auto& entity : entities) {
            auto& audio =
                entity.get().getComponent<engine::component::AAudio>();

            saves.emplace_back(entity.get(), audio.paths);
        }
    }

    return saves;
}

std::vector<engine::save::component::ARender>
engine::core::Core::saveARenderComponents()
{
    std::vector<save::component::ARender> saves;

    auto worldNames = this->getUniverse().getWorldNames();

    for (const auto& worldName : worldNames) {
        auto entities = this->getUniverse()
            .getWorld(worldName)
            .getEntities<engine::component::ARender>();

        for (const auto& entity : entities) {
            auto& render =
                entity.get().getComponent<engine::component::ARender>();

            saves.emplace_back(entity.get(), render.paths);
        }
    }

    return saves;
}

std::vector<engine::save::system::AAudio>
engine::core::Core::saveAAudioSystems()
{
    std::vector<save::system::AAudio> saves;

    auto worldNames = this->getUniverse().getWorldNames();

    for (const auto& worldName : worldNames) {
        if (this->getUniverse()
            .getWorld(worldName)
            .hasSystems<engine::system::AAudio>()) {
            saves.emplace_back(this->getUniverse().getCurrentWorld());
        }
    }

    return saves;
}

std::vector<engine::save::system::ARender>
engine::core::Core::saveARenderSystems()
{
    std::vector<save::system::ARender> saves;

    auto worldNames = this->getUniverse().getWorldNames();

    for (const auto& worldName : worldNames) {
        if (this->getUniverse()
            .getWorld(worldName)
            .hasSystems<engine::system::ARender>()) {
            saves.emplace_back(this->getUniverse().getCurrentWorld());
        }
    }

    return saves;
}
