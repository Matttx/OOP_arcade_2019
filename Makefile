##
## EPITECH PROJECT, 2019
## OOP_arcade_2019
## File description:
## Makefile
##

NAME				=		arcade
TEST_NAME			=		tests/unit_tests
TEST_SH_NAME		=		tests/tests.sh

COV_DIR				=		obj
INCL_DIR			=		include
OBJ_DIR				=		obj
SRC_DIR				=		src
TEST_DIR			=		tests

LIB_NIBBLER_DIR		=		src/game/nibbler
LIB_PACMAN_DIR		=		src/game/pacman
LIB_NCURSES_DIR		=		src/graphical/ncurses
LIB_SDL_DIR			=		src/graphical/sdl
LIB_SFML_DIR		=		src/graphical/sfml

CC					=		g++
RM					=		rm -rf

LDLIBS				=		-ldl -rdynamic

MAIN_SRC			=		main.cpp

PROJ_SRC			=		engine/component/AAI.cpp			\
							engine/component/AAudio.cpp			\
							engine/component/Animations.cpp		\
							engine/component/ARender.cpp		\
							engine/component/AText.cpp			\
							engine/component/AUser.cpp			\
							engine/component/Hitbox.cpp			\
							engine/component/Motion.cpp			\
							engine/component/Size.cpp			\
							engine/component/Transform.cpp		\
							engine/core/Core.cpp				\
							engine/core/DynamicLibrary.cpp		\
							engine/ecs/AComponent.cpp			\
							engine/ecs/ASystem.cpp				\
							engine/ecs/Entity.cpp				\
							engine/ecs/Universe.cpp				\
							engine/ecs/World.cpp				\
							engine/event/Close.cpp				\
							engine/event/Collision.cpp			\
							engine/event/Input.cpp				\
							engine/eventbus/AEvent.cpp			\
							engine/eventbus/EventBus.cpp		\
							engine/save/Component.cpp			\
							engine/save/System.cpp				\
							engine/system/AAI.cpp				\
							engine/system/AAnimations.cpp		\
							engine/system/AAudio.cpp			\
							engine/system/ARender.cpp			\
							engine/system/AUser.cpp				\
							engine/system/Movement.cpp			\
							engine/system/Physics.cpp			\
							engine/util/Error.cpp				\
							game/AGame.cpp						\
							game/IGame.cpp						\
							game/emulator/Game.cpp				\
							game/emulator/component/Action.cpp	\
							game/emulator/component/User.cpp	\
							game/emulator/system/User.cpp		\
							graphical/AGraphical.cpp			\
							graphical/IGraphical.cpp			\

TEST_SRC			=		test_Universe.cpp					\
							test_World.cpp						\
							test_Entity.cpp						\
							test_AComponent.cpp					\
							test_ASystem.cpp					\


CFLAGS				+=		-I $(INCL_DIR)
CFLAGS				+=		-W -Wall -Wextra -Werror -std=c++17

MAIN_OBJ			=		$(MAIN_SRC:%.cpp=$(OBJ_DIR)/%.o)

