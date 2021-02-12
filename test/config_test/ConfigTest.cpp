//
// Created by abc on 2/8/21.
//

#include "ConfigTest.h"
#include "../src/config/Config.h"
#include <QDebug>
#include <memory>
#include <QSettings>
#include <QSignalSpy>

using std::make_shared;
using std::shared_ptr;

void ConfigTest::init(){
    shared_ptr<QSettings> mockSettings = make_shared<QSettings>();
    this->stdConfig = std::make_shared<Config>(mockSettings);
}

void ConfigTest::testInitConfigValue() {
    Q_ASSERT(stdConfig->getFloatImageAlwaysOnTopFlag());
    Q_ASSERT(!stdConfig->getClickToCloseFloatImgFlag());
    Q_ASSERT(stdConfig->getFramedFloatImageFlag());
}

void ConfigTest::testEmitSettingChanged() {
    shared_ptr<QSignalSpy> dummy = this->createSpySignal();
    this->stdConfig->emitSettingChanged();
    QCOMPARE(dummy->count(),1);
}

//void ConfigTest::testSetConfigs() {
//    shared_ptr<QSignalSpy> dummy = this->createSpySignal();
//    shared_ptr<Config> c = this->stdConfig;
//
//    bool oldClickToClose = c->getClickToCloseFloatImgFlag();
//    this->stdConfig->setClickToCloseFloatImgFlag(!oldClickToClose);
//    QCOMPARE(dummy->count(),1);
//    Q_ASSERT(this->stdConfig->getClickToCloseFloatImgFlag() == !oldClickToClose);
//
//    bool oldOnTopValue = this->stdConfig->getFloatImageAlwaysOnTopFlag();
//    this->stdConfig->setFloatImageAlwaysOnTopFlag(!oldOnTopValue);
//    QCOMPARE(dummy->count(),2);
//    Q_ASSERT(c->getFloatImageAlwaysOnTopFlag() == !oldOnTopValue);
//
//    bool oldFramedValue = c->getFramedFloatImageFlag();
//    c->setFramedFloatImageFlag(!oldFramedValue);
//    QCOMPARE(dummy->count(),3);
//    Q_ASSERT(c->getFramedFloatImageFlag() == !oldFramedValue);
//
//    int newWait = c->getWaitInMilliSec()*2+1;
//    c->setWaitInMilliSec(newWait);
//    QCOMPARE(dummy->count(),4);
//    QCOMPARE(c->getWaitInMilliSec(),newWait);
//};

shared_ptr<QSignalSpy> ConfigTest::createSpySignal(){
    shared_ptr<QSignalSpy> dummy = make_shared<QSignalSpy>(this->stdConfig.get(), &Config::settingChangedSignal);
    return dummy;
}

void ConfigTest::cleanup() {
    this->stdConfig->getQSettings()->clear();
}

void ConfigTest::cleanupTestCase() {
    this->stdConfig->getQSettings()->clear();
}

void ConfigTest::testWriteConfigToStorage() {
    shared_ptr<Config> c = this->stdConfig;
    bool newClickToClose = !c->getClickToCloseFloatImgFlag();
    bool newOnTopValue = !c->getFloatImageAlwaysOnTopFlag();
    bool newFramedValue = !c->getFramedFloatImageFlag();
    int newWait = c->getWaitInMilliSec()*2+1;

    c->setClickToCloseFloatImgFlag(newClickToClose);
    c->setFloatImageAlwaysOnTopFlag(newOnTopValue);
    c->setFramedFloatImageFlag(newFramedValue);
    c->setWaitInMilliSec(newWait);

    c->writeSettingsToStorage();

    shared_ptr<QSettings> st = c->getQSettings();

    QCOMPARE(st->value(Config::SKEY_CLICK_TO_CLOSE_FLOAT_IMG).toBool(),newClickToClose);
    QCOMPARE(st->value(Config::SKEY_FLOAT_IMG_ALWAYS_ON_TOP).toBool(),newOnTopValue);
    QCOMPARE(st->value(Config::SKEY_FRAMED_FLOAT_IMG).toBool(),newFramedValue);
    QCOMPARE(st->value(Config::SKEY_WAIT_DURATION).toInt(),newWait);
}

void ConfigTest::testReadConfigFromStorage(){
    shared_ptr<Config> c = this->stdConfig;
    shared_ptr<QSettings> st = c->getQSettings();

    bool newClickToClose = !c->getClickToCloseFloatImgFlag();
    bool newOnTopValue = !c->getFloatImageAlwaysOnTopFlag();
    bool newFramedValue = !c->getFramedFloatImageFlag();
    int newWait = c->getWaitInMilliSec()*2+1;

    st->setValue(Config::SKEY_CLICK_TO_CLOSE_FLOAT_IMG, newClickToClose);
    st->setValue(Config::SKEY_FLOAT_IMG_ALWAYS_ON_TOP, newOnTopValue);
    st->setValue(Config::SKEY_FRAMED_FLOAT_IMG,newFramedValue);
    st->setValue(Config::SKEY_WAIT_DURATION,newWait);

    c->loadFromStorage();

    QCOMPARE(c->getClickToCloseFloatImgFlag(), newClickToClose);
    QCOMPARE(c->getFloatImageAlwaysOnTopFlag(), newOnTopValue);
    QCOMPARE(c->getFramedFloatImageFlag(), newFramedValue);
    QCOMPARE(c->getWaitInMilliSec(), newWait);
}

void ConfigTest::testLoadInit() {
    shared_ptr<Config> c = this->stdConfig;

    bool newClickToClose = c->getClickToCloseFloatImgFlag();
    bool newOnTopValue = c->getFloatImageAlwaysOnTopFlag();
    bool newFramedValue = c->getFramedFloatImageFlag();
    int newWait = c->getWaitInMilliSec();

    c->loadFromStorage();

    QCOMPARE(c->getClickToCloseFloatImgFlag(), newClickToClose);
    QCOMPARE(c->getFloatImageAlwaysOnTopFlag(), newOnTopValue);
    QCOMPARE(c->getFramedFloatImageFlag(), newFramedValue);
    QCOMPARE(c->getWaitInMilliSec(), newWait);
}
//QTEST_MAIN(ConfigTest)
//#include "ConfigTest.moc"
