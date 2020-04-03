/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphical
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Graphical.hpp"

#include "../../../engine/event/Input.hpp"
#include "../../AGraphical.hpp"
#include "component/Audio.hpp"
#include "component/Render.hpp"
#include "system/Audio.hpp"
#include "system/Render.hpp"


sdl::Graphical::Graphical(engine::eventbus::EventBus& eventBus) : graphical::AGraphical("sdl", LIBTYPE::GRAPHIC, eventBus), _eventBus(eventBus)
{
    _window = nullptr;
    renderer = nullptr;
}

sdl::Graphical::~Graphical()
{
    destroy();
}

extern "C" sdl::Graphical* create(engine::eventbus::EventBus& eventBus)
 {
     return new sdl::Graphical(eventBus);
 }

void sdl::Graphical::init()
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(_window, -1, 0);
}

void sdl::Graphical::dispatchEvent()
{
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        for (auto& i : SDLKEYCODE) {
            if (e.key.keysym.sym == (i.first)) {
                auto input = new engine::event::Input(i.second);
                _eventBus.publish(*input);
                delete input;
            }
        }
    }
}

void sdl::Graphical::destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}

engine::component::AAudio &sdl::Graphical::createAudio(engine::ecs::Entity &entity, const std::vector<std::string> &paths)
{
    return *(new sdl::component::Audio(entity, paths));
}

engine::component::ARender &sdl::Graphical::createRender(engine::ecs::Entity &entity, const std::vector<std::string> &paths)
{
    return *(new sdl::component::Render(entity, paths, renderer));
}

engine::system::AAudio &sdl::Graphical::createAudioSystem(engine::ecs::World &world)
{
    return *(new sdl::system::Audio(world));
}

engine::system::ARender &sdl::Graphical::createRenderSystem(engine::ecs::World &world)
{
    return *(new sdl::system::Render(world, *renderer));
}