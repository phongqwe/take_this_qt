cmake_minimum_required(VERSION 3.5)

project(take_this_qt LANGUAGES CXX)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

enable_testing()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets Test)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
include_directories(${CMAKE_BINARY_DIR})

add_subdirectory(src)
add_subdirectory(test)

add_executable(take_this_qt
        main.cpp
        resources/resources.qrc)

target_link_libraries(take_this_qt PRIVATE take_this_qt_lib)
