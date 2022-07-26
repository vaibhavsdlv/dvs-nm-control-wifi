#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <vector>
#include <string>
#include <QDBusConnection>


namespace ABC {

class NetworkManager
{

public:
    NetworkManager();
    std::vector< std::string > GetDevices();

};
} // namespace ABC

#endif // NETWORKMANAGER_H
