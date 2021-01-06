//
// Created by abc on 12/15/20.
//

#ifndef TAKE_THIS_QT_CROPPINGINFO_H
#define TAKE_THIS_QT_CROPPINGINFO_H


#include <QtCore/QPoint>
#include<QSize>
class CroppingInfo {


public:
    static CroppingInfo getInvalidInfo();
    const QPoint position;
    const QSize size;
    CroppingInfo(QPoint position, QSize size);
};


#endif //TAKE_THIS_QT_CROPPINGINFO_H
