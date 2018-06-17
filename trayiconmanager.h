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

#ifndef TRAYICONMANAGER_H
#define TRAYICONMANAGER_H


#include <memory>
#include <QSystemTrayIcon>

#include "openvpnmanager.h"

class QAction;

// This class manages the system tray icon and it's menu.
class TrayIconManager : public QObject
{
    Q_OBJECT
public:
    static TrayIconManager * instance();
    static bool exists();
    static void cleanup();

    ~TrayIconManager();

    void statusConnecting();
    void statusConnected();
    void statusDisconnected();

    void updateStateIcon(OpenvpnManager::OvState st);

signals:
    void login();
    void logout();
    void connectToServer(int serverId);
    void quitApplication();

public slots:



    void aboutTriggered();
    void closeTriggered();
    void showTriggered();

private slots:
    void updateStateIcon();
    void actionActivated(QSystemTrayIcon::ActivationReason reason);

private:
    explicit TrayIconManager(QWidget *parent = 0);

    static std::auto_ptr<TrayIconManager> mInstance;

    void createTrayIconMenu();
    void createMenuActions();
    void createTrayIcon();
    void createMenuItem(QMenu * m, const QString & name, size_t srv);

    std::auto_ptr<QSystemTrayIcon> mTrayIcon;
    std::auto_ptr<QMenu> mTrayIconMenu;
    std::auto_ptr<QAction> mAboutAction;
    std::auto_ptr<QAction> mCloseAction;
    std::auto_ptr<QAction> mShowAction;

#ifdef Q_OS_DARWIN
    std::auto_ptr<QTimer> mIconTimer;
#endif


    QWidget *mParent;
};

#endif // SJMAINWINDOW_H
