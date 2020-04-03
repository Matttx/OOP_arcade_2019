/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** test_World.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "../src/engine/ecs/Universe.hpp"
#include "../src/engine/core/Core.hpp"
#include "../src/engine/ecs/World.hpp"

#include "mock_system.hpp"

Test(World, World_constructor)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    universe.createWorld("world");
}

Test(World, World_getUniverse)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.getUniverse();
}

Test(World, World_init)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.init();
}

Test(World, World_update)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.update();
}

Test(World, World_render)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.render();
}

Test(Word, World_createEntity)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.createEntity();
}

Test(Word, World_deleteEntity)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    world.deleteEntity(entity);
}

Test(World, World_addToGroup)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    world.addToGroup(entity, "Group");
}

Test(World, World_hasGroup_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    world.addToGroup(entity, "Group");
    cr_assert_eq(true, world.hasGroup(entity, "Group"));
}

Test(World, World_hasGroup_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    world.addToGroup(entity, "Group");
    try {
        world.hasGroup(entity, "false");
        cr_assert_eq(true, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}

Test(World, World_getGroup_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    world.addToGroup(entity, "Group");
    try {
        world.getGroup("Group");
        cr_assert_eq(true, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(World, World_getGroup_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    world.addToGroup(entity, "Group");
    try {
        world.getGroup("false");
        cr_assert_eq(true, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}

Test(World, World_removeFromGroup_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    world.addToGroup(entity, "Group");
    try {
        world.removeFromGroup(entity, "Group");
        world.hasGroup(entity, "Group");
        cr_assert_eq(true, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}

Test(World, World_removeFromGroup_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    auto& entity = world.createEntity();
    world.addToGroup(entity, "Group");
    try {
        world.removeFromGroup(entity, "false");
        cr_assert_eq(true, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}

Test(World, World_addSystem)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.addSystem<System>();
}

Test(World, World_hasSystem_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.addSystem<System>();
    cr_assert_eq(world.hasSystems<System>(), true);
}

Test(World, World_hasSystem_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    cr_assert_eq(world.hasSystems<System>(), false);
}

Test(World, World_getSystem_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.addSystem<System>();
    try {
        world.getSystem<System>();
        cr_assert_eq(true, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(World, World_getSystem_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    try {
        world.getSystem<System>();
        cr_assert_eq(true, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}

Test(World, Wrold_removeSystem_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    world.addSystem<System>();
    try {
        world.removeSystem<System>();
        cr_assert_eq(true, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(World, Wrold_removeSystem_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    auto& world = universe.createWorld("world");
    try {
        world.removeSystem<System>();
        cr_assert_eq(true, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}