//
// Created by abc on 2/13/21.
//

#ifndef TAKE_THIS_QT_FLOATIMAGESTATE_H
#define TAKE_THIS_QT_FLOATIMAGESTATE_H
#include <QSize>

class FloatImageState {
public:
    const bool pinned;
    const QSize size;
    bool preventClose = false;
    bool isLeftMouseDown = false;
};


#endif //TAKE_THIS_QT_FLOATIMAGESTATE_H
