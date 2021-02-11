#include <QtGui/QMouseEvent>
#include "floatimagedialog.h"
#include "ui_floatimagedialog.h"
#include <QDebug>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QDateTime>
#include <QClipboard>
#include "../config/Config.h"
#include <memory>
FloatImageDialog::FloatImageDialog(CroppingInfo croppingInfo, QPixmap image, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::FloatImageDialog) {
    ui->setupUi(this);
    this->move(croppingInfo.position);
    this->setFixedSize(croppingInfo.size);
    this->ui->imageLabel->move(0, 0);
    this->ui->imageLabel->resize(croppingInfo.size);
    this->pixmap = image.scaled(croppingInfo.size);
    this->ui->imageLabel->setPixmap(this->pixmap);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);

    connect(this,&QWidget::customContextMenuRequested,
            this,&FloatImageDialog::showContextMenu);
    connect(Config::getInstance().get(),
            &Config::settingChangedSignal,
            [this](std::shared_ptr<Config> config){
        // TODO de-draw this view when setting is changed
        qDebug()<< "ReDraw";
    });
}

FloatImageDialog::~FloatImageDialog() {
    delete ui;
}

void FloatImageDialog::mousePressEvent(QMouseEvent *event) {
    qDebug() << tr("FloatImage: Mouse press");
    QWidget::mousePressEvent(event);
    if (event->button() == Qt::MouseButton::RightButton) {
        this->preventClose = true;
    }
    if (event->button() == Qt::MouseButton::LeftButton) {
        this->isLeftMouseDown = true;
        this->xDistanceBetweenCornerAndMouse = abs(event->globalPosition().x() - this->x());
        this->yDistanceBetweenCornerAndMouse = abs(event->globalPosition().y() - this->y());
    }
}

void FloatImageDialog::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << tr("FloatImage: Mouse release ");
    if (this->preventClose==false) {
        this->close();
    }
    this->preventClose = false;
    this->isLeftMouseDown = false;
}

void FloatImageDialog::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
    //move the image around
    qDebug() << tr("FloatImage: Move mouse");
    qDebug() << event->button();
    if (this->isLeftMouseDown) {
        qDebug() << tr("FloatImage: Move mouse - left button");
        QPoint newXY = QPoint(event->globalPosition().x() - this->xDistanceBetweenCornerAndMouse,
                              event->globalPosition().y() - this->yDistanceBetweenCornerAndMouse);
        qDebug() << newXY;
        this->move(newXY);

        this->preventClose = true;
    }
}

void FloatImageDialog::closeEvent(QCloseEvent *event) {
    this->setParent(nullptr);
    QDialog::closeEvent(event);
    qDebug() << "close float image";
    Q_EMIT QDialog::accepted();
}

void FloatImageDialog::showContextMenu(const QPoint& menuPosition) {
    this->setupContextMenu();
    this->contextMenu->show();

    this->contextMenu->move(this->mapToGlobal(menuPosition));
}

void FloatImageDialog::setupContextMenu() {
    if(this->saveAction == nullptr){
        this->saveAction = new QAction("Save",this);
        connect(this->saveAction,&QAction::triggered,[this](){
            // save the image
            QString defaultFileName = "image_" +  QDateTime::currentDateTime().toLocalTime().toString() + ".png";
            qDebug() << defaultFileName;
            QString fileName = QFileDialog::getSaveFileName(this,"Save image",defaultFileName,"*.png");
            if(!fileName.isEmpty()){
                this->pixmap.toImage().save(fileName, "png");
                qDebug() << "FloatImageDialog: save image to " + fileName;
            }
        });
    }

    if(this->copyToClipboardAction== nullptr){
        this->copyToClipboardAction = new QAction("Copy to clipboard",this);
        connect(this->copyToClipboardAction,&QAction::triggered,[this](){
            qDebug()<<"FloatImageDialog: Copy to clipboard";
            QApplication::clipboard()->setPixmap(this->pixmap);
        });
    }

    if(this->contextMenu == nullptr){
        this->contextMenu = new QMenu(this);
        this->contextMenu->addAction(this->saveAction);
        this->contextMenu->addAction(this->copyToClipboardAction);
    }
}

