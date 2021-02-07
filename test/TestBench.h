//
// Created by abc on 2/7/21.
//

#ifndef TAKE_THIS_QT_TESTBENCH_H
#define TAKE_THIS_QT_TESTBENCH_H

#include <QtTest/QtTest>

class TestBench : public QObject
{
    Q_OBJECT
private slots:
            void testToUpper();
};

#endif //TAKE_THIS_QT_TESTBENCH_H
