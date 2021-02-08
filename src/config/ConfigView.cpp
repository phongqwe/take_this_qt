//
// Created by abc on 2/8/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ConfigView.h" resolved

#include "ConfigView.h"
#include "ui_ConfigView.h"

ConfigView::ConfigView(QWidget *parent) :
        QDialog(parent), ui(new Ui::ConfigView) {
    ui->setupUi(this);
}

ConfigView::~ConfigView() {
    delete ui;
}
