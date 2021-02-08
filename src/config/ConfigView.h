//
// Created by abc on 2/8/21.
//

#ifndef TAKE_THIS_QT_CONFIGVIEW_H
#define TAKE_THIS_QT_CONFIGVIEW_H

#include <QDialog>
#include <memory>
#include "Config.h"

using std::shared_ptr;
QT_BEGIN_NAMESPACE
namespace Ui { class ConfigView; }
QT_END_NAMESPACE

class ConfigView : public QDialog {
Q_OBJECT

public:
    explicit ConfigView(QWidget *parent = nullptr);

    ~ConfigView() override;

private:
    Ui::ConfigView *ui;
    shared_ptr<Config> config;

    void okButtonHandler();
    void cancelButtonHandler();
};

#endif //TAKE_THIS_QT_CONFIGVIEW_H
