#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transparent_dialog/transparentdialog.h"
#include <QDebug>
#include <QScreen>
#include <QThread>
#include <QEventLoop>
#include <QWindow>
#include<QGraphicsObject>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->takePicButton, &QPushButton::clicked,
            [this]() {
                this->showTransparentWindow();
            });

    this->createActions();
    this->createTrayIcon();
    this->createTransparentWindow();
    this->move(0, 0);
    connect(ui->pushButton, &QPushButton::clicked, [this]() {
        this->toTray();
    });

    connect(this, &MainWindow::doneTakingImage, [this](const QPixmap &image, CroppingInfo croppingInfo) {
        FloatImageDialog *floatImageDialog = new FloatImageDialog(
                croppingInfo,
                image, this);
        this->imagePanels.append(floatImageDialog);
        connect(floatImageDialog,
                &QDialog::accepted,
                [this, floatImageDialog]() {
                    floatImageDialog->setParent(nullptr);
                    int rmCount = this->imagePanels.removeAll(floatImageDialog);
                    qDebug() << rmCount;
                    delete floatImageDialog;
                });
        floatImageDialog->show();
    });
}

void MainWindow::toTray() {
    this->hide();
    this->trayIcon->show();
}

MainWindow::~MainWindow() {
    delete ui; //pointer in constructor must be cleaned in destructor to prevent mem leak
}

void MainWindow::createTrayIcon() {
    if (this->trayIconMenu == nullptr) {
        this->trayIconMenu = new QMenu(this);
        this->trayIconMenu->addAction(this->takePicAction);
        this->trayIconMenu->addAction(this->showTestWindowAction);
        this->trayIconMenu->addAction(this->exitAction);
        this->trayIcon = new QSystemTrayIcon(this);
        QIcon icon(tr("://icon_red.png"));
        this->trayIcon->setIcon(icon);
        this->trayIcon->setContextMenu(this->trayIconMenu);
    }
}

void MainWindow::createActions() {
    if (this->exitAction == nullptr) {
        this->exitAction = new QAction(tr("Exit"), this);
        connect(exitAction, &QAction::triggered, []() {
            QApplication::quit();
        });
    }

    if (this->takePicAction == nullptr) {
        this->takePicAction = new QAction(tr("Take Pic"), this);
        connect(takePicAction, &QAction::triggered, [this]() {
            //show transparent window
            this->showTransparentWindow();
        });
    }
    if (this->showTestWindowAction == nullptr) {
        this->showTestWindowAction = new QAction(tr("show test window"), this);
        connect(this->showTestWindowAction, &QAction::triggered, [this]() {
            this->show();
        });
    }
}

void MainWindow::createTransparentWindow() {
    if (this->transparentDialog == nullptr) {
        this->transparentDialog = new TransparentDialog(this);

        connect(this->transparentDialog,
                &TransparentDialog::readyToTakeScreenshot,
                [this](CroppingInfo cp) {
                    this->takeScreenshot(cp);
                });
    }
}

void MainWindow::takeScreenshot(CroppingInfo croppingInfo) {
    QTimer::singleShot(Config::getInstance()->getWaitInMilliSec(), this, [this, croppingInfo]() {
        QPixmap pixmap = QWidget::screen()->grabWindow(
                QWidget::winId(),
                croppingInfo.position.x(), croppingInfo.position.y(),
                croppingInfo.size.width(), croppingInfo.size.height()
        );

        Q_EMIT doneTakingImage(pixmap, croppingInfo);
    });
}

void MainWindow::showTransparentWindow() {
    if (!this->transparentDialog->isVisible()) {
        this->transparentDialog->showMaximized();
    }
    this->transparentDialog->move(0, 0);
}
