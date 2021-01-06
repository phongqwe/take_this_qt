#include "mainwindow.h"

#include <QApplication>
#include <QtGui>
#include <src/Other/Config.h>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;

    app.setQuitOnLastWindowClosed(false);
    mainWindow.show();
    mainWindow.toTray();
    return app.exec();
}
