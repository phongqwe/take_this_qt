#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QtWidgets/QSystemTrayIcon>
#include "src/TransparentDialog/transparentdialog.h"
#include "src/FloatImageDialog/floatimagedialog.h"
#include <QWindow>
#include <src/Other/Config.h>
#include <memory>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void toTray();

private:
    Ui::MainWindow *ui;
    TransparentDialog *transparentDialog = nullptr;
    QMenu *trayIconMenu = nullptr;
    QSystemTrayIcon *trayIcon = nullptr;
    QAction *takePicAction = nullptr;
    QAction *showTestWindowAction = nullptr;
    QAction *exitAction = nullptr;

    QVector<FloatImageDialog*> imagePanels;

    void createTrayIcon();
    void createActions();
    void createTransparentWindow();
    void showTransparentWindow();
public slots:
    void takeScreenshot(CroppingInfo croppingInfo);

signals:
    void doneTakingImage(QPixmap image, CroppingInfo croppingInfo);
};
#endif // MAINWINDOW_H
