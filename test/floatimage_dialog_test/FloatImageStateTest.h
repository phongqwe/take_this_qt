//
// Created by abc on 2/14/21.
//

#ifndef TAKE_THIS_QT_FLOATIMAGESTATETEST_H
#define TAKE_THIS_QT_FLOATIMAGESTATETEST_H
#include <QtTest/QtTest>
#include <memory>
#include <QSignalSpy>
#include "../src/floatImage_dialog/FloatImageState.h"

class FloatImageStateTest:public QObject {
    Q_OBJECT
private:
    FloatImageState state;
private slots:
    void init();
    void testFlipPin();
};


#endif //TAKE_THIS_QT_FLOATIMAGESTATETEST_H
