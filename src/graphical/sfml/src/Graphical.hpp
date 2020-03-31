/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphical.hpp
*/

#ifndef OOP_ARCADE_2019_GRAPHICAL_HPP
#define OOP_ARCADE_2019_GRAPHICAL_HPP

#include <string>
#include <vector>

#include "../../../engine/eventbus/EventBus.hpp"
#include "../../../engine/system/AAudio.hpp"
#include "../../AGraphical.hpp"
#include "component/Audio.hpp"
#include "component/Render.hpp"
#include "system/Render.hpp"

namespace sfml {
class Graphical : public graphical::AGraphical {
  public:
    explicit Graphical(engine::eventbus::EventBus &eventBus);

    ~Graphical() override;

    void init() override;

    void dispatchEvent() override;

    void destroy() override;

    engine::component::AAudio &createAudio(engine::ecs::Entity &entity,
        const std::vector<std::string> &paths) override;

    engine::component::ARender &createRender(engine::ecs::Entity &entity,
        const std::vector<std::string> &paths) override;

    engine::system::AAudio &createAudioSystem(
        engine::ecs::World &world) override;

    engine::system::ARender &createRenderSystem(
        engine::ecs::World &world) override;

  private:
    sf::RenderWindow *_window;
    engine::eventbus::EventBus& _eventBus;
};
} // namespace sfml

#endif // OOP_ARCADE_2019_GRAPHICAL_HPP
