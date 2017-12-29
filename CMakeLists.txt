##
## CMakeLists.txt for Indie Studio
## C++ Project made by
## Victor Debray
## Roman Blondeau
## Paul Mendiela
## Theo Penavaire (Twitter: @theo_pnv)
## EPITECH - May/June 2017
##

cmake_minimum_required(VERSION 3.5.0)
project(indie_studio)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(UNIX AND NOT APPLE)
    message(STATUS "Linux detected - Adding compiler flags")
    set(CMAKE_CXX_FLAGS "-std=c++14 -W -Wall -Wextra -lIrrlicht -lGL" )
endif(UNIX AND NOT APPLE)
if(APPLE)
    set(CMAKE_CXX_FLAGS "-std=c++14 -W -Wall -Wextra -lIrrlicht -fvisibility=hidden -fvisibility-inlines-hidden" )
    FIND_LIBRARY( OPENGL_LIB OpenGL )
    FIND_LIBRARY( COCOA_LIB Cocoa )
    FIND_LIBRARY( CARBON_LIB Carbon )
    FIND_LIBRARY( IOKIT_LIB IOKit )
    LIST( APPEND IRRLICHT_LINK_LIBS ${OPENGL_LIB} ${IOKIT_LIB} ${COCOA_LIB} ${CARBON_LIB} )
    ADD_DEFINITIONS(-DMACOSX)
endif(APPLE)

    ## Set Directories
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src/)
set(CORE_DIR ${SRC_DIR}Core/)
set(PAGE_DIR ${SRC_DIR}Page/)
set(FILE_DIR ${SRC_DIR}FileHandler/)

set(LIB_3D_DIR ${SRC_DIR}Lib3D/)
set(GRAPHIC_DIR ${LIB_3D_DIR}/Graphic/)
set(PHYSICS_ENGINE_DIR ${LIB_3D_DIR}/PhysicsEngine/)

set(SOUND_ENGINE_DIR ${SRC_DIR}SoundEngine/)

set(EVENT_DIR ${SRC_DIR}EventReceiver/)
set(GAME_DIR ${SRC_DIR}Game/)
set(CHAR_DIR ${GAME_DIR}Characters/)
set(MAP_DIR ${GAME_DIR}Map/)
set(ACTION_DIR ${GAME_DIR}Actions/)
set(EVENT_DIR ${SRC_DIR}EventReceiver/)
set(EXCEPTION_DIR ${SRC_DIR}Exceptions/)

