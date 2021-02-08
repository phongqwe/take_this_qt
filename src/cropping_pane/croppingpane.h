#ifndef CROPPINGPANE_H
#define CROPPINGPANE_H

#include <QWidget>
#include "../other/CroppingInfo.h"
#include <qdebug.h>
namespace Ui {
class CroppingPane;
}

class CroppingPane : public QWidget
{
    Q_OBJECT
protected:
    void hideEvent(QHideEvent *event) override;

public:
    explicit CroppingPane(QWidget *parent = nullptr);
    ~CroppingPane() override;
    CroppingInfo getCroppingInfo();
    void reset();

private:
    Ui::CroppingPane *ui;

signals:
    void croppingPaneIsHidden();
};

#endif // CROPPINGPANE_H
