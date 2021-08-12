cmake_minimum_required(VERSION 3.5)

project(stock LANGUAGES CXX)

set(CMAKE_PREFIX_PATH /usr/local/Cellar/qt@5/5.15.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
file(COPY "resource" DESTINATION ".")
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        stockgraphicsview.cpp
        stockgraphicsview.h
        stockgraphicsscene.h
        stockgraphicsscene.cpp
        stockgraphicsedge.cpp
        stockgraphicsedge.h
        stockgraphicsnode.cpp
        stockgraphicsnode.h
        stockgraphicssocket.cpp
        stockgraphicssocket.h
        stockgraphicsedge.h
        stockgraphicsedge.cpp

        stocknode.cpp
        stocknode.h
        stocksocket.cpp
        stocksocket.h
        stocksocketinterface.h
        stocknodeinterface.h
        stockedgeinterface.h
        stockedge.cpp
        stockedge.h
        stockscene.cpp
        stockscene.h
        stocksceneinterface.h

        stockgraphicscuttingline.cpp
        stockgraphicscuttingline.h
)

qt5_add_resources(PROJECT_SOURCES resource.qrc)
add_executable(stock           ${PROJECT_SOURCES})

target_link_libraries(stock PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
