include_directories(${CMAKE_BINARY_DIR})
add_test(
        NAME allTest
        COMMAND take_this_qt_test
)

add_executable(take_this_qt_test
        TestBench.cpp
        TestBench.h
        config_test/ConfigTest.cpp
        config_test/ConfigTest.h
        testMain.cpp
        floatimage_dialog_test/FloatImageStateTest.cpp floatimage_dialog_test/FloatImageStateTest.h)

target_link_libraries(take_this_qt_test PRIVATE Qt${QT_VERSION}::Widgets)
target_link_libraries(take_this_qt_test PRIVATE Qt${QT_VERSION}::Test)
target_link_libraries(take_this_qt_test PRIVATE take_this_qt_lib)
