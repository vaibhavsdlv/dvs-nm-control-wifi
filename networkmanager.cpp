#include "networkmanager.h"

#include <QDBusConnection>
#include <QDBusInterface>
#include <QDebug>
#include <QDBusArgument>
#include <QVector>

#include <iostream>

namespace ABC {

const std::string NM_SERVICE_NAME = "org.freedesktop.NetworkManager";
const std::string NM_OBJECT = "/org/freedesktop/NetworkManager";
const std::string NM_INTERFACE = "org.freedesktop.NetworkManager";


NetworkManager::NetworkManager()
{
}

std::vector< std::string > NetworkManager::GetDevices()
{
    QDBusConnection bus = QDBusConnection::systemBus();
    QDBusInterface dbusIface("org.freedesktop.NetworkManager",
        "/org/freedesktop/NetworkManager",
        "org.freedesktop.NetworkManager",
        bus );

    QDBusMessage reply = dbusIface.call("GetDevices");
    if ( reply.arguments().size() == 0 )
    {
        std::cout << __PRETTY_FUNCTION__ << " Reply contains 0 arguments!\n";
        throw "Reply contains 0 arguments!";
    }

    std::vector< std::string > deviceList;

    QDBusArgument arg = reply.arguments().at(0).value<QDBusArgument>();
    arg.beginArray();

    while(!arg.atEnd())
    {
        QString device;
        arg >> device;
        deviceList.push_back( device.toStdString() );
    }

    return deviceList;
}
} // namespace ABC
