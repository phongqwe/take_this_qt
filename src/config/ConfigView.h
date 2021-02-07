//
// Created by abc on 2/7/21.
//

#ifndef TAKE_THIS_QT_CONFIGVIEW_H
#define TAKE_THIS_QT_CONFIGVIEW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ConfigView; }
QT_END_NAMESPACE

class ConfigView : public QWidget {
Q_OBJECT

public:
    explicit ConfigView(QWidget *parent = nullptr);

    ~ConfigView() override;

private:
    Ui::ConfigView *ui;
};

#endif //TAKE_THIS_QT_CONFIGVIEW_H
