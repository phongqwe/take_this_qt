cmake_minimum_required(VERSION 3.5)

project(take_this_qt_test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets Test)
find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

#if (NOT CMAKE_PREFIX_PATH)
#    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
#            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
#endif ()

enable_testing(true)

add_test(
        NAME allTest
        COMMAND allTest
)

add_executable(take_this_qt_test
                TestBench.cpp
                TestBench.h)

target_link_libraries(take_this_qt_test PRIVATE Qt${QT_VERSION}::Widgets)
target_link_libraries(take_this_qt_test PRIVATE Qt${QT_VERSION}::Test)
