/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_ASystem.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "../src/engine/ecs/Universe.hpp"
#include "../src/engine/core/Core.hpp"

#include "mock_system.hpp"

Test(ASystem, ASystem_constructor)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.addSystem<System>();

}

Test(AComponent, ASystem_getWorld)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.addSystem<System>();
    auto& system = world.getSystem<System>();
    cr_assert_eq(&system.getWorld(), &world);
}