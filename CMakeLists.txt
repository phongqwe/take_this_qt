cmake_minimum_required(VERSION 3.5)

project(take_this_qt LANGUAGES CXX)

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

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

add_executable(take_this_qt
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        src/transparent_dialog/transparentdialog.cpp
        src/transparent_dialog/transparentdialog.h
        src/transparent_dialog/transparentdialog.ui
        src/other/CroppingInfo.cpp
        src/other/CroppingInfo.h
        src/floatImage_dialog/floatimagedialog.cpp
        src/floatImage_dialog/floatimagedialog.h
        src/floatImage_dialog/floatimagedialog.ui
        src/cropping_pane/croppingpane.cpp
        src/cropping_pane/croppingpane.ui
        src/cropping_pane/croppingpane.h
        src/config/Config.cpp
        src/config/Config.h
        resources/resources.qrc


        src/config/ConfigView.cpp src/config/ConfigView.h src/config/configview.ui)

target_link_libraries(take_this_qt PRIVATE Qt${QT_VERSION}::Widgets)
target_link_libraries(take_this_qt PRIVATE Qt${QT_VERSION}::Test)
add_subdirectory(test)