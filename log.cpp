#include "log.h"


#include <QFile>
#include <QDateTime>
#include <QDir>
#include <QIODevice>
#include <QDebug>



void log::logt(const QString & s)
{
    // Don't log anything if logging is disabled


    QDateTime now = QDateTime::currentDateTimeUtc();
    QString s1 = now.toString("yyyy-MM-dd-HH-mm-ss ") + s;
    s1 +=  + "\n";
    QString path=QDir::homePath() + "/.DollarVPN/Dollar-debug.log";


    QFile ff(path);

    if (ff.open( QIODevice::Append)) {
        ff.write(s1.toLatin1());
        ff.flush();
        ff.close();
    }

}
