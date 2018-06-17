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

#include "setting.h"

#include <stdexcept>

#include "common.h"
#include "authmanager.h"
#include "osspecific.h"
#include "log.h"


//In future, we’ll add things such as “OpenVPN with XOR TCP 448” or “OpenVPN with TOR UDP 4044”.

static const QString kLoggingKey = "logging";

std::vector<QString> Setting::mProtocols[ENCRYPTION_COUNT];
std::vector<int> Setting::mPorts[ENCRYPTION_COUNT];

Setting::Setting()
    :mTesting(false)
{
    mDefaultDNS[0] = "146.185.134.104";
    mDefaultDNS[1] = "192.241.172.159";
}

Setting::~Setting()
{}

void Setting::setDefaultDNS(const QString & dns1, const QString & dns2)
{
    mDefaultDNS[0] = dns1;
    mDefaultDNS[1] = dns2;
}

QString Setting::defaultDNS1()
{
    return mDefaultDNS[0];
}

QString Setting::defaultDNS2()
{
    return mDefaultDNS[1];
}

void Setting::PopulateColls(std::vector<QString> & v_strs, std::vector<int> & v_ports, size_t sz, const char ** protocols, const int * ports)
{
    if (v_strs.empty()) {
        for (size_t k = 0; k < sz; ++k) {
            v_strs.push_back(protocols[k]);
            v_ports.push_back(ports[k]);
        }
    }
}

const std::vector<QString> & Setting::currentEncryptionProtocols()
{
    int enc = encryption();
    if (mProtocols[enc].empty()) {
        switch (enc) {
        case ENCRYPTION_RSA: {
            const char * gs_protocols [] = {
                "TCP 80 (RSA)"
                , "TCP 110 (RSA)"
                , "TCP 443 (RSA)"

                , "TCP 843 (RSA)"

                , "UDP 53 (RSA)"

                , "UDP 1194 (RSA)"
                , "UDP 1443 (RSA)"
                , "UDP 8080 (RSA)"
                , "UDP 9201 (RSA)"
            };
            const int gs_ports [] = {
                80
                , 110
                , 443
                , 843
                , 53
                , 1194
                , 1443
                , 8080
                , 9201
            };

            size_t sz = sizeof(gs_protocols)/sizeof(gs_protocols[0]);
            PopulateColls(mProtocols[enc], mPorts[enc], sz, gs_protocols, gs_ports);
            break;
        }

        case ENCRYPTION_TOR_OBFS2: {
            const char * gs_protocols [] = {
                "TCP 888 (RSA+TOR)"
            };
            const int gs_ports [] = {
                888
            };
            size_t sz = sizeof(gs_protocols)/sizeof(gs_protocols[0]);
            PopulateColls(mProtocols[enc], mPorts[enc], sz, gs_protocols, gs_ports);
            break;
        }
        case ENCRYPTION_TOR_OBFS3: {
            const char *gs_protocols [] = {
                "TCP 898 (RSA+TOR)"
            };
            const int gs_ports [] = {
                898
            };
            size_t sz = sizeof(gs_protocols)/sizeof(gs_protocols[0]);
            PopulateColls(mProtocols[enc], mPorts[enc], sz, gs_protocols, gs_ports);
            break;
        }
        case ENCRYPTION_TOR_SCRAMBLESUIT: {
            const char *gs_protocols [] = {
                "TCP 988 (RSA+TOR)"
            };
            const int gs_ports [] = {
                988
            };
            size_t sz = sizeof(gs_protocols)/sizeof(gs_protocols[0]);
            PopulateColls(mProtocols[enc], mPorts[enc], sz, gs_protocols, gs_ports);
            break;
        }
        case ENCRYPTION_ECC: {
            const char * gs_protocols [] = {
                "TCP 465 (ECC)"
            };
            const int gs_ports [] = {
                465
            };
            size_t sz = sizeof(gs_protocols)/sizeof(gs_protocols[0]);
            PopulateColls(mProtocols[enc], mPorts[enc], sz, gs_protocols, gs_ports);
            break;
        }
        case ENCRYPTION_ECCXOR: {
            const char * gs_protocols [] = {
                "TCP 995 (ECC+XOR)"
            };
            const int gs_ports [] = {
                995
            };
            size_t sz = sizeof(gs_protocols)/sizeof(gs_protocols[0]);
            PopulateColls(mProtocols[enc], mPorts[enc], sz, gs_protocols, gs_ports);
            break;
        }
        default:
            throw std::runtime_error("invalid encryption index");
        }
    }
    return mProtocols[enc];
}

