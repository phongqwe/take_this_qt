//
// Created by abc on 1/2/21.
//

#ifndef TAKE_THIS_QT_CONFIG_H
#define TAKE_THIS_QT_CONFIG_H

#include <memory>
#include <QString>
#include <QSettings>
#include <QObject>
#include <QApplication>
using std::shared_ptr;
using std::make_shared;
class Config : public QObject{
    Q_OBJECT
private:

    static std::shared_ptr<Config> instance ;
    int waitInMilliSec=500;
    bool floatImgAlwaysOnTop=true;
    bool framedFloatImg=true;
    bool clickToCloseFloatImg=false;
    shared_ptr<QSettings> settings;

public:
    static const QString SKEY_FRAMED_FLOAT_IMG;
    static const QString SKEY_WAIT_DURATION;
    static const QString SKEY_FLOAT_IMG_ALWAYS_ON_TOP;
    static const QString SKEY_CLICK_TO_CLOSE_FLOAT_IMG;

    explicit Config(shared_ptr<QSettings> settings);
    ~Config() override;

    shared_ptr<QSettings> getQSettings();

    /**
     * load the setting from storage
     */
    void loadFromStorage();

    /**
     * reload the setting from storage
     */
    void reloadFromStorage();

    /**
     * emit the setting to those that subscribe to this config
     */
    void emitSettingChanged();

    /**
     * write setting to storage
     */
    void writeSettingsToStorage();
    static std::shared_ptr<Config> getInstance();

    int getWaitInMilliSec() const;
    void setWaitInMilliSec(int newValue);

    bool getFloatImageAlwaysOnTopFlag() const;
    void setFloatImageAlwaysOnTopFlag(bool newVal);

    bool getFramedFloatImageFlag() const;
    void setFramedFloatImageFlag(bool newVal);

    bool getClickToCloseFloatImgFlag() const;
    void setClickToCloseFloatImgFlag(bool newVal);
signals:
    void settingChangedSignal(std::shared_ptr<Config> config);
};


#endif //TAKE_THIS_QT_CONFIG_H
