#ifndef WIFIDEVICE_H
#define WIFIDEVICE_H

#include <string>
#include <vector>

namespace ABC {

class WifiDevice
{
public:
    WifiDevice( std::string _devicePath );
    std::vector< std::string > ScanForAccessPoints();
    void connect( std::string& accessPoint );
    void disconnect();


private:
    std::string devicePath;
};
}

#endif // WIFIDEVICE_H