const std::vector<int> & Setting::currentEncryptionPorts()
{
    const std::vector<QString> & pr = currentEncryptionProtocols();		// force init
    if (!pr.empty()) {
        int enc = encryption();
        return mPorts[enc];
    } else {
        return mPorts[0];
    }
}

std::auto_ptr<Setting> Setting::mInstance;
Setting * Setting::instance()
{
    if (!mInstance.get())
        mInstance.reset(new Setting());
    return mInstance.get();
}

void Setting::cleanup()
{
    if (mInstance.get() != NULL)
        delete mInstance.release();
}

bool Setting::exists()
{
    return (mInstance.get() != NULL);
}

bool Setting::showNodes()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("cb_ShowNodes", false).toBool();
}

void Setting::setShowNodes(bool v)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("cb_ShowNodes", v);
    emit showNodesChanged();
}

bool Setting::disableIPv6()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("cb_DisableIpv6", true).toBool();
}

void Setting::setDisableIPv6(bool v)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("cb_DisableIpv6", v);
    try {
        OsSpecific::instance()->setIPv6(!v);
    } catch(std::exception & ex) {
        log::logt(ex.what());
    }
}

bool Setting::autoconnect()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("cb_AutoConnect", false).toBool();
}

void Setting::setAutoconnect(bool v)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("cb_AutoConnect", v);
}

bool Setting::detectInsecureWifi()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("cb_InsecureWiFi", false).toBool();
}

void Setting::setDetectInsecureWifi(bool v)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("cb_InsecureWiFi", v);
    emit detectInsecureWifiChanged(); // Send signal so login window can start wifi watcher timer
}

bool Setting::blockOnDisconnect()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("cb_BlockOnDisconnect", false).toBool();
}

void Setting::setBlockOnDisconnect(bool v)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("cb_BlockOnDisconnect", v);
}

bool Setting::fixDns()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("cb_FixDnsLeak", true).toBool();
}

void Setting::setFixDns(bool v)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("cb_FixDnsLeak", v);
}

bool Setting::testing()
{
    return mTesting;
}

void Setting::setTesting(bool value)
{
    mTesting = value;
}

bool Setting::logging()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value(kLoggingKey, true).toBool();
}

void Setting::setLogging(bool value)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue(kLoggingKey, value);
}

bool Setting::startup()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("cb_Startup", true).toBool();
}

void Setting::setStartup(bool v)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("cb_Startup", v);
    // Do the OsSpecific stuff to make it happen
    OsSpecific::instance()->setStartup(v);
}

void Setting::setProtocol(QString protocol)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("protocol", protocol);
}
QString Setting::getProtocol()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("protocol","tcp").toString();

}



bool Setting::reconnect()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("cb_Reconnect", true).toBool();
}

void Setting::setReconnect(bool v)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("cb_Reconnect", v);
}

int Setting::encryption()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    int enc = settings.value("dd_Encryption", 0).toInt();
    if (enc < 0 || enc >= ENCRYPTION_COUNT)
        enc = 0;
    return enc;
}

void Setting::setEncryption(int enc)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    if (enc > -1 && enc < ENCRYPTION_COUNT && enc != settings.value("dd_Encryption", 0).toInt()) {
        settings.setValue("dd_Encryption", enc);
        loadProtocol(); // When encryption changes, we need to load protocols
        emit encryptionChanged();
    }
}

QString Setting::encryptionName(int enc)
{
    if (enc >= ENCRYPTION_COUNT || enc >= encryptionNames.size())
        enc = ENCRYPTION_RSA;
    return encryptionNames.at(enc);
}

