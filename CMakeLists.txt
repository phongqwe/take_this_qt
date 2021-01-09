cmake_minimum_required(VERSION 3.5)

project(take_this_qt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

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
