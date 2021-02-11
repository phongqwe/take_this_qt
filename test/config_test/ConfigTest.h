//
// Created by abc on 2/8/21.
//

#ifndef TAKE_THIS_QT_CONFIGTEST_H
#define TAKE_THIS_QT_CONFIGTEST_H
#include <QtTest/QtTest>

class ConfigTest : public QObject{
    Q_OBJECT
private slots:
    void testInitConfigValue();
};


#endif //TAKE_THIS_QT_CONFIGTEST_H
