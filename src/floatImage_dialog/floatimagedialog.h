#ifndef FLOATIMAGEDIALOG_H
#define FLOATIMAGEDIALOG_H

#include <QDialog>
#include "../other/CroppingInfo.h"
#include <QDebug>
#include <QtWidgets/QMenu>
#include <memory>
#include "../config/Config.h"

using std::shared_ptr;
using std::make_shared;

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
    void alignChildViews(QSize size);

    /**
     * config this view with Config obj
     */
    void config(shared_ptr<Config> config,CroppingInfo croppingInfo);

    void saveImage();

    void copyImageToClipboard();

protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // FLOATIMAGEDIALOG_H
