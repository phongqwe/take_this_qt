//
// Created by abc on 1/2/21.
//

#include "Config.h"

const QString Config::SKEY_FRAMED_FLOAT_IMG="SKEY_FRAMED_FLOAT_IMG";
const QString Config::SKEY_WAIT_DURATION="SKEY_WAIT_DURATION";
const QString Config::SKEY_FLOAT_IMG_ALWAYS_ON_TOP="SKEY_FLOAT_IMG_ALWAYS_ON_TOP";
const QString Config::SKEY_CLICK_TO_CLOSE_FLOAT_IMG="SKEY_CLICK_TO_CLOSE_FLOAT_IMG";

std::shared_ptr<Config> Config::instance = nullptr;

std::shared_ptr<Config> Config::getInstance() {
    if (Config::instance == nullptr) {
        Config::instance = make_shared<Config>(make_shared<QSettings>(QApplication::instance()));
    }
    return Config::instance;
}

void Config::loadFromStorage() {
    this->setFramedFloatImageFlag(
            this->settings->value(Config::SKEY_FRAMED_FLOAT_IMG, this->getFramedFloatImageFlag()).toBool());
    this->setFloatImageAlwaysOnTopFlag(
            this->settings->value(Config::SKEY_FLOAT_IMG_ALWAYS_ON_TOP, this->getFloatImageAlwaysOnTopFlag()).toBool());
    this->setWaitInMilliSec(this->settings->value(Config::SKEY_WAIT_DURATION, this->getWaitInMilliSec()).toInt());
    this->setClickToCloseFloatImgFlag(
            this->settings->value(Config::SKEY_CLICK_TO_CLOSE_FLOAT_IMG, this->getClickToCloseFloatImgFlag()).toBool());
}

void Config::reloadFromStorage() {
    this->loadFromStorage();
}

void Config::setWaitInMilliSec(int newValue) {
    this->waitInMilliSec = newValue;
}

int Config::getWaitInMilliSec() const {
    return this->waitInMilliSec;
}

bool Config::getFloatImageAlwaysOnTopFlag() const {
    return this->floatImgAlwaysOnTop;
}

void Config::setFloatImageAlwaysOnTopFlag(bool newFlag) {
    this->floatImgAlwaysOnTop = newFlag;
//    this->emitSettingChanged();
}

bool Config::getFramedFloatImageFlag() const{
    return this->framedFloatImg;
}

void Config::setFramedFloatImageFlag(bool newVal) {
    this->framedFloatImg = newVal;
//    this->emitSettingChanged();
}

bool Config::getClickToCloseFloatImgFlag() const {
    return this->clickToCloseFloatImg;
}

void Config::setClickToCloseFloatImgFlag(bool newVal) {
    this->clickToCloseFloatImg = newVal;
//    this->emitSettingChanged();
}

void Config::emitSettingChanged() {
    Q_EMIT Config::settingChangedSignal(Config::getInstance());
}

void Config::writeSettingsToStorage() {
    this->settings->setValue(
            Config::SKEY_FRAMED_FLOAT_IMG,
            this->getFramedFloatImageFlag());
    this->settings->setValue(
            Config::SKEY_WAIT_DURATION,
            this->getWaitInMilliSec());
    this->settings->setValue(
            Config::SKEY_CLICK_TO_CLOSE_FLOAT_IMG,
            this->getClickToCloseFloatImgFlag());
    this->settings->setValue(
            Config::SKEY_FLOAT_IMG_ALWAYS_ON_TOP,
            this->getFloatImageAlwaysOnTopFlag());

}

Config::Config(shared_ptr<QSettings> settings) {
    this->settings = settings;
}

Config::~Config() {

}

shared_ptr<QSettings> Config::getQSettings() {
    return this->settings;
}
