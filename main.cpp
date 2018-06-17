#include "mainwindow.h"
#include <QApplication>
#include <QLockFile>
#include <QDir>
#include "log.h"


#define THE_APP_CLASS QApplication
THE_APP_CLASS * g_pTheApp;
int main(int argc, char *argv[])
{
    QString tmpDir = QDir::tempPath();
    QLockFile lockFile(tmpDir + "/125.lock");
    QDir dir;
    dir.mkpath(QDir::homePath()+"/.DollarVPN");
    if(lockFile.tryLock(125)){
        g_pTheApp = new THE_APP_CLASS(argc, argv);
        MainWindow::instance()->show();

        int res = g_pTheApp->exec();
//        MainWindow::Cleanup();
        log::logt("Quit Application");
        delete g_pTheApp;
        return res;
    }
}
