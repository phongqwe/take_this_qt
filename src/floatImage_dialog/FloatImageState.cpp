//
// Created by abc on 2/13/21.
//

#include "FloatImageState.h"

FloatImageState::FloatImageState(bool pinned):pinned(pinned) {}

FloatImageState FloatImageState::pin() {
    return FloatImageState(true);
}

FloatImageState FloatImageState::unPin() {
    return FloatImageState(false);
}

FloatImageState FloatImageState::flipPin() {
    return FloatImageState(!this->pinned);
}

bool FloatImageState::getPinned() {
    return this->pinned;
}



