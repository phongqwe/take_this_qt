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

/**
 * State class for ConfigView.
 * Handle storing configuration info, read, and write info to storage
 */
class Config : public QObject{
    Q_OBJECT
private:

    static std::shared_ptr<Config> instance ;
    int waitInMilliSec=500;
    bool floatImgAlwaysOnTop=true;
    bool showTitleBarOnFloatImg=false;
    bool clickToCloseFloatImg=false;
    bool enableResizeFloatImg = false;
    bool showUiFloatImg = false;
    shared_ptr<QSettings> settings;

public:
    static const QString SKEY_SHOW_TITLE_BAR_ON_FLOAT_IMG;
    static const QString SKEY_WAIT_DURATION;
    static const QString SKEY_FLOAT_IMG_ALWAYS_ON_TOP;
    static const QString SKEY_CLICK_TO_CLOSE_FLOAT_IMG;
    static const QString SKEY_ENABLE_RESIZE_FLOAT_IMG;
    static const QString SKEY_SHOW_UI_FLOAT_IMG;

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
    static shared_ptr<Config> getInstance();

    int getWaitInMilliSec() const;
    void setWaitInMilliSec(int newValue);

    bool getFloatImageAlwaysOnTopFlag() const;
    void setFloatImageAlwaysOnTopFlag(bool newVal);

    bool getShowTitleBarOnFloatImage() const;
    void setShowTitleBarOnFloatImage(bool newVal);

    bool getClickToCloseFloatImgFlag() const;
    void setClickToCloseFloatImgFlag(bool newVal);

    bool getEnableResizeFloatImg() const;
    void setEnableResizeFloatImg(bool newVal);

    bool getShowUiFloatImg() const;
    void setShowUiFloatImg(bool newVal);

signals:
    void settingChangedSignal(shared_ptr<Config> config);
};


#endif //TAKE_THIS_QT_CONFIG_H
