/***************************************************************************
 *   Copyright (C) 2017 by Jeremy Whiting <jeremypwhiting@gmail.com>       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.                *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/

#ifndef COMMON_H
#define COMMON_H

#include <QDialog>
#include <QHash>
#include <QString>
#include <QSettings>
#include <QApplication>

#define THE_APP_CLASS QApplication

#include <QNetworkRequest>

#include <map>
#include <set>
#include <string>
#include <vector>

enum EncryptionType {
    ENCRYPTION_RSA = 0,
    ENCRYPTION_TOR_OBFS2,
    ENCRYPTION_TOR_OBFS3,
    ENCRYPTION_TOR_SCRAMBLESUIT,
    ENCRYPTION_ECC,
    ENCRYPTION_ECCXOR,
    ENCRYPTION_COUNT
};

const QList<QString> encryptionNames = {
    "RSA 4096-bit",
    "RSA + TOR (obfs2)",
    "RSA + TOR (obfs3)",
    "RSA + TOR (scramblesuit)",
    "ECC (secp384r1)",
    "ECC + XOR",
};

#define PORT_FORWARD_MAX 5

extern THE_APP_CLASS * g_pTheApp;

bool IsValidIp(const QString & ip);
bool IsValidPort(const QString & s);

bool OpenUrl(const char * url);
bool OpenUrl_Support();
bool OpenUrl_Panel();
bool OpenUrl_Earn();
bool OpenUrl_Bug();
bool launchUpdateUrl();

void SaveCb(const char * name, bool val);



struct AServer {
    QString ip_address;    // IP or DNs
    QString name;       // "Chile Hub" - Hub at the end indicates hub
    QString load;       // double
    QString flag;
    QString country;
};

struct BServer {
    QString id;
    QString ip;    // IP or DNs
    QString name;       // "Chile Hub" - Hub at the end indicates hub
    QString state;       // double
    QString status;
    QString country;
    QString config;
};
struct Port{
    QString portID;
    QString port;
    QString ip;
    QString server;
};


typedef QHash<QString, size_t>  HMSI;

typedef std::map<std::string, int> SIMap;
typedef std::map<int, int> IIMap;

typedef std::vector<unsigned int> UVec;
typedef std::set<unsigned int> USet;

// escape \ and "
QString EscapePsw(const QString & raw);

QNetworkRequest BuildRequest(const QUrl & u);

#endif // COMMON_H
