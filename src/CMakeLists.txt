qt_add_executable(${PROJECT_NAME}
    ../src/main.cc
    ../src/SDL2Widget.cc
  
)


    
target_link_libraries(${PROJECT_NAME}  PUBLIC Qt6::Core Qt6::Widgets Qt6::Quick)
target_include_directories(${PROJECT_NAME} PUBLIC  ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2MIXER_INCLUDE_DIRS} )
target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2MIXER_LIBRARIES})

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

