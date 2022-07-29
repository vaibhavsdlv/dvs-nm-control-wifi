#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <vector>
#include <string>
#include <QDBusConnection>


namespace ABC {

enum NMReloadFlag
{
    RELOAD_EVERYTHING = 0,
    RELOAD_CONF = 1,
    UPDATE_DNS = 2,
    RESTART_DNS = 4,
} ;

class NetworkManager
{
public:
    NetworkManager();
    std::vector< std::string > GetDevices();
    void Reload( NMReloadFlag flag );

};
} // namespace ABC

#endif // NETWORKMANAGER_H
