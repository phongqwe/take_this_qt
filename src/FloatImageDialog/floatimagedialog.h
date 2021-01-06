#ifndef FLOATIMAGEDIALOG_H
#define FLOATIMAGEDIALOG_H

#include <QDialog>
#include <src/Other/CroppingInfo.h>
#include <QDebug>
#include <QtWidgets/QMenu>

namespace Ui {
class FloatImageDialog;
}
//use a QLabel to show image: imageLabel->setPixmap(QPixmap::fromImage(image));
class FloatImageDialog : public QDialog
{
    Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void closeEvent(QCloseEvent *event) override;

public:
    explicit FloatImageDialog(CroppingInfo croppingInfo, QPixmap image,QWidget *parent = nullptr);
    ~FloatImageDialog();

private:
    Ui::FloatImageDialog *ui;
    bool preventClose = false;
    bool isLeftMouseDown = false;
    int xDistanceBetweenCornerAndMouse = 0;
    int yDistanceBetweenCornerAndMouse = 0;
    QPixmap pixmap;
    QMenu* contextMenu = nullptr;
    QAction* saveAction = nullptr;
    QAction* copyToClipboardAction = nullptr;

    void showContextMenu(const QPoint& menuPosition);
    void setupContextMenu();
};

#endif // FLOATIMAGEDIALOG_H
