/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_AComponent.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "../src/engine/ecs/Universe.hpp"
#include "../src/engine/core/Core.hpp"
#include "../src/engine/ecs/World.hpp"

#include "mock_component.hpp"

Test(AComponent, AComponent_constructor)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    entity.addComponent<Component>();

}

Test(AComponent, AComponent_getEntity)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    entity.addComponent<Component>();
    auto& comp = entity.getComponent<Component>();
    comp.getEntity();
}