//
// Created by abc on 2/8/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ConfigView.h" resolved

#include "ConfigView.h"
#include "ui_ConfigView.h"

ConfigView::ConfigView(QWidget *parent) :
        QDialog(parent), ui(new Ui::ConfigView) {
    ui->setupUi(this);
    this->config = Config::getInstance();
    shared_ptr<Config> c = this->config;
    this->setModal(true);

    this->connect(ui->cancelButton,&QPushButton::clicked,[this](){
        this->cancelButtonHandler();
    });

    this->connect(ui->okButton,&QPushButton::clicked,[this](){
       this->okButtonHandler();
    });
}


ConfigView::~ConfigView() {
    delete ui;
}

void ConfigView::cancelButtonHandler() {
    this->reject();
}

void ConfigView::okButtonHandler() {
    shared_ptr<Config> c = this->config;
    c->setFramedFloatImageFlag(this->ui->framedImgOption->isChecked());
    c->setFloatImageAlwaysOnTopFlag(this->ui->imgOnTopOption->isChecked());
    c->setClickToCloseFloatImgFlag(this->ui->clickToCloseImgOption->isChecked());
    c->setWaitInMilliSec(this->ui->waitDurationBox->value());
    c-> emitSettingChanged();
    c->writeSettingsToStorage();
    this->accept();
}
void ConfigView::loadConfig(){
    shared_ptr<Config> c = this->config;
    c->loadFromStorage();
    ui->waitDurationBox->setValue(c->getWaitInMilliSec());
    ui->clickToCloseImgOption->setChecked(c->getClickToCloseFloatImgFlag());
    ui->framedImgOption->setChecked(c->getFramedFloatImageFlag());
    ui->imgOnTopOption->setChecked(c->getFloatImageAlwaysOnTopFlag());

}
void ConfigView::showEvent(QShowEvent *event) {
    QDialog::showEvent(event);
    this->loadConfig();
}
