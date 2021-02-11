#include "transparentdialog.h"
#include "ui_transparentdialog.h"
#include <QDebug>
#include <QMouseEvent>
#include "../other/CroppingInfo.h"
#include <QScreen>
#include <QEventLoop>
#include <QPushButton>

TransparentDialog::TransparentDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::TransparentDialog) {
    ui->setupUi(this);
    this->setWindowOpacity(this->opacity);
    this->move(QPoint(0, 0));
    this->setWindowTitle(tr("transparent dialog"));
    this->resize(QWidget::screen()->size());

    this->croppingPane = new CroppingPane(this);
    QPalette pal = palette();
    pal.setColor(QPalette::ColorRole::Window, Qt::blue);
    this->croppingPane->setAutoFillBackground(true);
    this->croppingPane->setPalette(pal);
    this->croppingPane->setGeometry(0, 0, 0, 0);

    this->setWindowFlag(Qt::FramelessWindowHint);
}

void TransparentDialog::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    qDebug() << tr("Mouse down");
    this->anchor = QPoint(event->position().x(), event->position().y());
    this->croppingPane->move(this->anchor);
    this->croppingPane->resize(0, 0);
    this->croppingPane->show();
}

void TransparentDialog::mouseReleaseEvent(QMouseEvent *event) {
    QWidget::mouseReleaseEvent(event);
    qDebug() << QString("Mouse release %1 : %2").arg(this->anchor.x())
            .arg(this->anchor.y());
    Q_EMIT readyToTakeScreenshot(this->getCroppingInfo());
    this->resetCroppingPane();
    this->hide();
}

void TransparentDialog::mouseMoveEvent(QMouseEvent *event) {
    QWidget::mouseMoveEvent(event);
    qDebug() << tr("Mouse move");
    // update croppingPane
    int newWidth = abs(event->position().x() - this->anchor.x());
    int newHeight = abs(event->position().y() - this->anchor.y());
    int newXPos = [event, this]() -> int {
        if (event->position().x() <= this->anchor.x()) {
            return event->position().x();
        } else {
            return this->croppingPane->x();
        }
    }();

    int newYPos = [event, this]() -> int {
        if (event->position().y() <= this->anchor.y()) {
            return event->position().y();
        } else {
            return this->croppingPane->y();
        }
    }();

    this->croppingPane->resize(newWidth, newHeight);
    this->croppingPane->move(newXPos, newYPos);
}

TransparentDialog::~TransparentDialog() {
    delete ui;
}

void TransparentDialog::hideEvent(QHideEvent *event) {
    QWidget::hideEvent(event);
    QApplication::processEvents();
}

void TransparentDialog::closeEvent(QCloseEvent *event) {
    QDialog::closeEvent(event);
}

CroppingInfo TransparentDialog::getCroppingInfo() {
    if(this->allowCropping()){
        return this->croppingPane->getCroppingInfo();
    }else{
        return CroppingInfo::getInvalidInfo();
    }
}

bool TransparentDialog::allowCropping() {
    return this->croppingPane->size().isValid();
}

void TransparentDialog::resetCroppingPane() {
    this->croppingPane->reset();
}