PROJ_OBJ			=		$(PROJ_SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_OBJ			=		$(TEST_SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_COV			=		$(PROJ_SRC:%.cpp=$(COV_DIR)/%.gcda)	\
							$(PROJ_SRC:%.cpp=$(COV_DIR)/%.gcno)	\
							$(TEST_SRC:%.cpp=$(COV_DIR)/%.gcda)	\
							$(TEST_SRC:%.cpp=$(COV_DIR)/%.gcno)	\

MAKEFLAGS			+=		--silent

NO_COLOR			=		\e[0;0m
GREEN_COLOR			=		\e[0;32m
RED_COLOR			=		\e[0;31m
GREEN_B_COLOR		=		\e[1;32m
RED_B_COLOR			=		\e[1;31m
YELLOW_B_COLOR		=		\e[1;33m

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.cpp
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(OBJ_DIR)/%.o:		$(TEST_DIR)/%.cpp
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

default:			full

core:				all

games:				libs_game

graphicals:			libs_graphical

$(NAME):			$(MAIN_OBJ) $(PROJ_OBJ)
					$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) \
					&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

all:				$(NAME)

clean:
					$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

sweet:				all clean

debug:				CFLAGS += -g3
debug:				all

debug_re:			CFLAGS += -g3
debug_re:			re

debug_sweet:		CFLAGS += -g3
debug_sweet:		sweet

lib_pacman:
					cd $(LIB_PACMAN_DIR) && $(MAKE) all

lib_pacman_clean:
					cd $(LIB_PACMAN_DIR) && $(MAKE) clean

lib_pacman_fclean:
					cd $(LIB_PACMAN_DIR) && $(MAKE) fclean

lib_pacman_re:
					cd $(LIB_PACMAN_DIR) && $(MAKE) fclean
					cd $(LIB_PACMAN_DIR) && $(MAKE) all

lib_sdl:
					cd $(LIB_SDL_DIR) && $(MAKE) all

lib_sdl_clean:
					cd $(LIB_SDL_DIR) && $(MAKE) clean

lib_sdl_fclean:
					cd $(LIB_SDL_DIR) && $(MAKE) fclean

lib_sdl_re:
					cd $(LIB_SDL_DIR) && $(MAKE) fclean
					cd $(LIB_SDL_DIR) && $(MAKE) all

lib_sfml:
					cd $(LIB_SFML_DIR) && $(MAKE) all

lib_sfml_clean:
					cd $(LIB_SFML_DIR) && $(MAKE) clean

lib_sfml_fclean:
					cd $(LIB_SFML_DIR) && $(MAKE) fclean

lib_sfml_re:
					cd $(LIB_SFML_DIR) && $(MAKE) fclean
					cd $(LIB_SFML_DIR) && $(MAKE) all

libs_game:			lib_pacman

libs_game_clean:	lib_pacman_clean

libs_game_fclean:	lib_pacman_fclean

libs_game_re:		libs_game_fclean libs_game

libs_graphical:			lib_sdl lib_sfml

libs_graphical_clean:	lib_sdl_clean lib_sfml_clean

libs_graphical_fclean:	lib_sdl_fclean lib_sfml_fclean

libs_graphical_re:		libs_graphical_fclean libs_graphical

libs:				libs_game libs_graphical

libs_clean:			libs_game_clean libs_graphical_clean

libs_fclean:		libs_game_fclean libs_graphical_fclean

libs_re:			libs_fclean libs

$(TEST_NAME):		CFLAGS += -fprofile-arcs -ftest-coverage
$(TEST_NAME):		LDLIBS += -lgcov -lcriterion
$(TEST_NAME):		$(PROJ_OBJ) $(TEST_OBJ)
					if [ -d $(TEST_DIR) ]; then \
						$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(LDFLAGS) $(LDLIBS) \
						&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; } \
					fi

tests_run:			$(TEST_NAME)
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Unit tests not found$(NO_COLOR)"; \
					else \
						./$(TEST_NAME) \
						&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

tests_clean:		clean
					$(RM) $(TEST_OBJ)
					$(RM) $(TEST_COV)

tests_fclean:		tests_clean
					$(RM) $(TEST_NAME)

tests_re:			tests_fclean tests_run

tests_sweet:		tests_run tests_clean

tests_sh:			re
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_SH_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Functional tests not found$(NO_COLOR)"; \
					else \
						sh $(TEST_SH_NAME) $(NAME) \
						&& echo "$(GREEN_B_COLOR)Functional tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Functional tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

full:				all libs

full_clean:			clean libs_clean tests_clean

full_fclean:		fclean libs_fclean tests_fclean

full_re:			full_fclean full

full_sweet:			full full_clean

doc:
					doxygen

doc_pdf:
					cd doc/latex && $(MAKE)

doc_clean:
					$(RM) doc

.PHONY:				all clean fclean re sweet															\
					debug debug_re debug_sweet															\
					lib_pacman lib_pacman_clean lib_pacman_fclean lib_pacman_re							\
					lib_sdl lib_sdl_clean lib_sdl_fclean lib_sdl_re										\
					lib_sfml lib_sfml_clean lib_sfml_fclean lib_sfml_re									\
					libs_game libs_game_clean libs_game_fclean libs_game_re								\
					libs_graphical libs_graphical_clean libs_graphical_fclean libs_graphical_re			\
					libs libs_clean libs_fclean libs_re													\
					tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh					\
					full full_clean full_fclean full_re full_sweet										\
