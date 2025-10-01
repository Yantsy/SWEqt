qt_add_executable(${PROJECT_NAME}
    ../src/main.cc
  
)


    
target_link_libraries(${PROJECT_NAME}  PUBLIC Qt6::Core Qt6::Widgets Qt6::Quick)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

