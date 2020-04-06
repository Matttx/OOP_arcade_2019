/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGraphical.hpp
*/

/**
 * @file AGraphical.hpp
 * @brief Class for graphical implementation
 */

#ifndef OOP_ARCADE_2019_AGRAPHICAL_HPP
#define OOP_ARCADE_2019_AGRAPHICAL_HPP

#include <vector>

#include "IGraphical.hpp"

namespace graphical {

/**
 * @brief Abstract class for graphical
 */
class AGraphical : public IGraphical {
  public:
    /**
     * @brief Constructor of AGraphical
     *
     * @param name Name of the graphical
     * @param type Type of the graphical
     * @param eventBus Reference to an event bus
     */
    AGraphical(const std::string& name, LIBTYPE type, engine::eventbus::EventBus& eventBus);
    /**
     * @brief Destructor of AGraphical
     */
    ~AGraphical() override = 0;

  public:
    /**
     * @brief Initialize the graphical
     */
    void init() override = 0;
    /**
     * @brief Dispatch event in the event bus
     */
    void dispatchEvent() override = 0;
    /**
     * @brief Destroy the graphical
     */
    void destroy() override = 0;

  public:
    /**
     * @brief Get the name of graphical
     *
     * @return Name of graphical
     */
    std::string getName() const override;
    /**
     * @brief Get the type of graphical
     *
     * @return Type of graphical
     */
    LIBTYPE getType() const override;
    /**
     * @brief Get the event bus
     *
     * @return Reference of the event bus
     */
    engine::eventbus::EventBus& getEventBus() const override;

  public:
    /**
     * @brief Create audio component
     *
     * @param entity Entity that the component belongs to
     * @param paths Vector of audio paths
     *
     * @return Reference of the created audio component
     */
    engine::component::AAudio& createAudio(
        engine::ecs::Entity& entity, const std::vector<std::string>& paths) override = 0;
    /**
     * @brief Create render component
     *
     * @param entity Entity that the component belongs to
     * @param paths Vector of render paths
     *
     * @return Reference of the created render component
     */
    engine::component::ARender& createRender(
        engine::ecs::Entity& entity, const std::vector<std::string>& paths) override = 0;
    /**
     * @brief Create text component
     *
     * @param entity Entity that the component belongs to
     * @param paths Vector of font paths
     *
     * @return Reference of the created text component
     */
    engine::component::AText& createText(
        engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths) override = 0;

  public:
    /**
     * @brief Create animations system
     *
     * @param world World that the system belongs to
     *
     * @return Reference of the created animations system
     */
    engine::system::AAnimations& createAnimationsSystem(engine::ecs::World& world) override = 0;
    /**
     * @brief Create audio system
     *
     * @param world World that the system belongs to
     *
     * @return Reference of the created audio system
     */
    engine::system::AAudio& createAudioSystem(engine::ecs::World& world) override = 0;
    /**
     * @brief Create render system
     *
     * @param world World that the system belongs to
     *
     * @return Reference of the created render system
     */
    engine::system::ARender& createRenderSystem(engine::ecs::World& world) override = 0;

  private:
    /**
     * @brief Name of the graphical
     */
    std::string _name;
    /**
     * @brief Type of the graphical
     */
    LIBTYPE _type;
    /**
     * @brief Reference of the event bus
     */
    engine::eventbus::EventBus& _eventBus;
};

} // namespace graphical

#endif // OOP_ARCADE_2019_AGRAPHICAL_HPP
