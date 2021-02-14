//
// Created by abc on 2/13/21.
//

#ifndef TAKE_THIS_QT_FLOATIMAGESTATE_H
#define TAKE_THIS_QT_FLOATIMAGESTATE_H
#include <QSize>
#include "../other/CroppingInfo.h"

/**
 * Encapsulation that hold the state of a FloatImageDialog
 * TODO port state variables in FloatImageDialog to this class
 */
class FloatImageState {
private:
    bool pinned;
public:

    explicit FloatImageState(bool pinned = false);

    bool getPinned();

//    const QSize size;
//    const bool preventClose;
//    const bool isLeftMouseDown;
//    const CroppingInfo originalCroppingInfo;
//    const QPoint position;

    FloatImageState pin();
    FloatImageState unPin();
    FloatImageState flipPin();
//    void resize(QSize newSize);
//    void moveTo(QPoint newPosition);

//    void update(FloatImageDialog floatImgDialog);

};


#endif //TAKE_THIS_QT_FLOATIMAGESTATE_H
