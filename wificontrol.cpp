#include "wificontrol.h"
#include "networkmanager.h"

#include <QDBusInterface>

#include <iostream>

namespace ABC {

namespace  {

std::string FindWifiDevice( std::vector< std::string > deviceList )
{
    for ( unsigned int i = 0; i < deviceList.size(); i++ )
    {
        QDBusConnection bus = QDBusConnection::systemBus();
        QDBusInterface wirelessDevice( "org.freedesktop.NetworkManager",
                                       deviceList.at( i ).c_str(),
                                       "org.freedesktop.NetworkManager.Device.Wireless",
                                       bus );
        QDBusMessage reply = wirelessDevice.call("GetAccessPoints");

        if( reply.errorMessage() == "" )
        {
            std::cout << " : wireless found : " << deviceList.at( i ) << "\n";
            return deviceList.at( i );
        }
    }

    return "";
}
}

/**
 * @brief Constructor
 */
WifiControl::WifiControl() :
    networkManager(),
    wifiDevice( FindWifiDevice( networkManager.GetDevices()))
{
}

/**
 * @brief Start wifi device
 */
void WifiControl::StartWifi()
{
}

/**
 * @brief Stop wifi device
 */
void WifiControl::StopWifi()
{
}

/**
 * @brief Get list of all access points
 * @return List of access points
 */
std::vector<std::string> WifiControl::GetAllAccessPoints()
{
    return wifiDevice.ScanForAccessPoints();
}

/**
 * @brief Connect to provided access point
 * @param accessPoint Access point name
 */
void WifiControl::ConnectToAccessPoint(std::string &accessPoint)
{
    std::vector<std::string> deviceList = networkManager.GetDevices();
    WifiDevice device( FindWifiDevice( deviceList ) );
    device.connect( accessPoint );
}

/**
 * @brief Disconnect from current connected access point
 */
void WifiControl::Disconnect()
{
    std::vector<std::string> deviceList = networkManager.GetDevices();
    WifiDevice device( FindWifiDevice( deviceList ) );
    device.disconnect();
}
} // namespace ABC
