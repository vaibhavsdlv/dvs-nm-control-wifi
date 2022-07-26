#include "wifidevice.h"

#include <QDBusConnection>
#include <QDBusInterface>
#include <QDBusArgument>
#include <QDebug>

#include <iostream>

namespace ABC {

/**
 * @brief Constructor
 * @param _devicePath Device object path
 * Note: DevicePath is somthing like /org/freedesktop/NetworkManager/Devices/1
 */
WifiDevice::WifiDevice(std::string _devicePath )
    : devicePath( _devicePath )
{
    if( "" == devicePath )
    {
        std::cout << __PRETTY_FUNCTION__ << " : No wifi device available!\n";
        throw "No wifi device available!";
    }
}

/**
 * @brief Scan for access points
 * @return List of available access points
 */
std::vector< std::string > WifiDevice::ScanForAccessPoints()
{
    QDBusConnection bus = QDBusConnection::systemBus();
    QDBusInterface wirelessDevice( "org.freedesktop.NetworkManager",
        devicePath.c_str(),
        "org.freedesktop.NetworkManager.Device.Wireless",
        bus );
    QDBusMessage reply = wirelessDevice.call("GetAccessPoints");
    std::vector< std::string > apList;

    QDBusArgument args = reply.arguments().at( 0 ).value<QDBusArgument>();

    args.beginArray();
    while( !args.atEnd())
    {
        QString accessPoint;
        args >> accessPoint;
        qDebug() << accessPoint;
        apList.push_back( accessPoint.toStdString());
    }

    return apList;
}

/**
 * @brief Connect device to provided access point
 * @param accessPoint Access point
 */
void WifiDevice::connect(std::string &accessPoint)
{
    (void)accessPoint;
}

/**
 * @brief Disconnect device from current connected access point
 */
void WifiDevice::disconnect()
{
}

} // namespace ABC

