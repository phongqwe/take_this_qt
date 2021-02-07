//
// Created by abc on 12/15/20.
//

#include "CroppingInfo.h"

CroppingInfo::CroppingInfo(QPoint position, QSize size)
        : position(position), size(size) {
}

CroppingInfo CroppingInfo::getInvalidInfo() {
    return CroppingInfo(QPoint(-1,-1), QSize(-1,-1));
}
