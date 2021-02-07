//
// Created by abc on 2/7/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ConfigView.h" resolved

#include "ConfigView.h"
#include "ui_ConfigView.h"

ConfigView::ConfigView(QWidget *parent) :
        QWidget(parent), ui(new Ui::ConfigView) {
    ui->setupUi(this);
}

ConfigView::~ConfigView() {
    delete ui;
}
