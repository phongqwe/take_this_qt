//
// Created by abc on 1/2/21.
//

#ifndef TAKE_THIS_QT_CONFIG_H
#define TAKE_THIS_QT_CONFIG_H

#include <memory>
#include <QString>
#include <QSettings>
#include <QObject>
class Config : public QObject{
    Q_OBJECT
private:

    static std::shared_ptr<Config> instance ;
    int waitInMilliSec=500;
    bool floatImgAlwaysOnTop=true;
    bool framedFloatImg=true;
    bool clickToCloseFloatImg=true;
    QSettings settings;

public:
    static const QString SKEY_FRAMED_FLOAT_IMG;
    static const QString SKEY_WAIT_DURATION;
    static const QString SKEY_FLOAT_IMG_ALWAYS_ON_TOP;
    static const QString SKEY_CLICK_TO_CLOSE_FLOAT_IMG;

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
    void emitSetting();

    /**
     * write setting to storage
     */
    void writeSettingsToStorage();
    static std::shared_ptr<Config> getInstance();

    void setWaitInMilliSec(int newValue);
    int getWaitInMilliSec();

    bool getFloatImageAlwaysOnTopFlag();
    void setFloatImageAlwaysOnTopFlag(bool newVal);

    bool getFramedFloatImageFlag();
    void setFramedFloatImageFlag(bool newVal);

    bool getClickToCloseFloatImgFlag();
    void setClickToCloseFloatImgFlag(bool newVal);
signals:
    void settingChangedSignal(std::shared_ptr<Config> config);
};


#endif //TAKE_THIS_QT_CONFIG_H
