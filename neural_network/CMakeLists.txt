cmake_minimum_required(VERSION 3.5)

project(untitled LANGUAGES CXX)

set(CMAKE_PREFIX_PATH /usr/local/Cellar/qt@5/5.15.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt5 COMPONENTS Widgets PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets PrintSupport REQUIRED)
find_package(Boost 1.72.0 COMPONENTS locale random chrono REQUIRED)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        myitem.cpp
        myitem.h
        circle.cpp
        circle.h
        neuralnetwork.cpp
        neuralnetwork.h
        line.cpp
        line.h
        dialog.cpp
        dialog.h
        dialog.ui
)
add_executable(untitled ${PROJECT_SOURCES})

#target_include_directories(untitled PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)
