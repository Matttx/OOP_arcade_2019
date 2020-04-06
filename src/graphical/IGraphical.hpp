/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphical.hpp
*/

/**
 * @file IGraphical.hpp
 * @brief Interface for graphical implementation
 */

#ifndef OOP_ARCADE_2019_IGRAPHICAL_HPP
#define OOP_ARCADE_2019_IGRAPHICAL_HPP

#include <string>

#include "../engine/component/AAudio.hpp"
#include "../engine/component/ARender.hpp"
#include "../engine/component/AText.hpp"
#include "../engine/eventbus/EventBus.hpp"
#include "../engine/system/AAnimations.hpp"
#include "../engine/system/AAudio.hpp"
#include "../engine/system/ARender.hpp"

/**
 * @brief Type of graphical
 */
enum LIBTYPE { TEXT, GRAPHIC, DEBUG };

namespace graphical {

/**
 * @class Interface of graphical
 */
class IGraphical {
  public:
    /**
     * @brief Destructor of IGraphical
     */
    virtual ~IGraphical() = 0;

  public:
    /**
     * @brief Initialize the graphical
     */
    virtual void init() = 0;
    /**
     * @brief Dispatch event in the event bus
     */
    virtual void dispatchEvent() = 0;
    /**
     * @brief Destroy the graphical
     */
    virtual void destroy() = 0;

  public:
    /**
     * @brief Get the name of graphical
     *
     * @return Name of graphical
     */
    virtual std::string getName() const = 0;
    /**
     * @brief Get the type of graphical
     *
     * @return Type of graphical
     */
    virtual LIBTYPE getType() const = 0;
    /**
     * @brief Get the event bus
     *
     * @return Reference of the event bus
     */
    virtual engine::eventbus::EventBus& getEventBus() const = 0;

  public:
    /**
     * @brief Create audio component
     *
     * @param entity Entity that the component belongs to
     * @param paths Vector of audio paths
     *
     * @return Reference of the created audio component
     */
    virtual engine::component::AAudio& createAudio(
        engine::ecs::Entity& entity, const std::vector<std::string>& paths) = 0;
    /**
     * @brief Create render component
     *
     * @param entity Entity that the component belongs to
     * @param paths Vector of render paths
     *
     * @return Reference of the created render component
     */
    virtual engine::component::ARender& createRender(
        engine::ecs::Entity& entity, const std::vector<std::string>& paths) = 0;
    /**
     * @brief Create text component
     *
     * @param entity Entity that the component belongs to
     * @param paths Vector of font paths
     *
     * @return Reference of the created text component
     */
    virtual engine::component::AText& createText(
        engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths) = 0;

  public:
    /**
     * @brief Create animations system
     *
     * @param world World that the system belongs to
     *
     * @return Reference of the created animations system
     */
    virtual engine::system::AAnimations& createAnimationsSystem(engine::ecs::World& world) = 0;
    /**
     * @brief Create audio system
     *
     * @param world World that the system belongs to
     *
     * @return Reference of the created audio system
     */
    virtual engine::system::AAudio& createAudioSystem(engine::ecs::World& world) = 0;
    /**
     * @brief Create render system
     *
     * @param world World that the system belongs to
     *
     * @return Reference of the created render system
     */
    virtual engine::system::ARender& createRenderSystem(engine::ecs::World& world) = 0;
};

} // namespace graphical

#endif // OOP_ARCADE_2019_IGRAPHICAL_HPP