## Set sources
set(SRCS
        ${SRC_DIR}main.cpp
        ${SRC_DIR}Node.cpp
        ${SRC_DIR}standards.cpp

        ${CORE_DIR}Core.cpp
        ${CORE_DIR}Init.cpp

        ## GAME
        ${GAME_DIR}Game.cpp
        ${GAME_DIR}GameEventReceiver.cpp
        ${GAME_DIR}Timer.cpp
	${GAME_DIR}GameInfo/GameInfo.cpp

	${CHAR_DIR}ACharacter.cpp
	${CHAR_DIR}LemmingManager.cpp
	${CHAR_DIR}Lemming.cpp
	${CHAR_DIR}Lemmings/Walker.cpp
	${CHAR_DIR}Lemmings/Stopper.cpp
	${CHAR_DIR}Lemmings/Exploder.cpp
	${CHAR_DIR}Lemmings/Climber.cpp
	${CHAR_DIR}Lemmings/Floater.cpp
	${CHAR_DIR}Lemmings/Basher.cpp
	${CHAR_DIR}Lemmings/Dead.cpp

        ${ACTION_DIR}ActionManager.cpp
        ${ACTION_DIR}AAction.cpp
        ${ACTION_DIR}Stop.hpp
        ${ACTION_DIR}Bash.hpp
        ${ACTION_DIR}Explode.hpp
        ${ACTION_DIR}Float.hpp
        ${ACTION_DIR}Climb.hpp
        ${ACTION_DIR}Walk.hpp

        ${MAP_DIR}ColorShade.h
        ${MAP_DIR}ColorShadeGen.cpp
        ${MAP_DIR}Map.cpp
        ${MAP_DIR}Level/ILevel.hpp
        ${MAP_DIR}Level/ALevel.cpp
        ${MAP_DIR}Level/Level1.cpp
        ${MAP_DIR}Level/Level1.hpp
        ${MAP_DIR}Level/Level2.cpp
        ${MAP_DIR}Level/Level2.hpp
        ${MAP_DIR}Level/Level3.hpp
        ${MAP_DIR}Level/Level3.cpp
        ${MAP_DIR}Resource/Block.cpp
        ${MAP_DIR}Resource/Particule.cpp
        ${MAP_DIR}Resource/Platform.cpp

        ## PAGES
        ${PAGE_DIR}APage.cpp
        ${PAGE_DIR}Menu/Menu.cpp
        ${PAGE_DIR}Menu/MenuEventReceiver.cpp
        ${PAGE_DIR}Play/Play.cpp
        ${PAGE_DIR}Levels/Levels.cpp
        ${PAGE_DIR}Levels/LevelsEventReceiver.cpp
        ${PAGE_DIR}Settings/Settings.cpp
        ${PAGE_DIR}Settings/SettingsEventReceiver.cpp
        ${PAGE_DIR}Scores/Scores.cpp
	${PAGE_DIR}Scores/ScoresEventReceiver.cpp

        ${FILE_DIR}FileHandler.cpp

        ## GRAPHIC
        ${LIB_3D_DIR}irrlicht.hpp
        ${LIB_3D_DIR}Lib3D.cpp
        ${LIB_3D_DIR}PhysicsEngine/Collisions.cpp
        ${GRAPHIC_DIR}Init.cpp
        ${GRAPHIC_DIR}Blit.cpp
        ${GRAPHIC_DIR}Display.cpp
        ${GRAPHIC_DIR}Accessor.cpp
        ${GRAPHIC_DIR}Misc.cpp
        ${GRAPHIC_DIR}Graphic.hpp
        ${GRAPHIC_DIR}Camera.cpp

	## EVENTS
	${EVENT_DIR}AEventReceiver.cpp

        ${EXCEPTION_DIR}Exception.cpp
        ${EXCEPTION_DIR}FileException.cpp
        ${EXCEPTION_DIR}GraphicException.cpp
        ${EXCEPTION_DIR}DataException.cpp
        ${EXCEPTION_DIR}SyntaxException.cpp

        ## SOUND
        ${SOUND_ENGINE_DIR}SoundEngine.cpp

        )

## Set includes directories
include_directories(
	${SRC_DIR}
	${CORE_DIR}
	${FILE_DIR}
	${LIB_3D_DIR}
	${GRAPHIC_DIR}
	${PHYSICS_ENGINE_DIR}
	${EVENT_DIR}
	${GAME_DIR}
	${GAME_DIR}/GameInfo
	${CHAR_DIR}
	${ACTION_DIR}
	${EXCEPTION_DIR}include
	${SOUND_ENGINE_DIR}

        ${MAP_DIR}
        ${MAP_DIR}Level
        ${MAP_DIR}Resource

        ${PAGE_DIR}
        ${PAGE_DIR}Menu
        ${PAGE_DIR}Play
        ${PAGE_DIR}Levels
        ${PAGE_DIR}Settings
        ${PAGE_DIR}Scores
        ${PAGE_DIR}Credits

        ${PROJECT_SOURCE_DIR}/include/irrklang
)


if(WIN32)
    message(STATUS "Windows detected - Include Irrlicht directory directly")
    include_directories(${PROJECT_SOURCE_DIR}/include)
endif(WIN32)

## Set executable
add_executable(${PROJECT_NAME} ${SRCS})

## Link librairies
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/linux/libIrrKlang.so)
endif(UNIX AND NOT APPLE)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/macos/libirrklang.dylib ${IRRLICHT_LINK_LIBS})
endif(APPLE)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/windows/Irrlicht.lib)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/lib/windows/irrKlang.lib)
endif(WIN32)
