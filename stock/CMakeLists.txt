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
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        mainwindow.ui
        src/gmobject.h
        src/gmgraphicsview.cpp
        src/gmgraphicsview.h
        src/gmscene.cpp
        src/gmscene.h
        src/gmnode.cpp
        src/gmnode.h
        src/gmedge.cpp
        src/gmedge.h
        src/gmsocket.cpp
        src/gmsocket.h

        src/gmqtgraphicssocket.cpp
        src/gmqtgraphicssocket.h

        src/stockgraphicsscene.h
        src/stockgraphicsscene.cpp
        src/stockgraphicsedge.cpp
        src/stockgraphicsedge.h
        src/stockgraphicsnode.cpp
        src/stockgraphicsnode.h

        src/stockgraphicsedge.h
        src/stockgraphicsedge.cpp
        src/stocksocketinterface.h
        src/stocknodeinterface.h
        src/stockedgeinterface.h
        src/GMSerializable.h
        src/stocksceneinterface.h
        src/stockgraphicscuttingline.cpp
        src/stockgraphicscuttingline.h
        src/gmserializable.h
)

include_directories(./src)
include_directories(./include)
qt5_add_resources(PROJECT_SOURCES resource.qrc)
add_executable(stock    ${PROJECT_SOURCES})
target_link_libraries(stock PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
