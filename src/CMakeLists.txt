qt_add_executable(${PROJECT_NAME}
    ../src/main.cc
   ../src/mainwindow.qml
)

qt_add_qml_module(SWEqml
    URI SWEqt
    VERSION 1.0
    QML_FILES
    mainwindow.qml
    RESOURCES
    ../assets/background.jpg)
    
target_link_libraries(${PROJECT_NAME}  PUBLIC Qt6::Core Qt6::Widgets Qt6::Quick)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

