cmake_minimum_required(VERSION 3.5)

project(genetic_algoirthm LANGUAGES CXX)


set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt@5/5.15.2")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file("input.csv" "input.csv" COPYONLY)

find_package(QT NAMES Qt5 COMPONENTS Widgets PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets PrintSupport REQUIRED)
find_package(Boost 1.72.0 COMPONENTS ALL REQUIRED)
message(${Boost_INCLUDE_DIRS})

set(PROJECT_SOURCES ./src/qcustomplot.h ./src/qcustomplot.cpp
    ./src/chromosome.cpp  ./src/chromosome.h
    ./src/crowdingga.cpp  ./src/crowdingga.h
    ./src/ga_problem.cpp  ./src/ga_problem.h
    ./src/ga_tool.cpp  ./src/ga_tool.h
    ./src/main.cpp  ./src/mainwindow.cpp
    ./src/mainwindow.h ./src/nsga_chromosome.h
    ./src/nsga_chromosome.cpp
    ./src/nsga.h ./src/nsga.cpp
    ./src/selection_method.h ./src/selection_method.cpp
     ./src/csv.h
	)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(./src)
add_executable(genetic_algoirthm ${PROJECT_SOURCES})

target_link_libraries(genetic_algoirthm PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)
target_link_libraries(genetic_algoirthm PRIVATE ${Boost_LIBRARIES})

add_subdirectory(test)
