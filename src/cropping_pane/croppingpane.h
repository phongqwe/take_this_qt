#ifndef CROPPINGPANE_H
#define CROPPINGPANE_H

#include <QWidget>
#include "../other/CroppingInfo.h"
#include <qdebug.h>
namespace Ui {
class CroppingPane;
}

/**
 * A view for specifying the segment of the screen to take screenshot
 * Displayed at the mouse's position when user hold down left-click on TransparentDialog
 */
class CroppingPane : public QWidget
{
    Q_OBJECT
protected:
    void hideEvent(QHideEvent *event) override;

public:
    explicit CroppingPane(QWidget *parent = nullptr);
    ~CroppingPane() override;
    /**
     * extract cropping info from this pane
     * @return
     */
    CroppingInfo getCroppingInfo();

    /**
     * resize this -> 0*0, then hide it
     */
    void reset();

private:
    Ui::CroppingPane *ui;

signals:
    void croppingPaneIsHidden();
};

#endif // CROPPINGPANE_H
