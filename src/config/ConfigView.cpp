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
    c->setShowTitleBarOnFloatImage(this->ui->framedImgOption->isChecked());
    c->setFloatImageAlwaysOnTopFlag(this->ui->imgOnTopOption->isChecked());
    c->setClickToCloseFloatImgFlag(this->ui->clickToCloseImgOption->isChecked());
    c->setWaitInMilliSec(this->ui->waitDurationBox->value());
    c->setShowUiFloatImg(this->ui->showUiFloatImgOption->isChecked());
    c-> emitSettingChanged();
    c->writeSettingsToStorage();
    this->hide();
}
void ConfigView::loadConfig(){
    shared_ptr<Config> c = this->config;
    c->loadFromStorage();
    ui->waitDurationBox->setValue(c->getWaitInMilliSec());
    ui->clickToCloseImgOption->setChecked(c->getClickToCloseFloatImgFlag());
    ui->framedImgOption->setChecked(c->getShowTitleBarOnFloatImage());
    ui->imgOnTopOption->setChecked(c->getFloatImageAlwaysOnTopFlag());
    ui->showUiFloatImgOption->setChecked(c->getShowUiFloatImg());
}
void ConfigView::showEvent(QShowEvent *event) {
    this->loadConfig();
    QDialog::showEvent(event);
}
