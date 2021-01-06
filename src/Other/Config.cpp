//
// Created by abc on 1/2/21.
//

#include "Config.h"

void Config::setWaitInMilliSec(int newValue) {
    this->waitInMilliSec = newValue;
}

int Config::getWaitInMilliSec() {
    return this->waitInMilliSec;
}

bool Config::getFloatImageAlwaysOnTopFlag() {
    return this->floatImageAlwaysOnTop;
}

void Config::setFloatImageAlwaysOnTopFlag(bool newFlag) {
    this->floatImageAlwaysOnTop = newFlag;
}
std::shared_ptr<Config> Config::instance = nullptr;
std::shared_ptr<Config> Config::getInstance() {
    if(Config::instance == nullptr){
        Config::instance = std::make_shared<Config>();
    }
    return Config::instance;
}
