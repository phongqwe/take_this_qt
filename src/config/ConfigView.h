//
// Created by abc on 2/8/21.
//

#ifndef TAKE_THIS_QT_CONFIGVIEW_H
#define TAKE_THIS_QT_CONFIGVIEW_H

#include <QDialog>
#include <memory>
#include "Config.h"

using std::shared_ptr;
using std::make_shared;
QT_BEGIN_NAMESPACE
namespace Ui { class ConfigView; }
QT_END_NAMESPACE

/**
 * A view showing the application's configuration
 */
class ConfigView : public QDialog {
Q_OBJECT

public:
    explicit ConfigView(QWidget *parent = nullptr);

    ~ConfigView() override;

protected:
    void showEvent(QShowEvent *event) override;

private:
    Ui::ConfigView *ui;
    shared_ptr<Config> config;

    void okButtonHandler();
    void cancelButtonHandler();
    void loadConfig();
};

#endif //TAKE_THIS_QT_CONFIGVIEW_H
