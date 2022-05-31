cmake_minimum_required(VERSION 3.5)

project(CSD_qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.h mainwindow.cpp
        HeadBar.h HeadBar.cpp
        ListWidget.h ListWidget.cpp
        HeadBarEdit.h HeadBarEdit.cpp
)

qt_add_executable(CSD_qt
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(CSD_qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(CSD_qt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(CSD_qt)
