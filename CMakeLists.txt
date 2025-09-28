cmake_minimum_required(VERSION 3.20)

project(SWEqt)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2MIXER REQUIRED SDL2_mixer)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

add_executable(
    ${PROJECT_NAME}
    src/main.cc
)

target_include_directories(SWEqt PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2MIXER_INCLUDE_DIRS}
)

target_link_libraries(SWEqt
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2MIXER_LIBRARIES}
)

target_link_libraries(SWEqt Qt5::Core Qt5::Widgets)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)