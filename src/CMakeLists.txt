include_directories(${CMAKE_BINARY_DIR})
add_library(take_this_qt_lib STATIC
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        transparent_dialog/transparentdialog.cpp
        transparent_dialog/transparentdialog.h
        transparent_dialog/transparentdialog.ui
        other/CroppingInfo.cpp
        other/CroppingInfo.h
        floatImage_dialog/floatimagedialog.cpp
        floatImage_dialog/floatimagedialog.h
        floatImage_dialog/floatimagedialog.ui
        cropping_pane/croppingpane.cpp
        cropping_pane/croppingpane.ui
        cropping_pane/croppingpane.h
        config/Config.cpp
        config/Config.h
        config/ConfigView.cpp
        config/ConfigView.h
        config/ConfigView.ui
        )

target_link_libraries(take_this_qt_lib PUBLIC Qt${QT_VERSION}::Widgets)