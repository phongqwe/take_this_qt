cmake_minimum_required(VERSION 3.5)

project(take_this_qt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Clion won't work without the below 3 lines #
set(QT_VERSION_MAJOR 5)
set(CMAKE_PREFIX_PATH "/home/abc/Applications/Qt/5.9.9/gcc_64")
include_directories(${CMAKE_BINARY_DIR})
#########

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

#FIND_PACKAGE(PkgConfig REQUIRED)
#PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
#INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
#LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
#ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

add_executable(take_this_qt
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        src/TransparentDialog/transparentdialog.cpp
        src/TransparentDialog/transparentdialog.h
        src/TransparentDialog/transparentdialog.ui
        src/Other/CroppingInfo.cpp
        src/Other/CroppingInfo.h
        src/FloatImageDialog/floatimagedialog.cpp
        src/FloatImageDialog/floatimagedialog.h
        src/FloatImageDialog/floatimagedialog.ui
        src/CroppingPane/croppingpane.cpp
        src/CroppingPane/croppingpane.ui
        src/CroppingPane/croppingpane.h
        src/Other/Config.cpp
        src/Other/Config.h
        resources/resources.qrc)

target_link_libraries(take_this_qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
