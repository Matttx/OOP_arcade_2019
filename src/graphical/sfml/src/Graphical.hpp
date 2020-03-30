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

#include "../../AGraphical.hpp"
#include "../../../engine/eventbus/EventBus.hpp"
#include "component/Render.hpp"
#include "component/Audio.hpp"
#include "system/Render.hpp"

namespace sfml {
class Graphical : public AGraphical {
  public:
    explicit Graphical(engine::eventbus::EventBus &eventBus);

    ~Graphical();

    void init() override;

    void dispatchEvent() override;

    void destroy() override;

    engine::component::AAudio createAudio(engine::ecs::Entity &entity,
        const std::vector<std::string> &paths) override;

    engine::component::ARender createRender(engine::ecs::Entity &entity,
        const std::vector<std::string> &paths) override;

    engine::system::AAudio createAudioSystem(
        engine::ecs::World &world) override;

    engine::system::ARender createRenderSystem(
        engine::ecs::World &world) override;

  private:
    std::vector<sfml::component::Audio> _audios;
    std::vector<sfml::component::Render> _renders;
    sfml::system::Audio _sysAudios;
    sfml::system::Render _sysRenders;
};
} // namespace sfml

#endif // OOP_ARCADE_2019_GRAPHICAL_HPP
