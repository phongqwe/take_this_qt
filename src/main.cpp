#include "mainwindow.h"

#include <QApplication>
#include <QtGui>
#include "src/config/Config.h"
#include <memory>
#include <QSettings>
void setDefaultSetting(QSettings& settings);
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setOrganizationName("Xadkile");
    QApplication::setOrganizationDomain("github.com/xadkile");
    QApplication::setApplicationName("take_this_qt");
    QApplication::setApplicationDisplayName("Take This");
    MainWindow mainWindow;
    QSettings setting(&app);
    setDefaultSetting(setting);
    app.setQuitOnLastWindowClosed(false);
    mainWindow.show();
    mainWindow.toTray();
    return app.exec();
}
//void setDefaultSetting(QSettings& settings){
//    if(!settings.contains(Config::FRAMED_FLOAT_IMG)){
//        settings.setValue(Config::FRAMED_FLOAT_IMG,true);
//    }
//}

