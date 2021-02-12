//
// Created by abc on 2/8/21.
//

#ifndef TAKE_THIS_QT_CONFIGTEST_H
#define TAKE_THIS_QT_CONFIGTEST_H
#include <QtTest/QtTest>
#include "../src/config/Config.h"
#include <memory>
#include <QSignalSpy>
using std::shared_ptr;
class ConfigTest : public QObject{
    Q_OBJECT
private:
    shared_ptr<Config> stdConfig;
    shared_ptr<QSignalSpy> createSpySignal();
private slots:

    void init();
    void cleanup();
    void cleanupTestCase();
    /**
     * Test init value of Config obj
     */
    void testInitConfigValue();

    /**
     * Test that setting changed signal is emitted when calling emitSettingChanged() function
     */
    void testEmitSettingChanged();
    void testWriteConfigToStorage();
    void testReadConfigFromStorage();
    void testLoadInit();
};


#endif //TAKE_THIS_QT_CONFIGTEST_H