QString Setting::EncryptionIx()
{
    int enc = encryption();
    QString s;
    if (enc > 0)
        s = QString::number(enc);
    return s;
}

QString Setting::ProtocolSettingsName()
{
    return "dd_Protocol_ix" + EncryptionIx();
}

QString Setting::ProtocolSettingsStrName()
{
    return "dd_Protocol_str" + EncryptionIx();
}

QString Setting::LocationSettingsName()
{
    return "dd_Location_ix" + EncryptionIx();
}

QString Setting::LocationSettingsStrName()
{
    return "dd_Location_str" + EncryptionIx();
}

static bool _loading_protocol = false;
void Setting::setProtocol(int ix)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    if (_loading_protocol)
        return;
    settings.setValue(ProtocolSettingsName(), ix);
    QString s;
    if (ix > -1 && ix < (int)currentEncryptionProtocols().size())
        s = currentEncryptionProtocols().at(ix);
    settings.setValue(ProtocolSettingsStrName(), s);
    emit protocolChanged();
}

void Setting::loadProtocol()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    _loading_protocol = true;
    int ix = settings.value(ProtocolSettingsName(), -1).toInt();
    if (ix > -1) {
        if (ix >= (int)currentEncryptionProtocols().size())
            ix = -1;
        else {
            QString s = settings.value(ProtocolSettingsStrName(), "").toString();
            if (s != currentEncryptionProtocols().at(ix))
                ix = -1;
        }
    }
    if (ix < 0) {
        ix = rand() % currentEncryptionProtocols().size();
    }
    setProtocol(ix);

    _loading_protocol = false;
}

static QString gs_Empty = "";
const QString & Setting::protocolName(int ix)
{
    if (ix > -1 && ix < currentEncryptionProtocols().size())
        return currentEncryptionProtocols().at(ix);
    else
        return gs_Empty;
}

const QString & Setting::currentProtocolName()
{
    return protocolName(currentProtocol());
}

const QString Setting::forwardPortsString()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("e_Ports", "").toString();
}

int Setting::currentProtocol()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value(ProtocolSettingsName(), -1).toInt();
}

void Setting::setServer(int ixsrv)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    BServer se = AuthManager::instance()->getServer(ixsrv);
    QString newsrv = se.name;
    settings.setValue(LocationSettingsName(), ixsrv);
    settings.setValue(LocationSettingsStrName(), newsrv);
    emit serverChanged();
}

void Setting::loadServer()
{
    log::logt("Setting loadServer called");
    if (AuthManager::instance()->currentEncryptionServers().empty()) {
        log::logt("Returning because we don't have a server list");
        return;		// cannot select in empty list
    }
    QSettings settings("settings.ini",QSettings::IniFormat);
    int savedsrv = settings.value(LocationSettingsName(), -1).toInt();
    QString savedname = settings.value(LocationSettingsStrName(), "undefined").toString();
    log::logt("In Setting::loadServer previously saved server name is " + savedname);
    log::logt("Previously saved server index is " + QString::number(savedsrv));

    int ixsrv = -1;
    // verify that the sever exists
    if (savedsrv > -1) {
        BServer  sr1 = AuthManager::instance()->getServer(savedsrv);
        if (!sr1.name.isEmpty()) {
            if (sr1.name == savedname)
                ixsrv = savedsrv;
            else if (savedname != "undefined") {
                ixsrv = AuthManager::instance()->serverIxFromName(savedname);
                log::logt("Server names didn't match their indexes, server index is " + QString::number(ixsrv));
            }
        } else {
            if (savedname != "undefined") {
                ixsrv = AuthManager::instance()->serverIxFromName(savedname);
                log::logt("Server names didn't match their indexes, server index is " + QString::number(ixsrv));
            }
        }
    }

    if (ixsrv < 0)
        ixsrv = AuthManager::instance()->getServerToJump();

    log::logt("Setting::loadServer server index to set is " + QString::number(ixsrv));
    // initiate population of the Location drop-down;
    // will call Setting::IsShowNodes() which will initiate scr_settings and load checkboxes
    setServer(ixsrv);
}

void Setting::setlastServer(BServer server)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("lastserver",server.id);
}

