//
// Created by abc on 2/14/21.
//

#include "FloatImageStateTest.h"

void FloatImageStateTest::init() {
    this->state = FloatImageState(true);
}
void FloatImageStateTest::testFlipPin(){
    FloatImageState newState = this->state.flipPin();
    QCOMPARE(newState.getPinned(),!this->state.getPinned());
}