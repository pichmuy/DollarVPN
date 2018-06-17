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

#include "trayiconmanager.h"

#include <QMenu>
#include <QFontDatabase>
#include <QTimer>




#include "authmanager.h"
#include "wndmanager.h"
#include "common.h"
#include "setting.h"
#include "settingpage.h"


#include "openvpnmanager.h"

#include "osspecific.h"



TrayIconManager::TrayIconManager(QWidget *parent)
    :mParent(parent)
{
    createTrayIcon();
    mTrayIcon->show();

    statusDisconnected();




    // On OSX check update the state icon every 3 seconds so we can change
    // from dark to light icons as the theme changes
    // TODO: Get notified by the os when this user setting changes instead
#ifdef Q_OS_DARWIN
    if (mIconTimer.get() == NULL) {
        mIconTimer.reset(new QTimer(this));
        connect(mIconTimer.get(), SIGNAL(timeout()),
                this, SLOT(updateStateIcon()));
        mIconTimer->start(3000);
    }
#endif
}

bool TrayIconManager::exists()
{
    return (mInstance.get() != NULL);
}


TrayIconManager::~TrayIconManager()
{


}

void TrayIconManager::createTrayIcon()
{
    mTrayIcon.reset(new QSystemTrayIcon(mParent));
    createTrayIconMenu();
    QMenu *menu = mTrayIconMenu.get();
    mTrayIcon->setContextMenu(menu);
    QIcon icon(OsSpecific::instance()->disconnectedIcon());
    mTrayIcon->setIcon(icon);
    connect(mTrayIcon.get(), &QSystemTrayIcon::activated,
            this, &TrayIconManager::actionActivated);
}

void TrayIconManager::createTrayIconMenu()
{
    mTrayIconMenu.reset(new QMenu(mParent));
    createMenuActions();

    if (!Setting::instance()->testing()) {
        mTrayIconMenu->addSeparator();
    }



    mTrayIconMenu->addSeparator();

    if (!Setting::instance()->testing()) {

        mTrayIconMenu->addSeparator();
    }

    //_TrayMenu->addAction(_ac_About.get());
    mTrayIconMenu->addAction(mShowAction.get());
    mTrayIconMenu->addAction(mCloseAction.get());

}

void TrayIconManager::createMenuActions()
{


    mShowAction.reset(new QAction(//QIcon(":/icons-tm/close-red.png"),
                           tr("Show"), this));
    connect(mShowAction.get(), SIGNAL(triggered()), this, SLOT(showTriggered()));

    mCloseAction.reset(new QAction(//QIcon(":/icons-tm/close-red.png"),
                           tr("Close"), this));
    connect(mCloseAction.get(), SIGNAL(triggered()), this, SLOT(closeTriggered()));
}

void TrayIconManager::actionActivated(QSystemTrayIcon::ActivationReason reason)
{
#ifdef Q_OS_WIN

    if (reason == QSystemTrayIcon::Trigger && !mTrayIconMenu->isVisible())
        mTrayIconMenu->exec();
#else
    Q_UNUSED(reason);
#endif
}

void TrayIconManager::updateStateIcon()
{
    OpenvpnManager::OvState st = OpenvpnManager::ovsDisconnected;
    if (OpenvpnManager::exists())
        st = OpenvpnManager::instance()->state();
    updateStateIcon(st);
}

void TrayIconManager::updateStateIcon(OpenvpnManager::OvState st)
{
    QString ic;
    switch (st) {
    case OpenvpnManager::ovsDisconnected:
        ic = OsSpecific::instance()->disconnectedIcon();
        break;
    case OpenvpnManager::ovsConnecting:
        ic = OsSpecific::instance()->connectingIcon();
        break;
    case OpenvpnManager::ovsConnected:
        ic = OsSpecific::instance()->connectedIcon();

        break;
    default:
        break;
    }
    QIcon icon(ic);
    mTrayIcon->setIcon(icon);
}









void TrayIconManager::aboutTriggered()
{
    WndManager::instance()->ToPrimary();
}

void TrayIconManager::closeTriggered()
{
    emit quitApplication();
}

void TrayIconManager::showTriggered()
{
   WndManager::instance()->ToPrimary();
}




std::auto_ptr<TrayIconManager> TrayIconManager::mInstance;
TrayIconManager * TrayIconManager::instance()
{
    if (!mInstance.get())
        mInstance.reset(new TrayIconManager(NULL));
    return mInstance.get();
}

void TrayIconManager::cleanup()
{
    std::auto_ptr<TrayIconManager> d(mInstance.release());
}

void TrayIconManager::createMenuItem(QMenu * m, const QString & name, size_t srv)
{
    QAction * a = m->addAction(name);
    a->setData(QVariant(int(srv)));
    connect(a, SIGNAL(triggered()),
            this, SLOT(connectToTriggered()));
}




void TrayIconManager::statusConnecting()
{

    updateStateIcon(OpenvpnManager::ovsConnecting);
}

void TrayIconManager::statusConnected()
{
    updateStateIcon(OpenvpnManager::ovsConnected);

}

void TrayIconManager::statusDisconnected()
{

    updateStateIcon(OpenvpnManager::ovsDisconnected);
}

static void s_set_enabled(QAction * ac, bool enabled, const char * /*icon_word */)
{
    if (!ac)
        return;
    ac->setEnabled(enabled);
//	QString fn = ":/icons-tm/";
//	fn += icon_word;
//	fn += (enabled ? "-red.png" : "-grey.png");
//	ac->setIcon(QIcon(fn));
}

