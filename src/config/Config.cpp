//
// Created by abc on 1/2/21.
//

#include "Config.h"

const QString Config::SKEY_SHOW_TITLE_BAR_ON_FLOAT_IMG="SKEY_FRAMED_FLOAT_IMG";
const QString Config::SKEY_WAIT_DURATION="SKEY_WAIT_DURATION";
const QString Config::SKEY_FLOAT_IMG_ALWAYS_ON_TOP="SKEY_FLOAT_IMG_ALWAYS_ON_TOP";
const QString Config::SKEY_CLICK_TO_CLOSE_FLOAT_IMG="SKEY_CLICK_TO_CLOSE_FLOAT_IMG";
const QString Config::SKEY_ENABLE_RESIZE_FLOAT_IMG = "SKEY_ENABLE_RESIZE_FLOAT_IMG";
const QString Config::SKEY_SHOW_UI_FLOAT_IMG = "SKEY_SHOW_UI_FLOAT_IMG";
std::shared_ptr<Config> Config::instance = nullptr;

std::shared_ptr<Config> Config::getInstance() {
    if (Config::instance == nullptr) {
        Config::instance = make_shared<Config>(make_shared<QSettings>(QApplication::instance()));
    }
    return Config::instance;
}

void Config::loadFromStorage() {
    this->setShowTitleBarOnFloatImage(
            this->settings->value(Config::SKEY_SHOW_TITLE_BAR_ON_FLOAT_IMG,
                                  this->getShowTitleBarOnFloatImage()).toBool());
    this->setFloatImageAlwaysOnTopFlag(
            this->settings->value(Config::SKEY_FLOAT_IMG_ALWAYS_ON_TOP, this->getFloatImageAlwaysOnTopFlag()).toBool());

    this->setWaitInMilliSec(this->settings->value(Config::SKEY_WAIT_DURATION, this->getWaitInMilliSec()).toInt());

    this->setClickToCloseFloatImgFlag(
            this->settings->value(Config::SKEY_CLICK_TO_CLOSE_FLOAT_IMG, this->getClickToCloseFloatImgFlag()).toBool());

    this->setEnableResizeFloatImg(
            this->settings->value(Config::SKEY_ENABLE_RESIZE_FLOAT_IMG,this->getEnableResizeFloatImg()).toBool());

    this->setShowUiFloatImg(
            this->settings->value(Config::SKEY_SHOW_UI_FLOAT_IMG, this->getShowUiFloatImg()).toBool());

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

bool Config::getShowTitleBarOnFloatImage() const{
    return this->showTitleBarOnFloatImg;
}

void Config::setShowTitleBarOnFloatImage(bool newVal) {
    this->showTitleBarOnFloatImg = newVal;
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
            Config::SKEY_SHOW_TITLE_BAR_ON_FLOAT_IMG,
            this->getShowTitleBarOnFloatImage());
    this->settings->setValue(
            Config::SKEY_WAIT_DURATION,
            this->getWaitInMilliSec());
    this->settings->setValue(
            Config::SKEY_CLICK_TO_CLOSE_FLOAT_IMG,
            this->getClickToCloseFloatImgFlag());
    this->settings->setValue(
            Config::SKEY_FLOAT_IMG_ALWAYS_ON_TOP,
            this->getFloatImageAlwaysOnTopFlag());

    this->settings->setValue(
            Config::SKEY_ENABLE_RESIZE_FLOAT_IMG,
            this->getEnableResizeFloatImg());

    this->settings->setValue(
            Config::SKEY_SHOW_UI_FLOAT_IMG,
            this->getShowUiFloatImg());
}
bool Config::getEnableResizeFloatImg() const{
    return this->enableResizeFloatImg;
}
void Config::setEnableResizeFloatImg(bool newVal){
    this->enableResizeFloatImg = newVal;
}

bool Config::getShowUiFloatImg() const{
    return this->showUiFloatImg;
}
void Config::setShowUiFloatImg(bool newVal){
    this->showUiFloatImg = newVal;
}


Config::Config(shared_ptr<QSettings> settings) {
    this->settings = settings;
}

Config::~Config() {}

shared_ptr<QSettings> Config::getQSettings() {
    return this->settings;
}

