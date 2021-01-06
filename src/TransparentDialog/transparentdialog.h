#ifndef TRANSPARENTDIALOG_H
#define TRANSPARENTDIALOG_H

#include <QDialog>
#include <src/CroppingPane/croppingpane.h>
#include "src/Other/CroppingInfo.h"
namespace Ui {
class TransparentDialog;
}

class TransparentDialog : public QDialog
{
    Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void hideEvent(QHideEvent *event) override;

    void closeEvent(QCloseEvent *event) override;

private:
    const qreal opacity = 0.4;
public:
    explicit TransparentDialog(QWidget *parent = nullptr);
    ~TransparentDialog();
    CroppingInfo getCroppingInfo();
    bool allowCropping();
    void resetCroppingPane();
private:
    Ui::TransparentDialog *ui;
    QPoint anchor;
    CroppingPane* croppingPane = nullptr;



signals:
    void readyToTakeScreenshot(CroppingInfo croppingInfo);
};

#endif // TRANSPARENTDIALOG_H
