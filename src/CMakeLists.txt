qt_add_executable(${PROJECT_NAME}
    ../src/main.cc
    ../src/game.cc
    ../src/game.h
    
  
)

qt_add_resources({${PROJECT_NAME} ../resources.qrc})

target_sources(${PROJECT_NAME} PRIVATE ../resources.qrc)

    
target_link_libraries(${PROJECT_NAME}  PUBLIC Qt6::Core Qt6::Widgets Qt6::Quick Qt6::Svg Qt6::SvgWidgets)
target_include_directories(${PROJECT_NAME} PUBLIC  ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2MIXER_INCLUDE_DIRS} )
target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2MIXER_LIBRARIES})

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

