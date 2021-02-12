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
    connect(ui->toTrayButton, &QPushButton::clicked,this, [this]() {
        this->toTray();
    });

    connect(ui->configButton, &QPushButton::clicked,this,[this](){
        this->showConfig();
    });

    connect(this, &MainWindow::doneTakingImage, this, [this](const QPixmap &image, CroppingInfo croppingInfo) {
        auto *floatImageDialog = new FloatImageDialog(
                croppingInfo,
                image, this);
        this->imagePanels.append(floatImageDialog);

        connect(floatImageDialog,
                &QDialog::accepted,this,
                [this, floatImageDialog]() {
                    this->removeFloatImage(floatImageDialog);
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
        auto tray = this->trayIconMenu;
        tray->addAction(this->takePicAction);
        tray->addAction(this->showTestWindowAction);
        tray->addAction(this->openConfigDialogAction);
        tray->addAction(this->exitAction);
        this->trayIcon = new QSystemTrayIcon(this);
        QIcon icon(tr("://icon_red.png"));
        this->trayIcon->setIcon(icon);
        this->trayIcon->setContextMenu(this->trayIconMenu);
    }
}

void MainWindow::createActions() {
    //create exit action
    if (this->exitAction == nullptr) {
        this->exitAction = new QAction(tr("Exit"), this);
        connect(exitAction, &QAction::triggered, []() {
            QApplication::quit();
        });
    }

    // create take pic/show transparent window action
    if (this->takePicAction == nullptr) {
        this->takePicAction = new QAction(tr("Take Pic"), this);
        connect(takePicAction, &QAction::triggered, [this]() {
            //show transparent window
            this->showTransparentWindow();
        });
    }

    // create show test window action
    if (this->showTestWindowAction == nullptr) {
        this->showTestWindowAction = new QAction(tr("show test window"), this);
        connect(this->showTestWindowAction, &QAction::triggered, [this]() {
            this->show();
        });
    }

    // create open dialog action
    if(this->openConfigDialogAction== nullptr){
        this->openConfigDialogAction = new QAction("Config",this);
        connect(this->openConfigDialogAction,&QAction::triggered,[this](){
            this->showConfig();
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
        this->transparentDialog->exec();
    }
    this->transparentDialog->move(0, 0);
}

void MainWindow::showConfig() {
    if(this->configView==nullptr){
        this->configView = new ConfigView(this);
    }
    this->configView->exec();
}

void MainWindow::removeFloatImage(FloatImageDialog* floatImg) {
    qDebug()<< this->imagePanels.removeOne(floatImg);
    floatImg->deleteLater();
}