BServer Setting::getlastServer()
{
     QSettings settings("settings.ini",QSettings::IniFormat);
     QString serverid = settings.value("lastserver","").toString();
     for (int i=0;i<AuthManager::instance()->mServers.count();i++)
     {
         if(serverid == AuthManager::instance()->mServers[i].id)
             return AuthManager::instance()->mServers[i];
     }
     return AuthManager::instance()->mServers[0];
}

QString Setting::serverAddress()
{
    QString s;
    int ix = serverID();
    if (ix > -1)
        s = AuthManager::instance()->getServer(ix).ip;
    return s;
}

int Setting::serverID()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value(LocationSettingsName()).toInt();
}

QString Setting::port()
{
//    int ix = currentProtocol();
//    int p = 80;
//    int enc = encryption();
//    std::vector<int> & v_ports = mPorts[enc];
//    if (ix > -1 && ix < (int)v_ports.size())
//        p = v_ports.at(ix);
//    return QString::number(p);

    return "443";
}

int Setting::determineNextPort()
{
    int ix = currentProtocol();
    ++ix;
    int enc = encryption();
    std::vector<int> & v_ports = mPorts[enc];
    if (ix >= (int)v_ports.size())
        ix = 0;
    return ix;
}

void Setting::switchToNextPort()
{
    int ix = determineNextPort();
    setProtocol(ix);
}

void Setting::switchToNextNode()
{
    // Get the current encryption server ids list
    QList<int> ids = AuthManager::instance()->currentEncryptionServers();
    // Find the current server
    int ix = serverID();
    // Go to the next one
    int which = ids.indexOf(ix);
    if (which != -1 && which + 1 < ids.size())
        setServer(ids.at(which + 1));
}

QString Setting::localPort()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    QString p = settings.value("e_LocalPort", "9090").toString();
    if (p.isEmpty())
        p = "6842";
    return p;
}

void Setting::setLocalPort(QString port)
{   QSettings settings("settings.ini",QSettings::IniFormat);
    if (IsValidPort(port)) {
        settings.setValue("e_LocalPort", port);
    }
}

QString Setting::tcpOrUdp()
{
    QString description = protocolName(currentProtocol());
    if (description.contains("udp", Qt::CaseInsensitive))
        return "udp";
    else
        return "tcp";
}

QString Setting::dns1()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("e_PrimaryDns", "").toString();
}

void Setting::setDNS1(QString value)
{   QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("e_PrimaryDns", value);
}

QString Setting::dns2()
{   QSettings settings("settings.ini",QSettings::IniFormat);
    return settings.value("e_SecondaryDns", "").toString();
}

void Setting::setDNS2(QString value)
{   QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("e_SecondaryDns", value);
}

UVec Setting::forwardPorts()
{
    QString portsString = forwardPortsString();
    bool valid = true;
    UVec v;
    QStringList pp = portsString.split(",");
    for (int k = 0; k < pp.length() && valid; ++k) {
        if (!IsValidPort(pp[k])) {
            valid = false;
            v.clear();
        } else {
            v.push_back(pp[k].toInt());
        }
    }

    std::sort(v.begin(), v.end());
    return v;
}

void Setting::setForwardPorts(QString portsString)
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("e_Ports", portsString);
}

static const char * gs_upd_name = "LastUpdMsg";
static const char * gs_undefined = "undefined";
bool Setting::checkForUpdates()
{
    bool is = true;
    QSettings settings("settings.ini",QSettings::IniFormat);
    QString saved = settings.value(gs_upd_name, gs_undefined).toString();
    if (saved != gs_undefined) {
        uint curr = QDateTime::currentDateTimeUtc().toTime_t();
        bool ok;
        uint old = saved.toUInt(&ok);
        if (ok) {
            int d = curr - old;
            static const int day = 24 * 60 * 60;
            if (d < day)
                is = false;
        }
    }
    return is;
}

void Setting::updateMessageShown()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    uint t = QDateTime::currentDateTimeUtc().toTime_t();
    settings.setValue(gs_upd_name, QString::number(t));
}
