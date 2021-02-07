//
// Created by abc on 2/7/21.
//

#include "TestBench.h"
#include "../src/mainwindow.h"
#include <iostream>
#include <QString>
#include <QDebug>
void TestBench::testToUpper()
{
    int x = 12;
    bool xb = (bool) x;
    if(xb){
        std::cout<<"ZAWARUDO"<<std::endl;
    }

    QString FRAMED_FLOAT_IMG("FRAMED_FLOAT_IMG");
    qInfo() << FRAMED_FLOAT_IMG;

}
QTEST_MAIN(TestBench)
#include "TestBench.moc"