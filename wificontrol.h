#ifndef WIFICONTROL_H
#define WIFICONTROL_H

#include "networkmanager.h"
#include "wifidevice.h"

#include <vector>
#include <string>
#include <memory>
#include <QDBusConnection>

namespace ABC {

class WifiControl
{
public:
    WifiControl();

    void StartWifi();
    void StopWifi();

    std::vector< std::string > GetAllAccessPoints();

    void ConnectToAccessPoint( std::string& accessPoint );
    void Disconnect();

private:
    NetworkManager networkManager;
    WifiDevice wifiDevice;

};
} // namespace ABC

#endif // WIFICONTROL_H
