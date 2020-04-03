/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** universe.cpp
*/

#include <criterion/criterion.h>

#include "../src/engine/ecs/Universe.hpp"
#include "../src/engine/core/Core.hpp"
#include "../src/engine/ecs/World.hpp"

Test(Universe, Universe_construct)
{
    engine::core::Core core;
}

Test(Universe, Universe_getCore)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    cr_assert_eq(&universe.getCore(), &core);
}

Test(Universe, Universe_getEventBus)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    universe.getEventBus();
}

Test(Universe, Universe_init_without_world)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    try {
        universe.init();
        cr_assert_eq(false, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}

Test(Universe, Universe_init_with_world)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    universe.createWorld("world");
    universe.setCurrentWorld("world");
    try {
        universe.init();
        cr_assert_eq(true, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(Universe, Universe_update_without_world)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    try {
        universe.update();
        cr_assert_eq(false, true);
    }
    catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
        return;
    }
}

Test(Universe, Universe_update_with_world)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    universe.createWorld("world");
    universe.setCurrentWorld("world");
    try {
        universe.update();
        cr_assert_eq(false, false);
    }
    catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(Universe, Universe_render_without_world)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    try {
        universe.render();
        cr_assert_eq(false, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}

Test(Universe, Universe_render_with_world)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    universe.createWorld("world");
    universe.setCurrentWorld("world");
    try {
        universe.render();
        cr_assert_eq(false, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(Universe, Universe_createWorld)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    universe.createWorld("world");
}

Test(Universe, Universe_hasWorld_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    universe.createWorld("world");
    cr_assert_eq(universe.hasWorld("world"), true);
}

Test(Universe, Universe_hasWorld_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    cr_assert_eq(universe.hasWorld("world"), false);
}

Test(Universe, Universe_getCurrentWorld_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    universe.createWorld("world");
    universe.setCurrentWorld("world");
    try {
        universe.getCurrentWorld();
        cr_assert_eq(false, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(Universe, Universe_setCurrentWorld_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    universe.createWorld("world");
    try {
        universe.setCurrentWorld("world");
        cr_assert_eq(false, false);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(Universe, Universe_setCurrentWorld_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    try {
        universe.setCurrentWorld("world");
        cr_assert_eq(false, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}

Test(Universe, Universe_deleteWorld_true)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    universe.createWorld("world");
    try {
        universe.deleteWorld("world");
        cr_assert_eq(true, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, false);
    }
}

Test(Universe, Universe_deleteWorld_false)
{
    engine::core::Core core;
    auto& universe = core.getUniverse();
    try {
        universe.deleteWorld("world");
        cr_assert_eq(false, true);
    } catch (engine::util::Error& e) {
        cr_assert_eq(true, true);
    }
}