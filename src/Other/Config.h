//
// Created by abc on 1/2/21.
//

#ifndef TAKE_THIS_QT_CONFIG_H
#define TAKE_THIS_QT_CONFIG_H

#include <memory>


class Config {
private:
    static std::shared_ptr<Config> instance ;

    int waitInMilliSec=500;
    bool floatImageAlwaysOnTop = true;
    bool enableTitleBarOnFloatImage = true;

public:

    static std::shared_ptr<Config> getInstance();
    void setWaitInMilliSec(int newValue);
    int getWaitInMilliSec();
    bool getFloatImageAlwaysOnTopFlag();
    void setFloatImageAlwaysOnTopFlag(bool newFlag);
};


#endif //TAKE_THIS_QT_CONFIG_H
