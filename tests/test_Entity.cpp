/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_Entity.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "../src/engine/ecs/Universe.hpp"
#include "../src/engine/core/Core.hpp"
#include "../src/engine/ecs/World.hpp"

#include "mock_component.hpp"


Test(Entity, Entity_constructor)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    (void) entity;
}

Test(Entity, Entity_getWorld)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    entity.getWorld();
}

Test(Entity, Entity_addComponent_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    entity.addComponent<Component>();
}

Test(Entity, Entity_addComponent_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    entity.addComponent<Component>();
    try {
        entity.addComponent<Component>();
        cr_assert_eq(true, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}

Test(Entity, Entity_hasComponent_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    entity.addComponent<Component>();
    cr_assert_eq(entity.hasComponents<Component>(), true);
}

Test(Entity, Entity_hasComponent_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    cr_assert_eq(entity.hasComponents<Component>(), false);
}

Test(Entity, Entity_getComponent_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    entity.addComponent<Component>();
    try {
        entity.getComponent<Component>();
        cr_assert_eq(true, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(Entity, Entity_getComponent_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    try {
        entity.getComponent<Component>();
        cr_assert_eq(true, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}

Test(Entity, Entity_removeComponent_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    entity.addComponent<Component>();
    try {
        entity.removeComponent<Component>();
        cr_assert_eq(true, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(Entity, Entity_removeComponent_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    try {
        entity.removeComponent<Component>();
        cr_assert_eq(true, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}