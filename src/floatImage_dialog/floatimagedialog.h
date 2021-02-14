#ifndef FLOATIMAGEDIALOG_H
#define FLOATIMAGEDIALOG_H

#include <QDialog>
#include "../other/CroppingInfo.h"
#include <QDebug>
#include <QtWidgets/QMenu>
#include <memory>
#include "../config/Config.h"
//#include "FloatImageState.h"
#include "FloatImageState.h"
#include <QWindow>
using std::shared_ptr;
using std::make_shared;

namespace Ui {
    class FloatImageDialog;
}
/**
 * A window showing a caputured image, also  handle saving the image, copying it image to clipboard.
 */
class FloatImageDialog : public QDialog {
Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void closeEvent(QCloseEvent *event) override;

public:

    explicit FloatImageDialog(shared_ptr<FloatImageState> state, CroppingInfo croppingInfo, shared_ptr<QPixmap> image, QWidget *parent);

    explicit FloatImageDialog(CroppingInfo croppingInfo, shared_ptr<QPixmap> image, QWidget *parent = nullptr);

    ~FloatImageDialog();
    void loadState(shared_ptr<FloatImageState> state);

private:
    shared_ptr<FloatImageState> state;
    Ui::FloatImageDialog *ui;
    /**
     * preventClose = true => cannot click-to-close this image
     */
    bool preventClose = false;
    bool isLeftMouseDown = false;
    int xDistanceBetweenCornerAndMouse = 0;
    int yDistanceBetweenCornerAndMouse = 0;
    shared_ptr<QPixmap> pixmap;
    QMenu *contextMenu = nullptr;
    QAction *saveAction = nullptr;
    QAction *copyToClipboardAction = nullptr;
    CroppingInfo originalCroppingInfo;

    /**
     * show a context menu at menuPosition
     * @param menuPosition
     */
    void showContextMenu(const QPoint &menuPosition);

    /**
     * init context menu
     */
    void setupContextMenu();

    /**
     * Align child views:
     * - the image is scaled to the provide size
     * - buttons are along the right window edge
     * @param size
     */
    void alignChildViews(QSize size);

    /**
     * Config this view with Config obj
     */
    void config(shared_ptr<Config> config, CroppingInfo croppingInfo);

    /**
     * Save the image to storage
     */
    void saveImage();

    /**
     * Copy image to clipboard.
     */
    void copyImageToClipboard();

    /**
     * get the coordinate of the top right corner of the window
     * @return
     */
    QPoint getTopRightCorner();

    /**
     * move the window using top-right corner as the reference point
     * @param newTopRightCorner
     */
    void moveByTopRight(QPoint newTopRightCorner);

    /**
     * reset the window size to the original size
     */
    void resetSize();

    /**
     * redraw this window
     */
    void resettt();

protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // FLOATIMAGEDIALOG_H
