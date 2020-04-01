/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGraphical.hpp
*/

#ifndef OOP_ARCADE_2019_AGRAPHICAL_HPP
#define OOP_ARCADE_2019_AGRAPHICAL_HPP

#include <vector>

#include "IGraphical.hpp"

namespace graphical {

class AGraphical : public IGraphical {
  public:
    AGraphical(const std::string& name, LIBTYPE type,
        engine::eventbus::EventBus& eventBus);
    ~AGraphical() override = 0;

  public:
    void init() override = 0;
    void dispatchEvent() override = 0;
    void destroy() override = 0;

  public:
    std::string getName() const override;
    LIBTYPE getType() const override;

  public:
    engine::component::AAudio& createAudio(engine::ecs::Entity& entity,
        const std::vector<std::string>& paths) override = 0;
    engine::component::ARender& createRender(engine::ecs::Entity& entity,
        const std::vector<std::string>& paths) override = 0;

  public:
    engine::system::AAudio& createAudioSystem(
        engine::ecs::World& world) override = 0;
    engine::system::ARender& createRenderSystem(
        engine::ecs::World& world) override = 0;

  private:
    std::string _name;
    LIBTYPE _type;
    engine::eventbus::EventBus _eventBus;
};

} // namespace graphical

#endif // OOP_ARCADE_2019_AGRAPHICAL_HPP
