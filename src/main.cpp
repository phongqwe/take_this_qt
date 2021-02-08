#include "mainwindow.h"

#include <QApplication>
#include <QtGui>
#include "src/config/Config.h"
#include <memory>
#include <QSettings>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setOrganizationName("Xadkile");
    QApplication::setOrganizationDomain("github.com/xadkile");
    QApplication::setApplicationName("take_this_qt");
    QApplication::setApplicationDisplayName("Take This");
    MainWindow mainWindow;
    app.setQuitOnLastWindowClosed(false);
    mainWindow.show();
    mainWindow.toTray();
    return app.exec();
}

