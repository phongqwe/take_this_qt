//
// Created by abc on 2/8/21.
//

#include <QtTest>
#include "config_test/ConfigTest.h"
int main(int argc, char** argv)
{
    int status = 0;
    {
        ConfigTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
//    {
//        TestClassB tc;
//        status |= QTest::qExec(&tc, argc, argv);
//    }
    return status;
}
