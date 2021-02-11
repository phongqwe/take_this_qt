//
// Created by abc on 2/8/21.
//

#include "ConfigTest.h"
#include "../src/config/Config.h"
#include <QDebug>
#include <memory>
#include <QSettings>

using std::make_shared;
using std::shared_ptr;

void ConfigTest::testInitConfigValue() {
    shared_ptr<QSettings> mockSettings = make_shared<QSettings>();
    Config config(mockSettings);
};
//QTEST_MAIN(ConfigTest)
//#include "ConfigTest.moc"
