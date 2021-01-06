#include "croppingpane.h"
#include "ui_croppingpane.h"

CroppingPane::CroppingPane(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::CroppingPane) {
    ui->setupUi(this);
}

void CroppingPane::hideEvent(QHideEvent *event) {
    QWidget::hideEvent(event);
    Q_EMIT this->croppingPaneIsHidden();
}

CroppingPane::~CroppingPane() {
    delete ui;
}

CroppingInfo CroppingPane::getCroppingInfo() {
    return CroppingInfo( this->parentWidget()->mapToGlobal(this->pos()), this->size());
}

void CroppingPane::reset() {
    this->resize(0,0);
    this->hide();
}