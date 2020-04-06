/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphical
*/

#include "Graphical.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../../engine/event/Close.hpp"
#include "../../../engine/event/Input.hpp"
#include "../../AGraphical.hpp"
#include "component/Audio.hpp"
#include "component/Render.hpp"
#include "component/Text.hpp"
#include "system/Animations.hpp"
#include "system/Audio.hpp"
#include "system/Render.hpp"

sdl::Graphical::Graphical(engine::eventbus::EventBus &eventBus)
    : graphical::AGraphical("sdl", LIBTYPE::GRAPHIC, eventBus)
{
    _window = nullptr;
    _renderer = nullptr;
}

sdl::Graphical::~Graphical()
{
    if (_active)
        destroy();
}

extern "C" sdl::Graphical *create(engine::eventbus::EventBus *eventBus)
{
    return new sdl::Graphical(*eventBus);
}

void sdl::Graphical::init()
{
    if (SDL_Init(SDL_INIT_VIDEO))
        throw std::runtime_error(std::string("SDL: Can't init SDL: ", SDL_GetError()).c_str());

    if (!IMG_Init(IMG_INIT_PNG))
        throw std::runtime_error(std::string("SDL: Can't init SDL_image: ", SDL_GetError()).c_str());

    if (TTF_Init())
        throw std::runtime_error(std::string("SDL: Can't init SDL_ttf: ", SDL_GetError()).c_str());

    _window =
        SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_RESIZABLE);

    if (!_window)
        throw std::runtime_error(std::string("SDL: Can't create Window: ", SDL_GetError()).c_str());

    _renderer = SDL_CreateRenderer(_window, -1, 0);

    if (!_renderer)
        throw std::runtime_error(std::string("SDL: Can't create Renderer: ", SDL_GetError()).c_str());

    SDL_RenderSetLogicalSize(_renderer, 1920, 1080);
    SDL_ShowCursor(0);

    _active = true;
}

void sdl::Graphical::dispatchEvent()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_KEYDOWN) {
            auto input = new engine::event::Input(SDLKEYCODE.at(e.key.keysym.sym));

            getEventBus().publish(*input);

            delete input;
        }
        if (e.type == SDL_QUIT) {
            auto close = new engine::event::Close();

            getEventBus().publish(*close);

            delete close;
        }
    }
}

void sdl::Graphical::destroy()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    _active = false;
}

engine::component::AAudio &sdl::Graphical::createAudio(
    engine::ecs::Entity &entity, const std::vector<std::string> &paths)
{
    return *(new sdl::component::Audio(entity, paths));
}

engine::component::ARender &sdl::Graphical::createRender(
    engine::ecs::Entity &entity, const std::vector<std::string> &paths)
{
    return *(new sdl::component::Render(entity, paths, _renderer));
}

engine::component::AText &sdl::Graphical::createText(
    engine::ecs::Entity &entity, const std::string &text, const std::vector<std::string> &paths)
{
    return *(new sdl::component::Text(entity, text, paths, _renderer));
}

engine::system::AAnimations &sdl::Graphical::createAnimationsSystem(engine::ecs::World &world)
{
    return *(new sdl::system::Animations(world));
}

engine::system::AAudio &sdl::Graphical::createAudioSystem(engine::ecs::World &world)
{
    return *(new sdl::system::Audio(world));
}

engine::system::ARender &sdl::Graphical::createRenderSystem(engine::ecs::World &world)
{
    return *(new sdl::system::Render(world, *_renderer));
}