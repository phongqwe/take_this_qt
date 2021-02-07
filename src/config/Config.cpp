//
// Created by abc on 1/2/21.
//

#include "Config.h"

const QString Config::SKEY_FRAMED_FLOAT_IMG = "FRAMED_FLOAT_IMG";


std::shared_ptr<Config> Config::instance = nullptr;

std::shared_ptr<Config> Config::getInstance() {
    if (Config::instance == nullptr) {
        Config::instance = std::make_shared<Config>();
    }
    return Config::instance;
}

void Config::loadFromStorage() {
    this->setFramedFloatImageFlag(this->settings.value(Config::SKEY_FRAMED_FLOAT_IMG, this->getFramedFloatImageFlag()).toBool());
    this->setFloatImageAlwaysOnTopFlag(this->settings.value(Config::SKEY_FLOAT_IMG_ALWAYS_ON_TOP, this->getFloatImageAlwaysOnTopFlag()).toBool());
    this->setWaitInMilliSec(this->settings.value(Config::SKEY_WAIT_DURATION, this->getWaitInMilliSec()).toInt());
    this->setClickToCloseFloatImgFlag(this->settings.value(Config::SKEY_CLICK_TO_CLOSE_FLOAT_IMG,this->getClickToCloseFloatImgFlag()).toBool());


}

void Config::reloadFromStorage() {
    this->loadFromStorage();
}

void Config::setWaitInMilliSec(int newValue) {
    this->waitInMilliSec = newValue;
    this->emitSetting();
}

int Config::getWaitInMilliSec() {
    return this->waitInMilliSec;
}

bool Config::getFloatImageAlwaysOnTopFlag() {
    return this->floatImgAlwaysOnTop;
}

void Config::setFloatImageAlwaysOnTopFlag(bool newFlag) {
    this->floatImgAlwaysOnTop = newFlag;
}

bool Config::getFramedFloatImageFlag() {
    return this->framedFloatImg;
}

void Config::setFramedFloatImageFlag(bool newVal) {
    this->framedFloatImg = newVal;
    this->emitSetting();
}

bool Config::getClickToCloseFloatImgFlag() {
    return this->clickToCloseFloatImg;
}

void Config::setClickToCloseFloatImgFlag(bool newVal) {
    this->clickToCloseFloatImg = newVal;
    this->emitSetting();
}

void Config::emitSetting() {
    Q_EMIT Config::settingChangedSignal(Config::getInstance());
}
